#pragma once

#ifndef SymbolistMainComponent_h
#define SymbolistMainComponent_h

#include "../JuceLibraryCode/JuceHeader.h"

#include "SymbolistHandler.h"
#include "PageComponent.h"
#include "PaletteComponent.h"
#include "BaseComponent.h"

#include "PropertyPanelTabs.h"
#include "MouseModeComponent.hpp"
#include "TimeDisplay.hpp"

#include "SymbolistMenu.hpp"
#include "SymbolistLookAndFeel.hpp"
#include "View.hpp"

/**
 * SymbolistMainComponent is the main graphic component of the application.
 *
 */
class SymbolistMainComponent : public virtual SymbolistComponent,
                               public virtual ApplicationCommandTarget,
                               public virtual View<SymbolistModel, SymbolistHandler> {
	
public:
    
    /**************************************************
     *        CONSTRUCTORS AND FACTORY FUNCTIONS      *
     **************************************************/
    SymbolistMainComponent(SymbolistHandler* mainController);
    ~SymbolistMainComponent();

    /*************************************
     *        GETTERS AND SETTERS        *
     *************************************/
    inline ScopedPointer<PropertyPanelTabs> getInspector()
    {
        return inspector;
    }
    inline PaletteComponent* getPaletteView() { return &palette_view; }
    inline PageComponent*    getScoreView() { return &score_view; }
	void setMouseMode(UI_EditType m);
    UI_EditType getMouseMode();
    void setDrawMode(UI_DrawType m);
    UI_DrawType getDrawMode();
    
    // Redefine these from SymbolistComponent
    inline PageComponent* getPageComponent() override
    {
        return dynamic_cast<PageComponent*>(score_viewport.getViewedComponent());
    }
    inline SymbolistHandler* getSymbolistHandler() override {
        return getController();
    }
    inline Viewport* getViewer() { return &score_viewport; }
	inline ModifierKeys* getCurrentMods(){ return &current_mods; }

    /**************************************
     *        PALETTE VIEW METHODS        *
     **************************************/
    void updatePaletteView();
    void addSelectedSymbolsToPalette();
    
	/**************************************
     *        SCORE VIEW METHODS          *
     **************************************/
     
     /**
      * Calls groupSelectedSymbols on the currently edited component in
      * the score view.
      * The currently edited component could be the score view itself or
      * a lower level graphic components (for instance if one is grouping
      * sysmbols within a symbol group).
      */
    void groupSelectedSymbols();
    
     /**
      * Calls ungroupSelectedSymbols on the currently edited component in
      * the score view.
      * The currently edited component could be the score view itself or
      * a lower level graphic components (for instance if one is grouping
      * sysmbols within a symbol group).
      */
    void ungroupSelectedSymbols();
	Rectangle<float> getViewRect();
    Rectangle<float> getZoomedRect();
    
	/***************************************
     *        INSPECTOR VIEW METHODS       *
     ***************************************/
    void toggleInspector();
    inline void clearInspector(){ inspector->clearInspector(); }
    inline void setInspectorObject( BaseComponent *c ){ inspector->setInspectorObject( c ); }
    
    // Redefinition of methods from Juce::Component
    void resized() override;
    void zoom( float delta );
    
    void modifierKeysChanged (const ModifierKeys& modifiers) override;
    

    void setTimePoint( float t )
    {
        getPageComponent()->setTimePoint(t);
        time_display_view.setTime(t);
    }
    
    void toggleTimeAndCursorDisplay()
    {
        time_display_view.toggleView();
        getPageComponent()->toggleCursorDisplay();
    }
    
    /***********************************************************************************
     * APPLICATION KEYBOARD COMMAND WRAPPER (ACTUAL COMMANDS ARE SET IN SymbolistMenu) *
     ***********************************************************************************/
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    
    /* Overrides the update method inherited from the Observer class. */
    inline void update() override { repaint(); }

private:
	
    /*******************************************************
     *                 CHILD COMPONENTS                    *
     *******************************************************/
	
    /**
     * A graphic component which surrounds the PageComponent
     * with scrollbars.
     */
    Viewport                         score_viewport;
	
    /**
     * A graphic component representing the score.
     */
    PageComponent                    score_view;
	
    /**
     * A graphic component representing the palette.
     */
    PaletteComponent                 palette_view;
	
    /**
     * A graphic component for the application's menu.
     * All commands to interact with the symbolist application
     * are referenced here.
     */
    SymbolistMenu                    menu;
    ScopedPointer<PropertyPanelTabs> inspector;
    MouseModeComponent               mouse_mode_view;
    TimeDisplayComponent             time_display_view;
	
	/***************************************************
     *             MISC GRAPHIC PROPERTIES             *
     ***************************************************/
    SymbolistLookAndFeel look_and_feel;
     
    int palette_w = 50;
    int menu_h; // set internally
	
    float            m_zoom = 1.0f;
    ModifierKeys     current_mods;
	
    UI_EditType      mouse_mode = SELECTION;
    UI_DrawType      draw_mode = FREE_DRAW;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SymbolistMainComponent)
};

#endif
