#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include "CaseString.h"

using namespace std;

extern ofstream csis;

CaseString& CaseString::operator= ( const CaseString& src )
{
    char* new_buf = new char[src.length];
    char* new_upper = new char[src.length];
    char* new_lower = new char[src.length];

    strcpy( new_buf, src.buf );
    strcpy( new_upper, src.upper );
    strcpy( new_lower, src.lower );

    reset();
    length = src.length;
    buf = new_buf;
    lower = new_lower;
    upper = new_upper;
    
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
void CaseString::print()
{
    cout << upper << endl;
    csis << upper << endl;
    cout << lower << endl;
    csis << lower << endl;
}