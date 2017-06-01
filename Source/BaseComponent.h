
#ifndef BaseComponent_h
#define BaseComponent_h

#include "../JuceLibraryCode/JuceHeader.h"

#include "Symbol.h"
#include "SymbolistComponent.h"

template <typename T>
void printRect( const Rectangle<T> &rect, const String &name = "rect" )
{
    std::cout << name << " " << rect.getX() << " " << rect.getY() << " " << rect.getWidth() << " " << rect.getHeight() << std::endl ;
}


class BaseComponent : public SymbolistComponent
{
public:
    
    BaseComponent();
    //BaseComponent(const BaseComponent& c); // can't get to compile this copy-constructor ???
    BaseComponent( const String &type, const Point<float> &pos );
    ~BaseComponent();
    
    // main operations in score management
    inline void setSymbol(Symbol *s){ score_symbol = s; };
    inline Symbol* getSymbol(){ return score_symbol; };
    inline String getSymbolType(){ return symbol_type ; };
    inline size_t getNumSubcomponents(){ return subcomponents.size() ; };
    inline BaseComponent* getSubcomponent(int i){ return subcomponents.at(i) ; };
    inline void addSubcomponent(BaseComponent *c ){ return subcomponents.emplace_back(c) ; };
    
    
    // Called from the Juce::SelectedItemSet subclass in ScoreComponent
    virtual void selectComponent();
    virtual void deselectComponent();
    
    // callbacks redefinitions from Juce::Component
    void paint ( Graphics& g ) override;
    void moved () override;
    void resized () override;
    
    
    void mouseEnter( const MouseEvent& event ) override;
    void mouseMove( const MouseEvent& event ) override;
    void mouseDown( const MouseEvent& event ) override;
    void mouseDrag( const MouseEvent& event ) override;
    void mouseUp( const MouseEvent& event ) override;

    void mouseExit( const MouseEvent& event ) override;
    void mouseDoubleClick( const MouseEvent& event ) override;
    
    
    // subroutine in derived class, maybe return bool to trigger repaint
    virtual void symbol_paint ( Graphics& g ) { std::cout << "symbol pain" << std::endl; }

    //virtual void symbol_select () {}
    //virtual void symbol_deselect () {}
    
    virtual void symbol_moved () {}
    virtual void symbol_resized () {}
    
    virtual float symbol_getX(){ return getX(); }
    virtual float symbol_getY(){ return getY(); }
    
    
    virtual void symbol_mouseEnter( const MouseEvent& event ){}
    virtual void symbol_mouseMove( const MouseEvent& event ){}
    virtual void symbol_mouseDown( const MouseEvent& event ){}
    virtual void symbol_mouseDrag( const MouseEvent& event ){}
    virtual void symbol_mouseUp( const MouseEvent& event ){}
    virtual void symbol_mouseExit( const MouseEvent& event ){}
    virtual void symbol_mouseDoubleClick( const MouseEvent& event ){}


    
    
    inline void setSymbolStrokeWeight( float s ){ strokeWeight = s; }
    inline void setSymbolColor( Colour c ){ sym_color = c; }
    
    inline void setEditState( bool e ){ is_being_edited = e; }
    
    
protected:
    
    // score structure
    Symbol                          *score_symbol;
    String                          symbol_type = String("symbol");
    std::vector<BaseComponent*>     subcomponents;
    
    // parameters
    float           strokeWeight = 1;
    Colour          sym_color = Colours::black;
    // interaction
    Point<float>    m_down;
    Colour          current_color = Colours::black;

    ScopedPointer<ResizableBorderComponent> resizableBorder;
    
    int             resize_mode = 0; // 0 = scale symbol to bounds, 1 = scale spacing (not resizing)
    
    bool            showBoundingBox = false;
    float           bb_strokeWeight = 1;
    Colour          bb_color = Colours::cornflowerblue;
    Colour          sel_color = Colours::cornflowerblue;
    
    /*
     
     to do: setup selection system:
        if selected and in the score context, 
        if clicked after selected (? or if it's the only selection) 
            then create handles for resizing (if it makes sense for the mode)
        if selected and in the palette context, highlight and set type for drawing
     
     */

    bool        is_being_edited = true;
    bool        is_selected = false;
    
private:
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseComponent)
    
};

#endif

// all parameters that might be used for performance should be stored in the score,
// separate from the graphic component class, if possible, generalize the stored parameter namespace here so that
// all inherited children can read and write their states through this interface
