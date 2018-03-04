#include "OdotAtom.hpp"


OdotAtom::OdotAtom()
{
    ptr = odot::newOdotAtomPtr();
//    D_(std::cout << "new empty pointer " << &ptr << " " << ptr.get() << std::endl;)
}

OdotAtom::OdotAtom( const OdotAtom& src )
{
//    D_(cout << __func__  << " copy object \n";)
    t_osc_atom_u *a = osc_atom_u_copy( src.ptr.get() );
    ptr = odot::newOdotAtomPtr( a );
}

// assumes we are not responible for the pointer (to work with osc_message_u_getArg()
OdotAtom::OdotAtom( t_osc_atom_u * src )
{
//    D_(cout << __func__ << " copy from pointer \n";)
    t_osc_atom_u *a = osc_atom_u_copy( src );
    ptr = odot::newOdotAtomPtr( a );
}

OdotAtom& OdotAtom::operator=( const OdotAtom& src )
{
///    D_(std::cout << "copy= \n";)
    
    if( this != &src )
    {
        t_osc_atom_u *a = osc_atom_u_copy( src.ptr.get() );
        ptr = odot::newOdotAtomPtr( a );
    }
    
    return *this;
}

OdotAtom::OdotAtomType OdotAtom::getType()
{
    switch ( osc_atom_u_getTypetag( ptr.get() ) )
    {
        case 'f':
            return O_ATOM_FLOAT;
        case 'd':
            return O_ATOM_DOUBLE;
        case 'i':
            return O_ATOM_INT;
        case 's':
            return O_ATOM_STRING;
        case OSC_BUNDLE_TYPETAG:
            return O_ATOM_BUNDLE;
        default:
            return O_ATOM_NONE;
    }
    
}
