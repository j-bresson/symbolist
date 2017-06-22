
#pragma once

#include "SymbolistComponent.h"
#include "TimePointArray.h"
#include "SymbolistHandler.h"


class TimePointGUI : public SymbolistComponent
{
public:
    
    void paint( Graphics& g ) override
    {
        auto timepoints = getSymbolistHandler()->getTimePointArray();
        
        for( auto t : (*timepoints) )
        {
            g.drawEllipse( t->time * 100.0f, getHeight() / 2, 10, 10, 1);
        }
        
    }
    
    void resized() override
    {
        auto parent = getParentComponent();
        setBounds(0, parent->getBottom() - 50,  parent->getWidth(), 50 );
    }
    
private:
    
};