///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _INTARRAY_H_
#define _INTARRAY_H_

#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
class IntArray
{
    private:
        char*   _name;
        int*    _myarray;
        int     _minIndex;
        int     _maxIndex;


    public:
    //constructors & destructor
    IntArray();
    IntArray( int numElements );
    IntArray( int lowIndex, int highIndex );
    IntArray( const IntArray &intarray );
    ~IntArray();

    //getter & setter functions
    int high() const;
    int low() const;
    int getValidIndex( int idx ) const;

    void setName( const char* name );
    const char* getName() const;
    void print() const;
    int getSize() const;


    //operator overloading
    friend IntArray operator+ ( IntArray a, IntArray b ) ;
    IntArray& operator+= ( IntArray a );
    IntArray& operator= ( IntArray a );
    int operator== ( IntArray a );
    int operator!= ( IntArray a );
    int& operator[] ( int idx );

    friend ostream& operator<< ( ostream& os, const IntArray& a );


};
#endif