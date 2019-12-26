///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include "String.h"

using namespace std;

extern ofstream csis;

///////////////////////////////////////////////////////////////////////////////
class CaseString : public String
{
    private:
        char* upper;
        char* lower;

    public:
        CaseString() : String() {}
        CaseString( const CaseString& src ) : String( src )
        {
            upper = new char[src.getLength()+1];
            lower = new char[src.getLength()+1];
            for( int i = 0; i < src.getLength(); i++ )
            {
                upper[i] = toupper(src.buf[i]);
                lower[i] = tolower(src.lower[i]);
            }
        }
        CaseString( const char* src ) : String( src )
        {
            upper = new char[strlen(src)+1];
            lower = new char[strlen(src)+1];

            for( int i = 0; i < strlen(src); i++ )
            {
                upper[i] = toupper(src[i]);
                lower[i] = tolower(src[i]);
            }
        }
        ~CaseString()
        {
            delete [] upper;
            delete [] lower;
        }

        void print();
        CaseString& operator= ( const CaseString& );
};

