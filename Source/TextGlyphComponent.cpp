
#include "TextGlyphComponent.h"
#include "SymbolistMainComponent.h"

void TextEditorObjListener::textEditorTextChanged (TextEditor& t)
{
    owner->updateText( t.getText() );
}


void EditableTextObjListener::labelTextChanged (Label* l)
{
    owner->updateText( l->getText() );
}

void EditableTextObjListener::editorShown (Label* l, TextEditor& t)
{
    owner->setEditMode( true );
    t.addListener( editlistener );
    t.setBorder( l->getBorderSize() );
    t.setFont(  l->getFont() );
    
    t.setColour( TextEditor::shadowColourId, Colours::transparentWhite );
    t.setColour( TextEditor::focusedOutlineColourId, Colours::transparentWhite );
    t.setIndents(0, 4);
    //t.setMultiLine(true);
    // maybe use subtracted from...
    // const Rectangle<int> centreArea (border.subtractedFrom (fullSize));

//    f.getStringWidth( l->getText() );
    
    // t.setBounds( owner->getLocalBounds().translated(1, 0) );
    //owner->setBounds( owner->getBounds().expanded(2) );
}

void EditableTextObjListener::editorHidden (Label* l, TextEditor& t)
{
    //owner->setBounds( owner->getBounds().expanded(2) );
    owner->setEditMode( false );

}


EditableTextObj::EditableTextObj(BaseComponent *c) : Label( String(), String() ), owner(c)
{
    setEditable (false, true, false);
    //setJustificationType (Justification::centredLeft);
    setBorderSize( BorderSize<int>(0,0,0,0) );
    setColour( Label::backgroundColourId, Colours::transparentWhite );
    setMinimumHorizontalScale(1.0f);
    
    listener = new EditableTextObjListener( (TextGlphComponent*)c );
    addListener(listener);
    
}
    
void EditableTextObj::paint (Graphics& g)
{
    owner->paint(g);
    setColour( Label::textColourId, owner->getCurrentColor() );
    Label::paint(g);
}

void EditableTextObj::mouseMove( const MouseEvent& event )
{
    owner->mouseMove(event);
    Label::mouseMove(event);
}

void EditableTextObj::mouseDown( const MouseEvent& event )
{
    owner->mouseDown(event);
    Label::mouseDown(event);
}

void EditableTextObj::mouseDrag( const MouseEvent& event )
{
    owner->mouseDrag(event);
    Label::mouseDrag(event);
    
}

void EditableTextObj::mouseUp( const MouseEvent& event )
{
    owner->mouseUp(event);
    Label::mouseUp(event);
    
}

//==========================================================================================

TextGlphComponent::TextGlphComponent()
{
    textobj = new EditableTextObj(this);
    textobj->setText (m_text, sendNotificationSync );
    textobj->setColour( Label::textColourId, getCurrentColor() );
    addAndMakeVisible(textobj);
}
    
TextGlphComponent::~TextGlphComponent(){
    cout << "deleting text " <<  this << endl;
};

void TextGlphComponent::setBoundsFromSymbol( float x, float y , float w , float h)
{
    //setBounds( x, y - (h * 0.5), w , h);
    m_font.setHeight( h );
    textobj->setFont( m_font );
    setBounds( x, y - (h * 0.5), m_font.getStringWidth(m_text) + m_width_offset, h );
    textobj->setBounds( getLocalBounds().translated(m_x_offset, 0) );
}

Rectangle<float> TextGlphComponent::symbol_export_bounds()
{
    auto b = getBounds().toFloat();
    return Rectangle<float>( b.getX(), b.getY() + b.getHeight()/2.0f, b.getWidth(), b.getHeight() );
}

void TextGlphComponent::importFromSymbol( const Symbol& s )
{
    BaseComponent::importFromSymbol(s);
    
    int pos = s.getOSCMessagePos("/text");
    if( pos != -1 )
    {
        m_text = s.getOSCMessageValue(pos).getString();
    }
    
    pos = s.getOSCMessagePos("/font");
    if( pos != -1 )
    {
        m_font = Font::fromString( s.getOSCMessageValue(pos).getString() );
    }

    pos = s.getOSCMessagePos("/kerning");
    if( pos != -1 )
    {
        m_extrakerning = Symbol::getOSCValueAsFloat( s.getOSCMessageValue(pos) );
    }

    pos = s.getOSCMessagePos("/h_scale");
    if( pos != -1 )
    {
        m_horz_scale = Symbol::getOSCValueAsFloat( s.getOSCMessageValue(pos) );
    }
    
    m_font = m_font.withExtraKerningFactor( m_extrakerning ).withHorizontalScale( m_horz_scale );
    
    textobj->setFont( m_font );
    textobj->setText( m_text, sendNotificationSync );
    
    setBounds(getX(), getY(), m_font.getStringWidth(m_text) + m_width_offset, m_font.getHeight() );
    textobj->setBounds( getLocalBounds().translated(m_x_offset, 0) );

}

int TextGlphComponent::addSymbolMessages( Symbol* s, const String &base_address )
{
    int messages_added = BaseComponent::addSymbolMessages( s, base_address );
    
    auto b = symbol_export_bounds();
    
    String addr;
    
    addr = base_address + "/text";
    if( s->getOSCMessagePos(addr) == -1 )
    {
        s->addOSCMessage( addr, m_text );
        messages_added++;
    }

    addr = base_address + "/font";
    if( s->getOSCMessagePos(addr) == -1 )
    {
        s->addOSCMessage( addr, m_font.toString() );
        messages_added++;
    }
    
    addr = base_address + "/kerning";
    if( s->getOSCMessagePos(addr) == -1 )
    {
        s->addOSCMessage( addr, m_extrakerning );
        messages_added++;
    }

    addr = base_address + "/h_scale";
    if( s->getOSCMessagePos(addr) == -1 )
    {
        s->addOSCMessage( addr, m_horz_scale );
        messages_added++;
    }
    
    return messages_added;
}


//void TextGlphComponent::resized()
//{
//    BaseComponent::resized();

    /*
    int h = getHeight();
    
    m_font.setHeight( h );
    textobj->setFont( m_font );

    setBounds(getX(), getY(), m_font.getStringWidth(m_text) + m_width_offset, h );
    textobj->setBounds( getLocalBounds().translated(m_x_offset, 0) );
    */
//}

void TextGlphComponent::setWidthInPixels(float w)
{
    float current_w = m_font.getStringWidthFloat(m_text);
    if( current_w > 0 )
    {
        float dst_scale = w / current_w;
        float current_scale = m_font.getHorizontalScale();
        
        if( current_scale > 0 )
        {
            m_font.setHorizontalScale( dst_scale / current_scale );
        }
    }
    
}
/*
void TextGlphComponent::resizeToFit(int x, int y, int w, int h)
{
    if( w > 0 && h > 0)
    {
        m_font.setHeight( h );
        setWidthInPixels( w );
        
        textobj->setFont( m_font );
        setBounds(x, y, m_font.getStringWidth(m_text), h );
        textobj->setBounds( getLocalBounds().translated(0, 0) );
    }
}
*/

void TextGlphComponent::scaleScoreComponent(float scale_w, float scale_h)
{
    float newHeight = scale_h * getHeight();
    m_font.setHeightWithoutChangingWidth( newHeight );
    
    float current_w = m_font.getStringWidthFloat(m_text);
    if( current_w > 0 )
    {
        float current_scale = m_font.getHorizontalScale();
        
        if( current_scale > 0 )
        {
            m_font.setHorizontalScale( current_scale * scale_w );
        }
    }
    
    textobj->setFont( m_font );
    setSize( m_font.getStringWidth(m_text), newHeight );
    textobj->setBounds( getLocalBounds().translated(0, 0) );
}


void TextGlphComponent::updateText( String str)
{
    if( m_text != str )
    {
        m_text = str;
        if( !in_edit_mode )
            textobj->setText (m_text, sendNotificationAsync );
        
        setSize(m_font.getStringWidth(m_text), getHeight() );
        textobj->setBounds( getLocalBounds().translated(m_x_offset, 0) );
    }
}

