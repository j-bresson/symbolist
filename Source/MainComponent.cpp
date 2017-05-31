
#include "MainComponent.h"
#include "MainWindow.h"
#include "ScoreComponent.h"


SymbolistMainComponent::SymbolistMainComponent()
{
    // score = std::unique_ptr<Score>(new Score());
    
    setComponentID("MainComponent");
    setSize (600, 400);
    
    
    
    // create two default items
    OSCBundle b1,b2;
    float symbol_size = 30.0;
    b1.addElement(OSCMessage(OSCAddressPattern("/type"), String("circle")));
    b1.addElement(OSCMessage(OSCAddressPattern("/w"), symbol_size));
    b1.addElement(OSCMessage(OSCAddressPattern("/h"), symbol_size));
    b1.addElement(OSCMessage(OSCAddressPattern("/x"), float(20.0)));
    b1.addElement(OSCMessage(OSCAddressPattern("/y"), float(20.0)));
    
    
    b2.addElement(OSCMessage(OSCAddressPattern("/type"), String("path")));
    b2.addElement(OSCMessage(OSCAddressPattern("/w"), symbol_size));
    b2.addElement(OSCMessage(OSCAddressPattern("/h"), symbol_size));
    
    palette.addPaletteItem(new Symbol(b1));
    palette.addPaletteItem(new Symbol(b2));
    
    paletteView.buildFromPalette(&palette);
    paletteView.selectPaletteButton(0);
    
    addAndMakeVisible(scoreGUI);
    addAndMakeVisible(paletteView);
    
    // the main component will receive key events from the subviews
    paletteView.addKeyListener(this);
    scoreGUI.addKeyListener(this);
    setWantsKeyboardFocus(true);
    addKeyListener(this);
}


SymbolistMainComponent::~SymbolistMainComponent() { }


void SymbolistMainComponent::resized()
{
    scoreGUI.setBounds( 50, 0, getWidth(), getHeight() );
    paletteView.setBounds( 0, 0, 50, getHeight() );
    // printf("main resized\n");
}


void SymbolistMainComponent::setCurrentSymbol(int n)
{
    palette.setSelectedItem(n);
    paletteView.selectPaletteButton(n);
}

int SymbolistMainComponent::getCurrentSymbolIndex()
{
    return palette.getSelectedItem();
}

Symbol* SymbolistMainComponent::getCurrentSymbol()
{
    return palette.getPaletteItem(palette.getSelectedItem());
}

void SymbolistMainComponent::setEditMode( UI_EditType m )
{
    mouse_mode = m;
    scoreGUI.repaint();
}

UI_EditType SymbolistMainComponent::getEditMode()
{
    return mouse_mode ;
}



bool SymbolistMainComponent::keyPressed (const KeyPress& key, Component* originatingComponent)
{
    std::cout << "key " << key.getTextDescription() << "\n";
    String desc = key.getTextDescription();
    if( desc            == "command + G" ) {
        scoreGUI.groupSymbols();
    } else if ( desc    == "backspace" ) {
        scoreGUI.deleteSelectedSymbolComponents();
    } else if ( desc    == "C") {
        setCurrentSymbol(0);
    } else if ( desc    == "P") {
        setCurrentSymbol(1);
    }
    
    return true;
}

void SymbolistMainComponent::modifierKeysChanged (const ModifierKeys& modifiers)
{
    if ( modifiers.isCommandDown() )
    {
        setEditMode( UI_EditType::draw );
    } else {
        setEditMode( UI_EditType::edit );
    }
}





/*********************************************
 * CONTROLLER METHODS CALLED FROM THE LIB API
 *********************************************/

// This is a static method called to create a window
// return the new SymbolistMainComponent within this window
SymbolistMainComponent* SymbolistMainComponent::symbolistAPI_createWindow()
{
    SymbolistEditorWindow *w = new SymbolistEditorWindow ();
    return w->getSymbolistMainComponent();
}

void SymbolistMainComponent::symbolistAPI_closeWindow()
{
    delete this->getTopLevelComponent(); // = the window
    delete this;
}

void SymbolistMainComponent::symbolistAPI_windowToFront()
{
    getTopLevelComponent()->toFront(true);
}

void SymbolistMainComponent::symbolistAPI_windowSetName(String name)
{
    getTopLevelComponent()->setName(name);
}

void SymbolistMainComponent::symbolistAPI_registerUpdateCallback(symbolistUpdateCallback c)
{
    myUpdateCallback = c;
}

void SymbolistMainComponent::symbolistAPI_registerCloseCallback(symbolistCloseCallback c)
{
    myCloseCallback = c;
}

int SymbolistMainComponent::symbolistAPI_getNumSymbols()
{
    return static_cast<int>( getScore()->getSize() );
}

odot_bundle* SymbolistMainComponent::symbolistAPI_getSymbol(int n)
{
    return getScore()->getSymbol(n)->exportToOSC();
}

void SymbolistMainComponent::symbolistAPI_setSymbols(int n, odot_bundle **bundle_array)
{
    // Will lock the MainLoop until out of scope..
    const MessageManagerLock mmLock;
    
    // clear the view
    scoreGUI.removeAllSymbolComponents();
    
    // update score
    getScore()->importScoreFromOSC(n, bundle_array);
    
    // recreate and add components from score symbols
    for (int i = 0; i < score.getSize(); i++) {
        scoreGUI.addScoreChildComponent( makeComponentFromSymbol( score.getSymbol(i) ) ) ;
    }
}

// these two methods shall be called from symbolist to notify the host environment
void SymbolistMainComponent::executeCloseCallback()
{
    if (myCloseCallback) { myCloseCallback( this ); }
}

void SymbolistMainComponent::executeUpdateCallback(int arg)
{
    if (myUpdateCallback) { myUpdateCallback( this, arg ); }
}




//=================================
// INTERFACE DATA<=>VIEW
//=================================

//=================================
// => MODIFY VIEW FROM DATA
//=================================

BaseComponent* SymbolistMainComponent::makeComponentFromSymbol(Symbol* s)
{
    float x = 0.0;
    float y = 0.0;
    float w = 10.0;
    float h = 10.0;
    
    int xMessagePos = s->getOSCMessagePos("/x");
    int yMessagePos = s->getOSCMessagePos("/y");
    int wMessagePos = s->getOSCMessagePos("/w");
    int hMessagePos = s->getOSCMessagePos("/h");
    int typeMessagePos = s->getOSCMessagePos("/type");
    
    if (xMessagePos != -1) x = s->getOSCMessageValue(xMessagePos).getFloat32();
    if (yMessagePos != -1) y = s->getOSCMessageValue(yMessagePos).getFloat32();
    if (wMessagePos != -1) w = s->getOSCMessageValue(wMessagePos).getFloat32();
    if (hMessagePos != -1) h = s->getOSCMessageValue(hMessagePos).getFloat32();
    
    
    if ( typeMessagePos == -1 ) {
        
        return NULL;
        
    } else {
        
        String typeStr = s->getOSCMessageValue(typeMessagePos).getString();
        BaseComponent *c;

        if (typeStr.equalsIgnoreCase(String("circle"))) {
            c = new CircleComponent( x, y, w, h );
        } else if (typeStr.equalsIgnoreCase(String("path"))) {
            c = new PathComponent( Point<float>(x, y) );
        } else {
            c = new BaseComponent(typeStr, Point<float>(x, y) );
        }
        
        c->setSymbol(s);
        //return std::unique_ptr<BaseComponent>(c);
        return c;
    }
}


//=================================
// <= MODIFY DATA FROM VIEW
//=================================

// can be overriden / completed by class-specific messages
int SymbolistMainComponent::addSymbolMessages( BaseComponent *c, OSCBundle *b, String base_address)
{
    int messages_added = 0;
    OSCMessage typeMessage = OSCMessage(OSCAddressPattern( String(base_address) += "/type" ), c->getSymbolType());
    OSCMessage xMessage = OSCMessage(OSCAddressPattern( String(base_address) += "/x"), static_cast<float>(c->symbol_getX()));
    OSCMessage yMessage = OSCMessage(OSCAddressPattern( String(base_address) += "/y"), static_cast<float>(c->symbol_getY()));
    OSCMessage wMessage = OSCMessage(OSCAddressPattern( String(base_address) += "/w"), static_cast<float>(c->getWidth()));
    OSCMessage hMessage = OSCMessage(OSCAddressPattern( String(base_address) += "/h"), static_cast<float>(c->getHeight()));
    b->addElement(typeMessage);
    b->addElement(xMessage);
    b->addElement(yMessage);
    b->addElement(wMessage);
    b->addElement(hMessage);
    messages_added += 5;
    
    for (int i = 0; i < c->getNumSubcomponents(); i++)
    {
        String base = base_address << "/sub_" << String(i) ;
        messages_added += addSymbolMessages( c->getSubcomponent(i), b, base);
    }
    
    return messages_added;
}

void SymbolistMainComponent::updateComponentSymbol( BaseComponent *c )
{
    OSCBundle b;
    addSymbolMessages( c , &b , String("") );
    c->getSymbol()->setOSCBundle(b);
}

/********************************
 * CALLBACKS FROM USER ACTIONS
 ********************************/

void SymbolistMainComponent::handleComponentAdded ( BaseComponent* c )
{
    Symbol *s = new Symbol();
    c->setSymbol( s );
    updateComponentSymbol( c );
    score.addSymbol( s );
    executeUpdateCallback( -1 );
}

void SymbolistMainComponent::handleComponentRemoved ( BaseComponent* c )
{
    score.removeSymbol( c->getSymbol() );
    executeUpdateCallback( -1 );
}

void SymbolistMainComponent::handleComponentModified ( BaseComponent* c )
{
    updateComponentSymbol( c );
    executeUpdateCallback( score.getSymbolPosition( c->getSymbol() ) );
}








