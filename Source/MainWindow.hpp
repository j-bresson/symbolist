/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"



//==============================================================================
/*
        This class implements the desktop window that contains an instance of
        our MainContentComponent class.    */
class MainWindow    : public DocumentWindow
    {
 
public:
    MainWindow (String name)  : DocumentWindow (name,
                                                Desktop::getInstance().getDefaultLookAndFeel()
                                                                      .findColour (ResizableWindow::backgroundColourId),
                                                DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar (true);
        setContentOwned (new MainContentComponent(), true);

        centreWithSize (getWidth(), getHeight());
        setVisible (true);
    }

    void closeButtonPressed() override
    {
        // This is called when the user tries to close this window. Here, we'll just
        // ask the app to quit when this happens, but you can change this to do
        // whatever you need.
        JUCEApplication::getInstance()->systemRequestedQuit();
    }

    /* Note: Be careful if you override any DocumentWindow methods - the base
       class uses a lot of them, so by overriding you might break its functionality.
       It's best to do all your work in your content component instead, but if
       you really have to override any DocumentWindow methods, make sure your
       subclass also calls the superclass's method.
    */

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};


//==============================================================================
// This macro generates the main() routine that launches the app.
// START_JUCE_APPLICATION (jucemouseeventsApplication)
