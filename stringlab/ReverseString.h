///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string.h>
#include "String.h"

///////////////////////////////////////////////////////////////////////////////
class ReverseString : public String
{
    private:
    public:
        ReverseString() : String() {}
        ReverseString( const char* src ) : String( src ) {}
        ReverseString( const ReverseString& src ) : String( src ) {}

        ReverseString& operator= ( const ReverseString& );
        ReverseString operator~ ();

};

