#include "SymbolPropertiesPanel.h"


SymbolPropertiesPanel::SymbolPropertiesPanel(SymbolistHandler *sh )
{
    setOpaque (false);
    addAndMakeVisible (symbol_inspector);
    setSize (200, 600);
    
    symbolist_handler = sh;
    change_callback_fn = std::bind( &SymbolPropertiesPanel::change_callback, this, std::placeholders::_1);
    
    getLookAndFeel().setColour( PropertyComponent::backgroundColourId, Colours::transparentWhite );
    getLookAndFeel().setColour( PropertyComponent::labelTextColourId, Colours::black );
    
    getLookAndFeel().setColour(Label::textWhenEditingColourId, Colours::black  );
    getLookAndFeel().setColour(Label::backgroundWhenEditingColourId, Colours::transparentWhite  );
}

void SymbolPropertiesPanel::change_callback( const OSCMessage& msg)
{
    Symbol *s = symbol_component->getScoreSymbolPointer();
    const OSCBundle *bundle = s->getOSCBundle();
    
    OSCBundle newBundle;
    
    for( auto osc_m_iter : *bundle )
    {
        auto i_msg = osc_m_iter.getMessage();
        if( i_msg.getAddressPattern() == msg.getAddressPattern() )
            newBundle.addElement( msg );
        else
            newBundle.addElement( i_msg );
    }
    
    s->setOSCBundle( &newBundle );
    
    symbolist_handler->updateSymbolFromInspector( symbol_component );
    
    // refresh inspector if object type is changed (to hide /staff if the object is a staff)
    if( msg.getAddressPattern() == "/objectType" )
        setInspectorObject( symbol_component );
    
    //cout << "*********************** updated bundle from inspector ********** " << endl;
    //s->printBundle();
    
}

void SymbolPropertiesPanel::createOSCview ()
{
    properties.clear();

    
    if( symbol_component )
    {
        Symbol *s = symbol_component->getScoreSymbolPointer();
        if( !s ) return;
        
        OSCBundle bndl = *s->getOSCBundle();
        if ( bndl.isEmpty() )  return;

        for( int i = 0; i < bndl.size(); i++ )
        {
            auto msg = bndl[i].getMessage();
            const String& addr = msg.getAddressPattern().toString();
            
            StringArray addr_arr = StringArray::fromTokens(addr, "/", "" );
            addr_arr.removeEmptyStrings();
            
            const String& test_addr = *addr_arr.end();
            
            // cout << test_addr << endl;
            
            if( test_addr == "color" )  // should have separate selection for stroke color and the other stroke parameters
            {
                properties.add( new OSCColourSelectorButton(addr, msg, change_callback_fn) );
            }
            else if( test_addr == "font" )
            {
                properties.add( new OSCFontMenu ( addr, msg, change_callback_fn, Font::findAllTypefaceNames() ) );
            }
            else if( test_addr == "objectType" ) // << this should be something like: /objectType : "staff"
            {
                StringArray choices = {"object", "staff"};
                properties.add( new OSCOptionMenu ( addr, msg, change_callback_fn, choices ) );
            }
            else if( test_addr == "staff" )
            {
                int pos = s->getOSCMessagePos("/objectType");
                if( pos != -1 && s->getOSCMessageValue("/objectType").getString() == "object" )
                {
                    properties.add( new OSCOptionMenu ( addr, msg, change_callback_fn, symbolist_handler->getStaves() ) );
                }
            }
            else if( test_addr == "fill" )
            {
                properties.add( new OSCOnOffButton( addr, msg, change_callback_fn) );
            }
            else if( test_addr == "type" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
            else if( test_addr == "id" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
            else if( test_addr == "num_sub_paths" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
            else if( test_addr == "length" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
            else if( msg[0].isString() )
            {
                properties.add( new OSCTextProperty( addr, msg, change_callback_fn) );
            }
            else if( msg[0].isFloat32() )
            {
                properties.add( new OSCFloatValueSlider( addr, msg, change_callback_fn ) );
            }
            else if( msg[0].isInt32() )
            {
                properties.add( new OSCIntValueSlider( addr, msg, change_callback_fn ) );
            }
        }
    
    }
    symbol_inspector.addProperties( properties );
//    symbol_inspector.addSection("OSC", properties);
}

void SymbolPropertiesPanel::setInspectorObject( BaseComponent *c )
{
    symbol_component = c;
    symbol_inspector.clear();
    createOSCview();
}

void SymbolPropertiesPanel::clearInspector()
{
    if( !symbol_inspector.isEmpty() )
    {
        symbol_inspector.clear();
    }
    
    symbol_component = nullptr;
}

void SymbolPropertiesPanel::paint (Graphics& g)
{
    // background
    g.fillAll ( Colour::fromFloatRGBA(0.95, 0.95, 0.95, 0.7) );
    
    // left separator line
    g.setColour( Colours::lightgrey );
    g.drawLine( 0, 0, 0, getHeight() );
    
    g.fillRect(0, 0, getWidth(), title_offset) ;
    
    g.drawLine( 0, title_offset, getWidth(), title_offset);
    
    // title
    g.setColour( Colours::white );
    auto f = g.getCurrentFont();
    f.setItalic(true);
    g.setFont( f );
    g.drawText("object inspector", 4, 0, getWidth()-8, title_offset, Justification::left);
}

void SymbolPropertiesPanel::resized() 
{
    auto local = getLocalBounds().reduced(4);
    symbol_inspector.setSize(local.getWidth(), local.getHeight() - title_offset);
    symbol_inspector.setTopLeftPosition(local.getX(), local.getY() + title_offset);
}

