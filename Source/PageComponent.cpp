//
//  PageComponent.cpp
//  symbolist
//
//  Created by Jean Bresson on 04/06/2017.
//
//

#include "PageComponent.h"
#include "MainComponent.h"


PageComponent::PageComponent()
{
    setComponentID("PageComponent");
    addChildComponent( lassoSelector );
    lassoSelector.setComponentID("lasso");
    getLookAndFeel().setColour( lassoSelector.lassoFillColourId, Colours::transparentWhite );
    getLookAndFeel().setColour( lassoSelector.lassoOutlineColourId, Colour::fromFloatRGBA(0, 0, 0, 0.2) );
}


/***************************************************/
/* MODIFICATIONS TO BE TRANSFERRED TO THE SCORE    */
/* will update the data (score) and notify to host environment */
/***************************************************/

void PageComponent::addSubcomponent( BaseComponent *c )
{
    ScoreComponent::addSubcomponent( c );
    c->addSymbolToScore();
    draw_mode = true;
}


void PageComponent::removeSubcomponent( BaseComponent *c , bool delete_it)
{
    c->removeSymbolFromScore();
    ScoreComponent::removeSubcomponent( c , delete_it );
}


/************************/
/* Draws the score page */
/************************/

void PageComponent::paint (Graphics& g)
{
    g.fillAll ( Colours::white );

    g.setFont (Font (16.0f));
    g.setColour (Colours::grey);
    
    String msg = "";
    
    switch ( getMainEditMode() )
    {
        case edit:
            msg += " select/transform mode" ;
            break;
        case draw:
            msg += " draw mode: " ;
            Symbol *s = static_cast<SymbolistMainComponent*>( getMainComponent() )->getCurrentSymbol();
            msg += s->getOSCMessageValue(s->getOSCMessagePos("/type")).getString();
            break;
    }
    g.drawText (msg, getLocalBounds() , Justification::bottom, false);
}
