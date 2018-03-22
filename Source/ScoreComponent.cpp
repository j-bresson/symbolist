#include "ScoreComponent.h"
#include "SymbolistMainComponent.h"
#include "SymbolGroupComponent.h"
#include "StaffComponent.hpp"

ScoreComponent::ScoreComponent()
{
    addChildComponent( sel_resize_box = new EditSelectionBox(&selected_components) );
    sel_resize_box->setBorderThickness( BorderSize<int>(6) );
    sel_resize_box->setAlwaysOnTop(true);
    sel_resize_box->setVisible(false);
}

ScoreComponent::~ScoreComponent()
{
    unselectAllComponents();
    clearAllSubcomponents();
}


/**************/
/* Selection  */
/**************/

void ScoreComponent::addToSelection(SymbolistComponent *c)
{
    if( selected_components.addIfNotAlreadyThere(c) )
    {
        c->selectComponent();
        sel_resize_box->updateEditSelBox();
    }
}

void ScoreComponent::removeFromSelection(SymbolistComponent *c)
{
    c->deselectComponent();
    selected_components.removeAllInstancesOf(c);
    sel_resize_box->updateEditSelBox();
}

void ScoreComponent::selectAllComponents()
{
    for (int i = 0 ; i < getNumSubcomponents(); i++ )
    {
        addToSelection(getSubcomponent(i));
    }
}

void ScoreComponent::unselectAllComponents()
{
    for (int i = 0 ; i < getNumSubcomponents(); i++ )
    {
        SymbolistComponent *c = getSubcomponent(i);
        c->deselectComponent();
        selected_components.removeAllInstancesOf(c);
    }
    sel_resize_box->updateEditSelBox();

}


// redefinitions from SymbolComponents
void ScoreComponent::removeSubcomponent( SymbolistComponent *c )
{
    removeFromSelection(c);
    SymbolistComponent::removeSubcomponent( c );
}

void ScoreComponent::clearAllSubcomponents()
{
    SymbolistComponent::clearAllSubcomponents();
    selected_components.clear();
}



void ScoreComponent::reportModificationForSelectedSymbols()
{
    // cout << "void ScoreComponent::reportModificationForSelectedSymbols()" << endl;
    BaseComponent* baseComponent;
    
    for( SymbolistComponent *symbolistComponent : selected_components )
    {
        baseComponent = dynamic_cast<BaseComponent*>(symbolistComponent);
        
        // Checks downcast result.
        if (baseComponent != NULL)
            baseComponent->reportModification();
    }
}

void ScoreComponent::selectedToFront()
{
    for( SymbolistComponent *c : selected_components )
    {
        c->toFront(true);
    }
}

void ScoreComponent::selectedToBack()
{
    for( SymbolistComponent *c : selected_components )
    {
        c->toBack();
    }
}

/*****************
 * Custom lasso tool
 *****************/

void ScoreComponent::beginLassoSelection(Point<int> position)
{
    unselectAllComponents();
    addAndMakeVisible(s_lasso);
    s_lasso.begin(position.getX(), position.getY());
}

void ScoreComponent::dragLassoSelection(Point<int> position)
{
    s_lasso.update( position.getX(), position.getY() );

    // this slows things down noticably where there are a lot of objects selected
    unselectAllComponents();
    
    for (int i = 0; i < getNumSubcomponents(); ++i)
    {
        SymbolistComponent* cc = getSubcomponent(i);
    
        if (!cc->componentSelected() && cc->intersectRect( s_lasso.getBounds() ))
        {
            addToSelection( cc );
        }
    }
}

void ScoreComponent::endLassoSelection()
{
    removeChildComponent(&s_lasso);
    s_lasso.end();
}

void SymbolistLasso::begin(int x, int y)
{
    start_x = x;
    start_y = y;
    setBounds(x, y, 0, 0);
}

void SymbolistLasso::update(int x, int y)
{
    int x1, x2, y1, y2;
    
    if (x > start_x)
    {
        x1 = start_x;
        x2 = x;
    } else {
        x1 = x;
        x2 = start_x;
    }
    
    if (y > start_y)
    {
        y1 = start_y;
        y2 = y;
    } else {
        y1 = y;
        y2 = start_y;
    }
    
    setBounds(x1, y1, x2-x1, y2-y1);
}

void SymbolistLasso::end() {}


void SymbolistLasso::paint ( Graphics &g)
{
    g.setColour(Colours::cornflowerblue);
    g.drawRect(0, 0, getWidth(), getHeight());
}


/**************************
 * User actions
 **************************/

void ScoreComponent::deleteSelectedComponents()
{
    vector< SymbolistComponent *> items;
    
    for( SymbolistComponent *c : selected_components ) // there's probably a better way to copy a vector's contents :)
    {
        std::cout << c << std::endl;
        items.push_back(c);
    }
    
    //selected_items.deselectAll();
    unselectAllComponents();
    
    for( SymbolistComponent *c : items )
    {
        //ScoreComponent* parent = (ScoreComponent*) c->getParentComponent() ; // the selected_items are not necesarily direct children
        //parent->
        removeSubcomponent( c );
        delete c;
    }
}

void ScoreComponent::createStaffFromSelected()
{
    auto page_comp = getPageComponent();

    bool creating_a_top_level_group = ( this == page_comp );
    
    if( !creating_a_top_level_group )
    {
        cout << "must be top level to create staff " << endl;
        return;
    }
    
    
    auto sel = page_comp->getSelectedItems();
    if( sel.size() > 1 )
    {
        page_comp->groupSelectedSymbols();
    }
    
    
    auto staff_ref_comp = dynamic_cast<BaseComponent*>(page_comp->getSelectedItems().getFirst());
    
    // Checks downcast result.
    if( staff_ref_comp != NULL )
    {
        if( staff_ref_comp->getSymbolTypeStr() == "staff" )
            return;
        
        Symbol ref_sym = *(staff_ref_comp->getScoreSymbolPointer());
        
        Symbol* staff_sym = new Symbol("staff", staff_ref_comp->getX(), staff_ref_comp->getY(), staff_ref_comp->getWidth(), staff_ref_comp->getHeight() );
        
        auto sh = getSymbolistHandler();
        
        // create the new component and attach the new symbol pointer to it
        StaffComponent *staff_comp = (StaffComponent *)sh->makeComponentFromSymbol( staff_sym, true );

        // remove from parent (which also sets the ref_sym to null)
        // the parent is not necessarily 'this' (selected_items can be indirect children...)
        ScoreComponent* parentOfStaffRefComponent = dynamic_cast<ScoreComponent*>(staff_ref_comp->getParentComponent());
        
        // Checks downcast result.
        if (parentOfStaffRefComponent != NULL)
            parentOfStaffRefComponent->removeSubcomponent( staff_ref_comp );
        
        // sets the position now relative to the group
        staff_ref_comp->setBounds( 0, 0, staff_ref_comp->getWidth(), staff_ref_comp->getHeight() );
        
        // add subcomponent to the parent staff component
        staff_comp->addSubcomponent( staff_ref_comp );
        
        // once the subcomponent is in place, the attached staff symbol can be updated
        // note: add symbol messages does not attache the symbol, it just adds the messages
        staff_comp->addSymbolMessages( staff_sym , String("") );
        
        addSubcomponent(staff_comp);
        addToSelection(staff_comp);
        
    }
    
}

void ScoreComponent::groupSelectedSymbols()
{
    bool creating_a_top_level_group = ( this == getPageComponent() );
    
    if ( selected_components.size() > 1 )
    {
        // get the position an bounds of the group
        int minx = getWidth(), maxx = 0, miny = getHeight(), maxy = 0;
        for( auto it = selected_components.begin(); it != selected_components.end(); it++ )
        {
            Rectangle<int> compBounds = (*it)->getBounds();
            minx =  min( minx, compBounds.getX() );
            miny =  min( miny, compBounds.getY() );
            maxx =  max( maxx, compBounds.getRight() );
            maxy =  max( maxy, compBounds.getBottom() );
        }
        
        // create a list from selected items
        vector< SymbolistComponent *> items;
        
        for( SymbolistComponent *c : selected_components )
        {
            items.push_back(c);
        }
        unselectAllComponents();
        
        Symbol* s = new Symbol("group", minx, miny, maxx-minx, maxy-miny);
        auto sh = getSymbolistHandler();
        SymbolGroupComponent *group = (SymbolGroupComponent*)sh->makeComponentFromSymbol( s , creating_a_top_level_group );
                
        Rectangle<int> groupBounds( minx, miny, maxx-minx, maxy-miny );
        
        for ( auto it = items.begin(); it != items.end(); it++ )
        {
            SymbolistComponent *c = *it ;
            
            // if this component is of type BaseComponent, remove it's time points if they exist
            try
            {
                BaseComponent* baseComponent = dynamic_cast<BaseComponent*>(c);
                
                // Checks downcast result.
                if( baseComponent != NULL )
                {
                    auto sym = baseComponent->getScoreSymbolPointer();
                    if( sym )  // this fails within groups becuase subcomponents do not have score symbols...
                    {
                        sh->removeTimePointsForSymbol( sym );
                    }
                    
                }
            }
            catch(errc)
            {
                cout << "error: cannot group non-BaseComponent types";
                return;
            }

            // sets the position now relative to the group
            Rectangle<int> compBounds = c->getBounds();
            
            c->setBounds(compBounds.getX() - groupBounds.getX(),
                         compBounds.getY() - groupBounds.getY(),
                         compBounds.getWidth(), compBounds.getHeight());
            
            // the parent is not necessarily 'this' (selected_items can be indirect children...)
            ScoreComponent* parentComponent = dynamic_cast<ScoreComponent*>(c->getParentComponent());
            
            // Checks downcast result.
            if (parentComponent != NULL)
                parentComponent->removeSubcomponent( c );
            
            group->addSubcomponent( c );
        }
        
        if ( creating_a_top_level_group )
        {
            group->addSymbolMessages( s , String("") );
        }
        else
        {
            delete s;
        }
        addSubcomponent( group );
        addToSelection( group );
        
//        cout << "group bundle post: " << endl;
//        group->getScoreSymbolPointer()->printBundle();
    }
}


void ScoreComponent::ungroupSelectedSymbols()
{
    vector<SymbolistComponent*> items;
    for( SymbolistComponent *c : selected_components ) {
        items.push_back(c);
    }
    unselectAllComponents();
    
    for ( int i = 0; i < items.size(); i++ )
    {
        BaseComponent* c = dynamic_cast<BaseComponent*>(items[i]);
        
        // Checks downcast result.
        if (c != NULL)
        {
            int n = ((int)c->getNumSubcomponents());
            
            vector< SymbolistComponent *> subitems;
            for ( int ii = 0 ; ii < n ; ii++ ) { subitems.push_back(c->getSubcomponent(ii)); }
            
            for ( int ii = 0; ii < n ; ii++ )
            {
                BaseComponent* sc = dynamic_cast<BaseComponent*>(subitems[ii]);
                
                // Checks downcast result.
                if (sc != NULL)
                {
                    c->removeSubcomponent(sc);
                    if ( c->isTopLevelComponent() ) sc->createAndAttachSymbol() ;
                    addSubcomponent(sc);
                    sc->setTopLeftPosition(sc->getPosition().translated(c->getPosition().getX(), c->getPosition().getY()));
                }
        
            }
            
            removeSubcomponent(c);
        }
        
    }
}


void ScoreComponent::translateSelectedComponents( Point<int> delta_xy )
{
    for ( auto c : selected_components )
    {
        c->setTopLeftPosition( c->getPosition() + delta_xy );
    }
    sel_resize_box->updateEditSelBox();
}

Rectangle<int> ScoreComponent::getSelectionBounds()
{
    return sel_resize_box->getSelectionBounds();
}


void ScoreComponent::flipSelectedSymbols( int axis )
{
    sel_resize_box->flipSelectedSymbols( axis );
}

void ScoreComponent::nudgeSelected(int direction)
{
    switch(direction)
    {
        case 0:
            translateSelectedComponents( Point<int>(-1,0) );
            break;
        case 1:
            translateSelectedComponents( Point<int>(1,0) );
            break;
        case 2:
            translateSelectedComponents( Point<int>(0,-1) );
            break;
        case 3:
            translateSelectedComponents( Point<int>(0,1) );
            break;
    }
}

void ScoreComponent::addSelectedSymbolsToPalette( )
{
    for ( int i = 0; i < selected_components.size(); i++ )
    {
        BaseComponent* c = dynamic_cast<BaseComponent*>(selected_components[i]);
        
        // Checks downcast result.
        if (c != NULL)
        {
            Symbol* s = new Symbol();
            c->addSymbolMessages(s, "");
            getSymbolistHandler()->getSymbolPalette()->addUserItem(s);
        }
        
    }
    getMainComponent()->updatePaletteView();
}


/***************************/
/* UI callbacks from Juce  */
/***************************/

void ScoreComponent::mouseAddClick ( const MouseEvent& event )
{

    unselectAllComponents();

    BaseComponent *c;
    
    bool top_level = ( this == getPageComponent() );
    
    auto sh = getSymbolistHandler();

    if ( getMainDrawMode() == UI_DrawType::from_template )
    {

        Symbol* symbol_template = getSymbolistHandler()->getCurrentSymbol();
        
        /* creates a new symbol with the same settings as the symbol_template
         * template symbols all have a default type of "path" and bounds of 0,0,30,30
         * the generic symbol has the same OSC data as the BaseComponent
         */
        Symbol* s = new Symbol( *symbol_template );
        
        // sets default position before creating the graphic component
        s->setPosition ( event.position );
        
        // create a new component of the current selected symbol type
        c = sh->makeComponentFromSymbol( s, top_level );
        
        // add component in the view
        addSubcomponent( c );
    }
    else
    {
        Symbol* s = new Symbol("path", event.position.x, event.position.y, 40.0, 40.0) ;
        c = sh->makeComponentFromSymbol( s , top_level );
        addSubcomponent( c );
        getPageComponent()->enterEditMode(c);
        c->mouseAddClick( event.getEventRelativeTo(c) );
    }

    if ( ! top_level )
        c->reportModification();
    
    // deselect other items and select this one
    //addToSelection( c );
}



void ScoreComponent::mouseDown ( const MouseEvent& event )
{
    UI_EditType ed = getMainMouseMode();
    if( ed == selection )
    {
        beginLassoSelection( event.getPosition() );
    }
    else if( ed == draw )
    {
        mouseAddClick( event.getEventRelativeTo(getPageComponent()) );
    }
}

void ScoreComponent::mouseDrag ( const MouseEvent& event )
{
    if( getMainMouseMode() == selection )
    {
        dragLassoSelection(event.getPosition());
    }
}

void ScoreComponent::mouseUp ( const MouseEvent& event )
{
    UI_EditType ed = getMainMouseMode();
    
    if( ed == selection )
    {
        endLassoSelection();
    }
    else if( ed == draw )
    {
        // when the mousedown on this triggered an entry to edit mode, we might want to pass the mouse up there, too
        ScoreComponent* sc = getPageComponent()->getEditedComponent();
        if ( sc != this )
            sc->mouseUp(event.getEventRelativeTo( sc ));
    }
}




