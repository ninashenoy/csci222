///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#pragma once

using namespace std;
///////////////////////////////////////////////////////////////////////////////
class String
{
    protected:
        char* buf;
        int length;

    public:
        String();
        String( const char* );
        String( char );
        String( int );
        String( const String& );
        String( char, int );
        ~String();

        void print();
        void reset();
        int getLength() const;
        String substr( int, int );


        String& operator= ( const String& );
        String& operator= ( const char* );
        String& operator+= ( const String& );
        String operator+ () const;
        String& operator++ ();
        String& operator-- ();
        String& operator++ (int);
        String& operator-- (int);
        char& operator[] ( int );
        friend String operator+ ( const String&, const String& );

        friend char* operator+ ( const String&, int );
        friend char* operator+ ( int, const String& );

        friend String operator+ ( const String&, char );
        friend String operator+ ( char, const String& );
        friend String operator+ ( const String&, const char* );
        friend String operator+ ( const char*, const String& );

        friend int operator== ( const String&, const String& );
        friend int operator!= ( const String&, const String& );
        friend int operator< ( const String&, const String& );
        friend int operator<= ( const String&, const String& );
        friend int operator> ( const String&, const String& );
        friend int operator>= ( const String&, const String& );
        friend ostream& operator<< ( ostream&, const String& );
};
