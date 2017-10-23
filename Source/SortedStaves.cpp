
#include "SortedStaves.hpp"

SortedStaves::SortedStaves(){}

SortedStaves::~SortedStaves()
{
    staves.clear();
}

void SortedStaves::clear()
{
    staves.clear();
}

size_t SortedStaves::size()
{
    return staves.size();
}

void SortedStaves::erase( Symbol *s )
{
    staves.erase( remove( staves.begin(), staves.end(), s ), staves.end() );
}

void SortedStaves::removeStaff( Symbol *s)
{
    erase(s);
    resetTimes();
}

bool SortedStaves::compareStaves (const Symbol* a, const Symbol* b)
{
    auto a_x = Symbol::getOSCValueAsFloat( a->getOSCMessageValue("/x") );
    auto a_y = Symbol::getOSCValueAsFloat( a->getOSCMessageValue("/y") );
    auto a_x2 = a_x + Symbol::getOSCValueAsFloat( a->getOSCMessageValue("/w") );
    
    
    auto b_x = Symbol::getOSCValueAsFloat( b->getOSCMessageValue("/x") );
    auto b_y = Symbol::getOSCValueAsFloat( b->getOSCMessageValue("/y") );
    // auto b_x2 = b_x + Symbol::getOSCValueAsFloat( b->getOSCMessageValue("/w") );
    
    /*
    cout << "sorting: " << a << " " << b << endl;
    cout << "\t a_x " << a_x << " a_y " << a_y << " a_x2 " << a_x2 << endl;;
    cout << "\t b_x " << b_x << " b_y " << b_y << endl;
    
    cout << "test a_y < b_y " << (a_y < b_y) << endl;
    cout << "test a_x2 < b_x " << (a_x2 < b_x) << endl;
    */
    
    if( a_y < b_y && b_x < a_x2 )
        return true;
    
    return false;
    
    /*
     {
     if( a_y == b_y && a_x == b_x )
     return 0;
     else
     return 1;
     }
     */
}

void SortedStaves::resetTimes()
{
    sort( staves.begin(), staves.end(), compareStaves );

    float time = 0.0f;
    for( auto it = staves.begin(); it != staves.end(); it++)
    {
        
        Symbol *sym = *it;
                
        float w = Symbol::getOSCValueAsFloat( sym->getOSCMessageValue("/w") );
        
        sym->setOSCAddrAndValue( "/time/start", time );
        
        cout << "staff time " << time << " ";
        
        time += sym->pixelsToTime(w) ;
        
        sym->setOSCAddrAndValue( "/time/duration", time );
        
        cout << time << endl;
        
    }
    
    
    
}

bool SortedStaves::addStaff( Symbol *s)
{
    int pos = s->getOSCMessagePos("/type");
    if( pos == -1 || s->getOSCMessageValue(pos).getString() != "staff" )
        return 0;
    
    removeStaff(s);
    
    cout << "adding staff " << endl;
    staves.emplace_back(s);
    
    resetTimes();
    
    // probably not the right place to deal with names.. maybe duplicates should be allowed?
    
    cout << "setting staff name -- size: " << staves.size() << endl;
    String name;
    auto name_pos = s->getOSCMessagePos("/name");
    if( name_pos != -1 )
    {
        name = s->getOSCMessageValue(name_pos).getString();
    }
    
    if( name.isEmpty() ) // for now allow  name == s->getID()
    {
        s->setOSCAddrAndValue( "/name", "staff_" + (String)staves.size() );
    }
    
    return 1;
    
}

Symbol *SortedStaves::getStaveAtTime(float time)
{
    
    if( staves.size() == 0 || time < 0 || time > staves.back()->getEndTime() )
        return NULL;
    
    // cout << "end time " << staves.back()->getEndTime() << endl;
    
    for( auto s : staves )
    {
        if( time >= s->getTime() && time <= s->getEndTime() )
            return s;
    }
    
    return NULL;
}

const Symbol *SortedStaves::getStaveByID( const String& id )
{
    if( staves.size() == 0 || id.isEmpty() )
        return NULL;
    
    for( auto s : staves )
    {
        if( s->getID() == id )
            return s;
    }
    
    return NULL;
}

StringArray SortedStaves::getStaveNames()
{
    StringArray names;
    
    for( auto s : staves )
    {
        names.add( s->getID() );
    }
    
    return names;
}
