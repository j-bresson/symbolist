#pragma once

#include "BaseComponent.h"

class PathHandle;

class PathComponent : public BaseComponent
{
public:
    
    PathComponent(  const Symbol& s ) : BaseComponent( s ) { symbol_type = "path"; }
    
    ~PathComponent()
    {
        printf("freeing path %p\n", this);
        removeHandles();
    }
    
    void printPath( Path p );
    
    int addSymbolMessages(Symbol* s, const String &base_address) override;
    
    void importFromSymbol( const Symbol* s ) override;

    void addHandle( float x, float y );
    void makeHandles();
    void removeHandles();
    void updatePathPoints();
    
    void deselectComponent () override;
    
    void paint ( Graphics& g ) override;

    void mouseDown( const MouseEvent& event ) override;
    void mouseMove( const MouseEvent& event ) override;
    void mouseDrag( const MouseEvent& event ) override;
    void mouseUp( const MouseEvent& event ) override;
    
    bool hitTest (int x, int y) override
    {
        return m_path.intersectsLine( Line<float>( x - 5, y - 5, x + 5, y + 5) ) || m_path.intersectsLine( Line<float>( x + 5, y - 5, x - 5, y + 5) );
    }
    
private:
    
    Point<float>    m_drag;
<<<<<<< Updated upstream
    PathStrokeType  strokeType;
    
    
=======
    PathStrokeType  strokeType = PathStrokeType(2.0);
>>>>>>> Stashed changes
    Path            m_path;
    Path            m_preview_path;

    float           quarter_pi = 0.78539816339745;


    
    std::vector<PathHandle*> path_handles;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PathComponent)
};


class PathHandle : public Component
{
public:
    PathHandle( float x, float y, PathComponent *pc)
    {
        m_path = pc;
        setComponentID("path_handle");
        float halfsize = m_size * 0.5;
        setBounds( x-halfsize, y-halfsize, m_size, m_size);
    }
    
    ~PathHandle()
    {

//        std::cout << "freeing " << getComponentID() << " " << this << "\n";
    }
    
    void paint ( Graphics& g ) override
    {
        g.setColour ( Colours::cornflowerblue );
        const Rectangle<float> bounds = getLocalBounds().toFloat().reduced( m_strokeweight );
        g.drawRect ( bounds, (float) m_strokeweight );
    }
    
    void mouseDown( const MouseEvent& event ) override
    {
        m_down = event.position;
    }
    
    void mouseDrag( const MouseEvent& event ) override
    {
        
        // not sure why I need to make this relative, it was jumping back and forth between being relative to the score and then to the component. is it possibe that it has an extra mouselistener somewhere?
        Point<int> draggy = event.getEventRelativeTo( m_path->getParentComponent() ).getPosition();
        setTopLeftPosition ( draggy - (m_down).toInt() );
        m_path->updatePathPoints();
    }
    void mouseUp( const MouseEvent& event ) override
    {}
    
private:
    
    Point<float>    m_down;

    PathComponent   *m_path;
    float           m_size = 10;
    float           m_strokeweight = 1;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PathHandle)
    
};
