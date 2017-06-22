
#include "TimePointArray.h"

void TimePointArray::addSymbolTimePoints( Symbol *s )
{
    float start_t = s->getTime();
    float end_t = s->getEndTime();

    addSymbol_atTime( s, start_t );
    addSymbol_atTime( s, end_t );
}

void TimePointArray::printTimePoints()
{
    cout << "-------- timepoint list ----------" << endl;
    int count = 0;
    for( auto t : (*this) )
    {
        cout << "timepoint " << count << " " << t->symbols_at_time.size() << " overlapping at " << t->time << endl;
        
        for (auto s : t->symbols_at_time)
        {
            cout << "\t" << s << "\t" << s->getTime() << "\t" << s->getEndTime() << endl;
        }
        
        count++;
    }
}

void TimePointArray::addSymbol_atTime( Symbol *s, float time)
{
    bool match;
    int idx = getTimePointInsertIndex( time, match );
    if( match )
    {
        (*this)[ idx ]->addSymbol( s );
    }
    else
    {
        auto newTimePoint = insert( idx, new SymbolTimePoint( s, time ) );
        
        if( idx - 1 >= 0 )
        {
            auto prevTimePoint = (*this)[idx-1];

            for( auto prev_s : prevTimePoint->symbols_at_time )
            {
                if( s == prev_s ) continue;
                
                if( prev_s->hitTest( time ) )
                {
                    newTimePoint->addSymbol( prev_s );
                }
                else if ( s->hitTest( prevTimePoint->time ) )
                {
                    prevTimePoint->addSymbol( s );
                }

            }
    
        }
    }
    
    printTimePoints();
}

void printBundle(OSCBundle bndl)
{
    std::cout << "==== OSC BUNDLE ====" << std::endl;
    for (auto osc : bndl )
    {
        OSCMessage msg = osc.getMessage();
        std::cout << msg.getAddressPattern().toString();
        
        for (auto arg : msg )
        {
            if( arg.isString() )
                std::cout << " " << arg.getString();
            else if( arg.isFloat32() )
                std::cout << " " << (String)arg.getFloat32();
            else if( arg.isInt32() )
                std::cout << " " << (String)arg.getInt32();
            else if( arg.isBlob() )
                std::cout << " " << "blob";
        }
        
        std::cout << std::endl;
    }
    std::cout << "====-===-======-====" << std::endl;
    
}

odot_bundle* symbolBundleToOdot( const OSCBundle& osc )
{
    OSCWriter w ;
    w.writeBundle( osc );
    size_t size = w.getDataSize();
    
    odot_bundle *bundle = new odot_bundle;
    
    bundle->len = static_cast<long>(size);
    bundle->data = new char[size];
    std::memcpy(bundle->data, w.getData() ,size );
    
    return bundle;
}

odot_bundle *TimePointArray::timePointToOSC(const SymbolTimePoint *tpoint  )
{
    const vector<Symbol*> vec = tpoint->symbols_at_time;
    
    OSCBundle bndl;
    int count = 0;
    String prefix = "/symbolsAtTime/";
    for (auto s : vec )
    {
        // ignore symbols if after endpoint
        if( current_time <= s->getEndTime() )
        {
            auto s_bndl = s->getOSCBundle();

            for ( auto osc : s_bndl )
            {
                OSCMessage msg = osc.getMessage();
                
                String newaddr = prefix + String(count) + msg.getAddressPattern().toString();
                
                msg.setAddressPattern(newaddr);
                
                bndl.addElement(msg);

            }
            
            count++;
        }
        else
        {
//             cout << "skipped sym " << s << " endpt: " << s->getEndTime() << endl;
        }
    }
    
    return symbolBundleToOdot( bndl );
}

int TimePointArray::lookupTimePoint( float t )
{
    int idx = (current_point < 0 ) ? 0 : current_point;
    float p_time = current_time;

    if ( p_time < t ) // moving forward
    {
        // maybe check one step before doing the loop?
        
        for ( ; idx < size(); idx++ ) // step forward
        {
            p_time = (*this)[ idx ]->time;
            
            if (p_time > t) // if point time is >, we want the previous one
            {
                current_time = t;
                current_point = idx - 1;
                return current_point;
            }
        }
        
        if( idx >= size() )
            current_point = size() - 1;
        else
            cout << "shouldn't happen " << current_point <<  endl;
        
        current_time = t;
        return current_point;
        
    }
    else if ( p_time > t )
    {
        for ( ; idx >= 0; idx-- ) // step backward
        {
            p_time = (*this)[ idx ]->time;
            
            if (p_time < t) // if point time is <, we want the previous one
            {
                current_time = t;
                current_point = idx;
                return current_point;
            }
        }
        
        // if we run off the end, we are before the first time point
        current_point = idx;
        current_time = t;
        
        return current_point;
    }

    // otherwise, we're not moving
    current_time = t;
    return current_point;
}

odot_bundle *TimePointArray::getSymbolsAtTime( float t )
{
    if (size() == 0 )
        return nullptr;
    
    int idx = lookupTimePoint( t );
    current_point = idx;

//    cout << "timepoint number: " << current_point << endl;
    if( idx >= 0 )
    {
        auto tpoint = (*this)[idx];

      //  cout << "for " << t <<" closest timepoint: " << idx << " at " << tpoint->time << " with: " << tpoint->symbols_at_time.size() << " overlaping" << endl;
        
        return timePointToOSC( tpoint );
    }
    
    return nullptr;
}

int TimePointArray::getTimePointInsertIndex( float t, bool& match )
{
    match = false;
    
    int firstElement = 0, lastElement = size();
    while (firstElement < lastElement)
    {
        if (compareTimes ( (*this)[firstElement]->time, t ) == 0)
        {
            match = true;
            break;
        }
        else
        {
            const int halfway = (firstElement + lastElement) >> 1;
            
            if (halfway == firstElement)
            {
                if (compareTimes ((*this)[firstElement]->time, t ) >= 0)
                {
                    ++firstElement;
                }
                break;
            }
            else if (compareTimes ((*this)[firstElement]->time, t ) >= 0)
            {
                firstElement = halfway;
            }
            else
            {
                lastElement = halfway;
            }
        }
    }
    
    return firstElement;
}
