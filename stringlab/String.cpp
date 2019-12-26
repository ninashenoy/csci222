///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "String.h"

using namespace std;

extern ofstream csis;

///////////////////////////////////////////////////////////////////////////////
void String::reset()
{
    length = 0;
    if( buf != nullptr )
        delete [] buf;
    buf = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
int String::getLength() const
{
    int len = 0;
    if( buf != nullptr )
        len = strlen(buf);
    return len;
}

///////////////////////////////////////////////////////////////////////////////
void String::print()
{
    for( int idx = 0; idx < getLength(); idx++ )
    {
        cout << buf[idx];
        csis << buf[idx];
        
    }
    cout << endl;
    csis << endl;
}

///////////////////////////////////////////////////////////////////////////////
String::String()
{
    length = 0;
    buf = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
String::String( const char* src )
{
    length = strlen(src) + 1;
    buf = new char[length];
    strcpy( buf, src );
}

///////////////////////////////////////////////////////////////////////////////
String::String( char src )
{
    length = 2;
    buf = new char[length];
    buf[0] = src;
    buf[1] = '\0';
}

////////////////////////////////////////////////////////////////////////////////
String::String( int src )
{
    if( src > 0 )
    {
        length = src;
        buf = new char[length];
        buf[0] = '\0';
    }
    else
    {
        length = 0;
        buf = nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////
String::String( const String& src )
{
    length = src.length;
    buf = new char[length];
    strcpy( buf, src.buf );
}

///////////////////////////////////////////////////////////////////////////////
String::String( char c, int char_count )
{
    length = char_count + 1;
    buf = new char[length];
    memset( buf, 0, length * sizeof(char) );
    for( int idx = 0; idx < char_count; idx++ )
    {
        buf[idx] = c;
    }
}

///////////////////////////////////////////////////////////////////////////////
String::~String()
{
    if( buf != nullptr )
    {
        delete [] buf;
        buf = nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator= ( const String& src )
{
    char* new_buf = new char[src.length];
    strcpy( new_buf, src.buf );

    reset();
    length = src.length;
    buf = new_buf;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator= ( const char* src )
{
    reset();
    // assert?
    length = strlen(src) + 1;
    buf = new char[length];
    strcpy( buf, src );
    return *this;
}


///////////////////////////////////////////////////////////////////////////////
String operator+ ( const String& s1, const String& s2 )
{
    String temp;
    temp.length = s1.getLength() + s2.getLength() + 1;
    temp.buf = new char[temp.length];
    memset( temp.buf, 0, temp.length * sizeof(char) );
    for( int idx = 0; idx < s1.getLength(); idx++ )
    {
        temp.buf[idx] = s1.buf[idx];
    }
    int idx = 0;
    for( int i = s1.getLength(); i < (temp.length - 1); i++ )
    {
        temp.buf[i] = s2.buf[idx];
        idx++;
    }
    return temp;
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator+= ( const String& src )
{
    int new_length = getLength() + src.getLength() + 1;
    char* new_buf = new char[ new_length ];

    memset( new_buf, 0, new_length * sizeof(char) );
    for( int i = 0; i < getLength(); i++ )
    {
        new_buf[i] = buf[i];
    }
    int idx = 0;
    for( int i = getLength(); i < new_length - 1; i++ )
    {
        new_buf[i] = src.buf[idx];
        idx++;
    }
    reset();
    length = new_length;
    buf = new_buf;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
String String::operator+ () const
{
    String temp;
   
    temp.length = length;
    temp.buf = new char[length];
    for( int i = 0; i < length; i++ )
    {
        if( buf[i] >= 97 && buf[i] <= 122 )
        {
            temp.buf[i] = buf[i]-32;
        }
        else
        {
            temp.buf[i] = buf[i];
        }
    }
    return temp;
}

///////////////////////////////////////////////////////////////////////////////
int operator== ( const String& s1, const String& s2 )
{
    int equals = 0;
    if( s1.getLength() == s2.getLength() )
    {
        int matchCount = 0;
        for( int i = 0; i < s1.getLength(); i++ )
        {
            if( s1.buf[i] == s2.buf[i] )
            {
                matchCount++;
            }
        }
        if( matchCount == s1.getLength() )
        {
            equals = 1;
        }
    }
    return equals;
}

///////////////////////////////////////////////////////////////////////////////
int operator!= ( const String& s1, const String& s2 )
{
    int equals = 1;
    if( s1.getLength() == s2.getLength() )
    {
        int matchCount = 0;
        for( int i = 0; i < s1.getLength(); i++ )
        {
            if( s1.buf[i] == s2.buf[i] )
            {
                matchCount++;
            }
        }
        if( matchCount == s1.getLength() )
        {
            equals = 0;
        }
    }
    return equals;
}

///////////////////////////////////////////////////////////////////////////////
int operator< ( const String& s1, const String& s2 )
{
    int equals = 0;
    if( strcmp(s1.buf, s2.buf) < 0 )
    {
        equals = 1;
    }
    return equals;
}

///////////////////////////////////////////////////////////////////////////////
int operator<= ( const String& s1, const String& s2 )
{
    int equals = 0;
    if( strcmp(s1.buf, s2.buf) <= 0 )
    {
        equals = 1;
    }
    return equals;
}

///////////////////////////////////////////////////////////////////////////////
int operator> ( const String& s1, const String& s2)
{
    int equals = 0;
    if( strcmp(s1.buf, s2.buf) > 0 )
    {
        equals = 1;
    }
    return equals;
}

///////////////////////////////////////////////////////////////////////////////
int operator>= ( const String& s1, const String& s2)
{
    int equals = 0;
    if( strcmp(s1.buf, s2.buf) >= 0 )
    {
        equals = 1;
    }
    return equals;
}

///////////////////////////////////////////////////////////////////////////////
char& String::operator[] ( int index )
{
    // assert
    return buf[index];
}

///////////////////////////////////////////////////////////////////////////////
char* operator+ ( const String& src, int i )
{
    char* cptr = nullptr;
    cptr = &src.buf[i];
    return cptr;
}

///////////////////////////////////////////////////////////////////////////////
char* operator+ ( int i, const String& src )
{
    char* cptr = nullptr;
    cptr = &src.buf[i];
    return cptr;
}

///////////////////////////////////////////////////////////////////////////////
String operator+ ( const String& src, char ch )
{
    String str = src + String(ch);
    return str;
}

///////////////////////////////////////////////////////////////////////////////
String operator+ ( char ch, const String& src)
{
    String str = String(ch) + src;
    return str;
}

///////////////////////////////////////////////////////////////////////////////
String operator+ ( const char* p, const String& src)
{
    String str = String(p) + src;
    return str;
}

///////////////////////////////////////////////////////////////////////////////
String operator+ (const String& src, const char* p)
{
    String str = src + String(p);
    return str;
}


///////////////////////////////////////////////////////////////////////////////
String& String::operator++ ()
{
    for( int i = 0; i < getLength(); i++ )
    {
        ++buf[i];
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator-- ()
{
    for( int i = 0; i < getLength(); i++ )
    {
        --buf[i];
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator++ (int)
{
    for( int i = 0; i < getLength(); i++ )
    {
        buf[i]++;
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator-- (int)
{
    for( int i = 0; i < getLength(); i++ )
    {
        buf[i]--;
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
String String::substr( int idx1, int idx2 )
{
    String temp;
    temp.reset();

    // assert if idx1,idx2 are same and negative
    if( idx2 > idx1 )
    {
        temp.length = idx2 - idx1 + 2;
        temp.buf = new char[temp.length];

        int str = idx1;
        for( int i = 0; i < temp.length - 1; i++ )
        {
            temp.buf[i] = buf[str];
            str++;
        }
    }
    return temp;
}

///////////////////////////////////////////////////////////////////////////////
ostream& operator<< ( ostream& os, const String& src )
{
    for( int i = 0; i < src.getLength(); i++ )
    {
        os << src.buf[i];
    }
    return os;
}

