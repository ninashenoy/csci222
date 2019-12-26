///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
#include "Holding.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
Holding::Holding( const char* title, int callNum )
{
    //allocate memory for _title
    _title = new char[strlen(title)+1];
    //copy title into _title
    strcpy( _title, title );
    //set _callNum
    _callNum = callNum;
}

///////////////////////////////////////////////////////////////////////////////
Holding::Holding( const Holding& src )
{
    //allocate memory for _title
    _title = new char[strlen(src._title)];
    strcpy( _title, src._title );
    _callNum = src._callNum;
}

///////////////////////////////////////////////////////////////////////////////
Holding::~Holding()
{
    //delete _title because we allocated memory using 'new'
    if( _title != nullptr )
    {
        delete _title;
    }
}

