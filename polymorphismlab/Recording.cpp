///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "Recording.h"

using namespace std;
extern ofstream csis;

///////////////////////////////////////////////////////////////////////////////
Recording::Recording( const char* title, int callNum, const char* format,
                      const char* performer ) : Holding( title, callNum )
{
    //allocate memory for _performer and _format
    _performer = new char[strlen(performer)+1];
    _format = new char[strlen(format)+1];

    //copy performer and format into _performer and _format
    strcpy( _performer, performer );
    strcpy( _format, format );
}

Recording::Recording( const Recording& src ) : Holding( src )
{
    //allocate memory for _performer and _format
    _performer = new char[strlen(src._performer)+1];
    _format = new char[strlen(src._format)+1];

    strcpy( _performer, src._performer );
    strcpy( _format, src._format );   
}

Recording::~Recording()
{
    //delete because we allocated memory using 'new'
    if( _performer != nullptr )
        delete [] _performer;
    if( _format != nullptr )
        delete [] _format;
}

void Recording::print()
{
    //print recording title, performer, format, and call number 
    cout << "RECORDING: " << " \"" << _title << "\" "<< _performer << " (" << _format << ")"
         << " " << _callNum << endl;
    csis << "RECORDING: " << " \"" << _title << "\" "<< _performer << " (" << _format << ")"
         << " " << _callNum << endl;
    
}
