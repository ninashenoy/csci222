///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string.h>
#include "Book.h"

using namespace std;
extern ofstream csis;

///////////////////////////////////////////////////////////////////////////////
Book::Book( const char* title, int callNum, const char* author ) : Holding( title, callNum )
{
    _author = new char[strlen(author)+1];
    strcpy( _author, author );
}

///////////////////////////////////////////////////////////////////////////////
Book::Book( const Book& src ) : Holding( src )
{
    _author = new char[strlen(src._author)+1];
    strcpy( _author, src._author );
}

///////////////////////////////////////////////////////////////////////////////
Book::~Book()
{
    if( _author != nullptr )
        delete [] _author;
}

///////////////////////////////////////////////////////////////////////////////
void Book::print()
{
    cout << "BOOK: " << " "  <<_author << " " << "\"" << _title << "\"" << " " << _callNum << endl;
    csis << "BOOK: " << " "  <<_author << " " << "\"" << _title << "\"" << " " << _callNum << endl;

}