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
        //print to console
        cout << buf[idx];
        //print to file
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
    // check for null before you check for length
    if( src != nullptr && strlen(src) > 0 )
    {
        length = strlen(src) + 1;
        buf = new char[length];
        strcpy( buf, src );
    }
    else
    {
        length = 0;
        buf = nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////
String::String( char src )
{
    if( src != '\0' )
    {
        length = 2;
        buf = new char[length];
        buf[0] = src;
        buf[1] = '\0';
    }
    else
    {
        length = 0;
        buf = nullptr; 
    }
    
    
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
    length = 0;
}

///////////////////////////////////////////////////////////////////////////////
// Here you return a reference because you are assigning a value.
// This allows you to perform an operation a = b = c, where c is assigned to b
// and b is assigned to a.
const String& String::operator= ( const String& src )
{
    char* new_buf = new char[src.length];
    strcpy( new_buf, src.buf );

    reset();
    length = src.length;
    buf = new_buf;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
const String& String::operator= ( const char* src )
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
const String& String::operator+= ( const String& src )
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
// Here, you return a reference because you are assigning a value
// For example, s0 = 'C'. The character 'C' needs to go to &0 of the char buffer
char& String::operator[] ( int index )
{
    // assert
    return buf[index];
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

