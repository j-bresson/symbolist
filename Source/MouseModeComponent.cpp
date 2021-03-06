
#include "MouseModeComponent.hpp"
#include "SymbolistMainComponent.h"


void MouseModeComponent::paint( Graphics &g )
{
    
    g.setFont (Font (16.0f));
    g.setColour (Colours::grey);
    g.drawText (m_str, getLocalBounds() , Justification::centredLeft, false);
    
}

void MouseModeComponent::drawString()
{
    if ( m_edit_type == UI_EditType::SELECTION )
    {
        m_str = " select " ;
    }
    else if ( m_draw_type == UI_DrawType::FROM_TEMPLATE )
    {
        m_str = " draw " ;
		
		SymbolistMainComponent* mainView = dynamic_cast<SymbolistMainComponent*>(getParentComponent());
		Symbol* selectedSymbol = NULL;
		
		if (mainView != NULL)
			selectedSymbol = mainView->getModel()->getPalette()->getSelectedSymbol();
		
		if (selectedSymbol != NULL)
        	m_str += String(selectedSymbol->getType());
		else m_str += "unknown ";
    }
    else
    {
        m_str = " draw lines " ;
    }
    
    repaint();
}

void MouseModeComponent::setMouseMode( UI_EditType t )
{
    m_edit_type = t;
    drawString();
}

void MouseModeComponent::setDrawMode( UI_DrawType t )
{
    m_draw_type = t;
    drawString();
}
