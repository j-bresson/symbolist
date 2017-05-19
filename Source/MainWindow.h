#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "types.h"

#include "MainComponent.h"
#include "ScoreData.h"


/************************************************
 * SHARED BY THE LIBRARY AND THE STANDALONE APP
 ************************************************/

class SymbolistMainWindow : public DocumentWindow {
    
public:

    SymbolistMainWindow ( Score *s );
    SymbolistMainWindow ();
    ~SymbolistMainWindow ();
    
    void registerUpdateCallback(symbolistUpdateCallback c);
    
    Score* getScore() { return score; }
    void setSymbols( Score *s );
    void notifyUpdate();
    
protected:

    MainComponent *comp;
    Score *score;

    symbolistUpdateCallback myUpdateCallback = NULL;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SymbolistMainWindow)

};



/***********************************
 * SPECIFIC FOR THE LIBRARY
 ***********************************/
class SymbolistEditorWindow : public SymbolistMainWindow {
    
public:
    
    SymbolistEditorWindow () : SymbolistMainWindow (new Score()) {} ; // {}
    SymbolistEditorWindow (Score *s)  : SymbolistMainWindow ( s ) {} ;
    ~SymbolistEditorWindow () {};
    
    void closeButtonPressed() override;
    void registerCloseCallback(symbolistCloseCallback c);
    
private:
  
    symbolistCloseCallback myCloseCallback;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SymbolistEditorWindow)
    
};
