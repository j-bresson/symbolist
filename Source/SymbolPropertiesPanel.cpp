#include "SymbolPropertiesPanel.h"
#include "OSCPropertyComponents.h"
#include "InspectorComponent.h"

SymbolPropertiesPanel::SymbolPropertiesPanel()
{
    setOpaque (false);
    addAndMakeVisible (symbol_inspector);
	
	add_property_button.setButtonText("Add property");
	add_property_button.addListener(this);
	addAndMakeVisible(add_property_button);
	
	evaluate_bundle_button.setButtonText("Evaluate bundle");
	evaluate_bundle_button.addListener(this);
	addAndMakeVisible(evaluate_bundle_button);
	
    change_callback_fn = std::bind( &SymbolPropertiesPanel::change_callback, this, std::placeholders::_1);
    
    getLookAndFeel().setColour( PropertyComponent::backgroundColourId, Colours::transparentWhite );
    getLookAndFeel().setColour( PropertyComponent::labelTextColourId, Colours::black );
    
    getLookAndFeel().setColour(Label::textWhenEditingColourId, Colours::black  );
    getLookAndFeel().setColour(Label::backgroundWhenEditingColourId, Colours::transparentWhite  );
}

SymbolPropertiesPanel::~SymbolPropertiesPanel()
{
	add_property_button.removeListener(this);
}

float SymbolPropertiesPanel::getPreferedHeight()
{
	int buttonAndFormTotalHeight = 60;
	return title_offset + symbol_inspector.getTotalContentHeight() + buttonAndFormTotalHeight;
}

void SymbolPropertiesPanel::change_callback(const OdotMessage& msg)
{
    Symbol* s = symbol_component->getScoreSymbol();
	
    if (s != NULL)
    {
    	s->addMessage( msg ); // this overwrites any duplicate messages
		InspectorComponent* inspectorView = dynamic_cast<InspectorComponent* >(getParentComponent());
		
    	inspectorView->updateSymbolFromComponent( symbol_component );
    }
    // DEBUG_INLINE("******************** updated bundle from inspector ********** " << endl)
    
}

void SymbolPropertiesPanel::buttonClicked(Button* button)
{
	if (button == &add_property_button)
	{
		if (add_property_form.isVisible())
			add_property_form.setVisible(false);
		else
			addAndMakeVisible(add_property_form);
	
		resized();
	}
	else if (button == &evaluate_bundle_button)
	{
		Symbol* inspectedSymbol = symbol_component->getScoreSymbol();
		
		if (inspectedSymbol != NULL)
		{
			for (OdotMessage symbolMessage : inspectedSymbol->getMessageArray())
			{
				if (symbolMessage.getString().find("=") != string::npos)
					inspectedSymbol->applyExpr(symbolMessage.getString());
				
			}
			
		}
		
		symbol_inspector.clear();
		createOSCview();
		
	}
	else throw logic_error("Click on an unknown button.");
	
	DEBUG_FULL("Add property button clicked." << endl)
}

void SymbolPropertiesPanel::createOSCview ()
{
    properties.clear();

    if ( symbol_component )
    {
        Symbol* symbol = symbol_component->getScoreSymbol();
        // DEBUG_FULL("Retrieving pointer from component" << endl)
        // s->print();
        
        if( !symbol )
            return;
        
        if ( !symbol->size() )  return;

        for ( auto msg : symbol->getMessageArray() )
        {
            const string& addr = msg.getAddress();
			
			
            // skipping subbundles for now! need to fix this
            
            if( addr == "/color" )  // should have separate selection for stroke color and the other stroke parameters
            {
                properties.add( new OSCColourSelectorButton(addr, msg, change_callback_fn) );
            }
            else if( addr == "/font" )
            {
                properties.add( new OSCFontMenu ( addr, msg, change_callback_fn, Font::findAllTypefaceNames() ) );
            }
            else if( addr == "/staff" )
            {
                if( symbol->getMessage("/type").getString() != "staff" )
                {
                	InspectorComponent* inspectorComponent = dynamic_cast<InspectorComponent*>(getParentComponent());
                	if (inspectorComponent != NULL)
                	{
						StringArray staves = inspectorComponent->getModel()->getScore()->getStaves();
                    	staves.insert(0, String("<none>") );
						
                    	properties.add( new OSCOptionMenu ( addr, msg, change_callback_fn, staves ) );
					}
			
                }
            }
            else if( addr == "/fill" )
            {
                properties.add( new OSCOnOffButton( addr, msg, change_callback_fn) );
            }
            else if( addr == "/type" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
            else if( addr == "/id" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
            else if( addr == "/num_sub_paths" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
            else if( addr == "/length" )
            {
                properties.add( new OSCValueDisplay( addr, msg) );
            }
           /* else if( addr == "lambda" )
            {
                properties.add( new OSCTextProperty( addr, msg, change_callback_fn, true ) );
            }*/
            else if( msg[0].isString() )
            {
                properties.add( new OSCTextProperty( addr, msg, change_callback_fn) );
            }
            else if( msg[0].isFloat() )
            {
                properties.add( new OSCFloatValueSlider( addr, msg, change_callback_fn ) );
            }
            else if( msg[0].isInt() )
            {
                properties.add( new OSCIntValueSlider( addr, msg, change_callback_fn ) );
            }
            // By default, add property of unknown type as a OSCTextProperty
            else
            {
				properties.add( new OSCTextProperty( addr, msg, change_callback_fn) );
			}
        }
    
    }
    
    symbol_inspector.addProperties( properties );
	resized();
}

void SymbolPropertiesPanel::addMessageToInspectedSymbol(String messageAddress, String messageType)
{
	InspectorComponent* parentView = dynamic_cast<InspectorComponent* >(getParentComponent());
	if (parentView != NULL)
	{
		InspectorController* parentViewController = parentView->getController();
		if (parentViewController != NULL)
		{
			Symbol* inspectedSymbol = symbol_component->getScoreSymbol();
			if (inspectedSymbol != NULL)
			{
				parentViewController->addMessageToInspectedSymbol(inspectedSymbol, messageAddress, messageType);
				add_property_form.setVisible(false);
				
				symbol_inspector.clear();
				createOSCview();
			}
			else throw logic_error("The inspected component is not associated with any symbol.");
		}
		else throw logic_error("InspectorComponent has no associated controller");
	}
	else throw logic_error("SymbolPropertiesPanel has no parent of type InspectorComponent");
}

void SymbolPropertiesPanel::setInspectorObject( BaseComponent *c )
{
    symbol_component = c;
    symbol_inspector.clear();
    createOSCview();
	
    if (c == NULL)
    {
    	add_property_form.setVisible(false);
    	add_property_button.setVisible(false);
    	evaluate_bundle_button.setVisible(false);
	}
	else
	{
		add_property_button.setVisible(true);
		evaluate_bundle_button.setVisible(true);
	}
}

void SymbolPropertiesPanel::clearInspector()
{
    if( !symbol_inspector.isEmpty() )
        symbol_inspector.clear();
    
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
    g.drawText("object inspector", 4, 0, getWidth() - 8, title_offset, Justification::left);
	
}

void SymbolPropertiesPanel::resized() 
{
    auto local = getLocalBounds();
    local.removeFromTop(title_offset); // deduces the title height
	
	int symbolInspectorHeight = symbol_inspector.getTotalContentHeight() + 10;
    int symbolInspectorMargin = 4;
	int buttonHeight = 30;
	int buttonMargin = 4;
	
    symbol_inspector.setBounds(local.removeFromTop(symbolInspectorHeight).reduced(symbolInspectorMargin));
	
	if (add_property_form.isVisible())
	{
		add_property_form.setBounds(local.removeFromTop(buttonHeight).reduced(buttonMargin));
	}
	
	add_property_button.setBounds(local.removeFromLeft(getWidth() * 0.5).removeFromTop(buttonHeight).reduced(buttonMargin));
	evaluate_bundle_button.setBounds(local.removeFromLeft(getWidth() * 0.5).removeFromTop(buttonHeight).reduced(buttonMargin));
}

