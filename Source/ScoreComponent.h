#ifndef ScoreComponent_h
#define ScoreComponent_h

#include "../JuceLibraryCode/JuceHeader.h"
#include "SymbolistComponent.h"
#include "EditSelectionBox.h"

class SymbolistLasso : public Component
{
    
public:
    
    void paint(Graphics &g) override;
    void begin(int x, int y);
    void update(int x, int y);
    void end();
    
private:
    
    float start_x, start_y;
};

/*********************
 * Superclass for score-editable containers : PageComponent or BaseComponent (when in_edit_mode)
 *********************/
class ScoreComponent : public SymbolistComponent {
	
public:
    
    ScoreComponent();
    ~ScoreComponent();
    
    void addToSelection(SymbolistComponent* c);
    void removeFromSelection(SymbolistComponent* c);
    void selectAllComponents();
    virtual void unselectAllComponents();
    Array<SymbolistComponent* >& getSelectedItems(){ return selected_components; }
    void selectedToFront();
    void selectedToBack();
    
    void removeSubcomponent( SymbolistComponent *c ) override;
    void clearAllSubcomponents( ) override;
    
    void reportModificationForSelectedSymbols();
    
    virtual void deleteSelectedComponents();

    void translateSelectedComponents( Point<int> delta_xy );
	
    /* Method about grouping and ungrouping
	 * shouldn't be here because simple components
	 * (which are not a composition of components) don't
	 * care about these methods.
     */
    virtual void groupSelectedSymbols();
    void ungroupSelectedSymbols();
        
    void flipSelectedSymbols( int axis );
    void nudgeSelected( int direction );
        
    void mouseDown ( const MouseEvent& event ) override;
    void mouseDrag ( const MouseEvent& event ) override;
    void mouseUp ( const MouseEvent& event ) override;
    
    virtual void mouseAddClick ( const MouseEvent& event );
    
    Rectangle<int> getSelectionBounds();
	
protected:
	
    Array<SymbolistComponent* > selected_components;
    SymbolistLasso s_lasso;
	
    void beginLassoSelection(Point<int> position);
    void dragLassoSelection(Point<int> position);
    void endLassoSelection();
	
    ScopedPointer<EditSelectionBox > sel_resize_box;

};


#endif
