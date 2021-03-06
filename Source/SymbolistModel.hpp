#ifndef SymbolistModel_hpp
#define SymbolistModel_hpp

#include <stdio.h>
#include "Observable.hpp"
#include "Score.h"
#include "Palette.hpp"

using namespace std;

/**
 * Represents the business logic of the symbolist application.
 *
 * The SymbolistModel class references a Score object and a Palette
 * object as instance variables. The score and palette
 * characterize the data layer of the symbolist application.
 *
 * SymbolistModel proposes wrapper methods around methods
 * of the Score and Palette classes which aim at changing the
 * state of the model.
 * The wrapper methods call the notify() method (inherited
 * from the Observable class) after changing the model.
 * In doing so, observers of the SymbolistModel are notified of
 * the change and can proceed accordingly.
 */
class SymbolistModel : public virtual Observable {
    
    unique_ptr<Score >   score;
    unique_ptr<Palette > palette;
    
public:
    
    /************************************************
     *                 CONSTRUCTORS                 *
     ************************************************/
    
    /**
     * SymbolistModel's empty constructor.
     */
    SymbolistModel();
    
    /**
     * SymbolistModel's default destructor.
     */
    inline virtual ~SymbolistModel() {}
    
    /*******************************************************
     *                 GETTERS AND SETTERS                 *
     *******************************************************/
    inline Score* getScore() { return score.get(); }
    inline void setScore(Score* score) { this->score = unique_ptr<Score>(score); }
    inline Palette* getPalette() { return palette.get(); }
    inline void setPalette(Palette* palette) { this->palette = unique_ptr<Palette>(palette); }
    
    /***************************************************
     *                 WRAPPER METHODS                 *
     ***************************************************/
    
    /**
     * Wrapper method around Score::addSymbol(Symbol*).
     *
     * Notifies the observers of this SymbolistModel instance
     * that the score has been changed.
     *
     * @param symbol a pointer to the symbol which will be copied
     *               to create a new symbol in the score.
     *
     * @return       a pointer to the newly created symbol
     *               in the score.
     *
     * @see          Score#addSymbol(Symbol*) Score::addSymbol
     */
    Symbol* addSymbolToScore(Symbol* symbol);
    
    /**
     * Wrapper method around Score::importSymbols(const OdotBundle_s&).
     *
     * Notifies the observers of this SymbolistModel instance
     * that the score has been changed.
     *
     * @param bundle    a serialized OSC bundle containing
     *                    one or many symbols as OSC bundles.
     *
     * @see               Score#importSymbols(const OdotBundle_s&) Score::importSymbols
     */
    void importSymbols( const OdotBundle_s& bundle );
    
    /**
     * Wrapper method around Score::removeAllSymbols().
     *
     * Notifies the observers of this SymbolistModel instance
     * that the score has been changed.
     *
     * @see Score#removeAllSymbols() Score::removeAllSymbols
     */
    void removeAllSymbolsFromScore();
    
    /**
     * Wrapper method around Palette::addUserItem(Symbol).
     *
     * Notifies the observers of this SymbolistModel instance
     * that the palette has been changed.
     *
     * @param symbol the symbol to add to the palette
     *
     * @see          Palette#addUserItem(Symbol) Palette::addUserItem
     */
    void addSymbolToPalette(Symbol symbol);
	
	/**
	 * Updates (or creates) the /expr message contained in symbol
	 * with the newExpression value.
	 *
	 * @param symbol        a reference to the symbol which will be updated.
	 *
	 * @param newExpression the new value assigned to /expr in symbol.
	 *
	 */
    void updateExprInSymbol(Symbol* symbol, string newExpression);
	
	
	/**
	 * Wrapper method around Score::addSatff(Symbol).
	 *
	 * Adds a new staff to the score, and resets all staves time duration
	 * and time start.
	 *
	 * @param newStaff the new staff symbol to add to the score.
	 *
	 * @see Score#addSatff(Symbol) Score::addSatff(Symbol)
	 */
	void addStaff(Symbol* newStaff);
	
	/**
	 * Removes a symbol from the score and from the time point
	 * array associated with the score.
	 *
	 * @param s the symbol to remove from the score.
	 */
	void removeSymbolFromScore( Symbol* s );
	
    //==============================================================================
    JUCE_LEAK_DETECTOR (SymbolistModel)
};


#endif /* SymbolistModel_hpp */
