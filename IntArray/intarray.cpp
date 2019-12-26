///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string.h>
#include <assert.h>
#include "intarray.h"

extern ofstream csis;

#define MAX_ARRAY_SIZE 10

///////////////////////////////////////////////////////////////////////////////
//gets the size of an array
int IntArray::getSize() const
{
    int size = 0;
    size = _maxIndex - _minIndex;

    //program will crash if size is 0 or less
    //we want the size of the integer array to be at least one.
    assert( size > 0 );
    return size;
}

///////////////////////////////////////////////////////////////////////////////
//gets the correct index of an array
int IntArray::getValidIndex( int idx ) const
{
    assert( idx >= low() );
    assert( idx <= high() );
    
    int index = idx - low();
    //the index should never be less than 0, or else the program will halt.
    assert( index >= 0 );
    return index;
}

///////////////////////////////////////////////////////////////////////////////
//gets max index of an array
int IntArray::high() const
{
    return _maxIndex - 1;
}

///////////////////////////////////////////////////////////////////////////////
//gets min index of an array
int IntArray::low() const
{
    return _minIndex;
}

///////////////////////////////////////////////////////////////////////////////
//creates an IntArray object of size 10 and initializes the values to 0
IntArray::IntArray()
{
    //set the name to null, memory will be allocated in setName()
    _name = NULL;
    _minIndex = 0;
    _maxIndex = MAX_ARRAY_SIZE;
    //allocate memory for the integer array
    _myarray = new int[getSize()];
    //loop and set every element in _myarray to 0
    for( int idx = low(); idx <= high(); idx++ )
    {
        _myarray[getValidIndex(idx)] = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
//creates an IntArray object of size numElements and initializes the values to 0

IntArray::IntArray( int numElements )
{
    //set the name to null, memory will be allocated in setName()
    _name = NULL;
    assert( numElements > 0 );

    _minIndex = 0;
    _maxIndex = numElements;
    _myarray = new int[getSize()];
    
    for( int idx = low(); idx <= high(); idx++ )
    {
        _myarray[idx] = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
//creates an IntArray object of specified indices and sets values to 0
IntArray::IntArray( int lowIndex, int highIndex )
{
    //the lower index must not be larger than the higher index
    //assert( lowIndex <= highIndex );

    //set the name to null, memory will be allocated in setName()
    _name = NULL;
    _minIndex = lowIndex;
    _maxIndex = highIndex + 1;
    if( _minIndex <= _maxIndex )
    {
        _myarray = new int[getSize()];

        //loop through array and set values equal to 0
        for( int idx = low(); idx <= high(); idx++ )
        {
            _myarray[getValidIndex(idx)] = 0;
        }   
    }
    else
    {
        cout << "ERROR!!! Lower Index cannot be greater than max index." << endl;
        cout << "Stopping program..." << endl;
        csis << "ERROR!!! Lower Index cannot be greater than max index." << endl;
        csis << "Stopping program..." << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////
//copies contents of one IntArray object to another
IntArray::IntArray( const IntArray& intarray )
{
    //set the name to null, memory will be allocated in setName()
    _name = NULL;
    //copy max and min values from the object passed in to the object being
    //...created
    _minIndex = intarray._minIndex;
    _maxIndex = intarray._maxIndex;

    _myarray = new int[intarray.getSize()];
    for( int idx = 0; idx < getSize(); idx++ )
    {
        _myarray[idx] = intarray._myarray[idx];
    }
}

///////////////////////////////////////////////////////////////////////////////
//destructor
IntArray::~IntArray()
{
    //_myarray will never be null because in all 4 possible constructors, you 
    //...are allocating memory. So, we don't need to check if the pointer is
    //...null before we delete it
    //We use [] because we used new[] to allocate memory.
    delete [] _myarray;
    _myarray = NULL;
    //We have to check if the _name pointer is null. If so, we will delete it.
    //We use [] because we used new[] to allocate memory.
    if( _name == NULL )
    {
        delete [] _name;
    }
}

///////////////////////////////////////////////////////////////////////////////
//sets the name of an IntArray object
void IntArray::setName( const char* name )
{
    //the assert ensures that this function is called only once
    assert( _name == NULL );
    _name = new char[ strlen(name) + 1 ];
    _name = strcpy( _name, name );
    return;
}

///////////////////////////////////////////////////////////////////////////////
//gets the name of an IntArray object
const char* IntArray::getName() const
{
    if( _name == nullptr )
        return "";
    return _name;
}

///////////////////////////////////////////////////////////////////////////////
// copies the values of one IntArray object to another
IntArray& IntArray::operator=( IntArray intarray )
{
    //copy max and min values from the object passed in to the object being
    //...created
    if( getSize() == intarray.getSize() )
    {
        _minIndex = intarray._minIndex;
        _maxIndex = intarray._maxIndex;

        _myarray = new int[intarray.getSize()];
        for( int idx = 0; idx < getSize(); idx++ )
        {
            _myarray[idx] = intarray._myarray[idx];
        }
    }
    else
    {
        cout << "ERROR!!! Cannot assign arrays of mismatches sizes..." << endl;
        cout << "Stopping program...";
        csis << "ERROR!!! Cannot assign arrays of mismatches sizes..." << endl;
        csis << "Stopping program...";
    }
    return *this;
   
}

///////////////////////////////////////////////////////////////////////////////
//accesses the index idx of an IntArray object
int& IntArray::operator[] ( int idx )
{
    if( idx < low() || idx > high() )
    {
        cout << "ERROR!!! Trying to access invalid index." << endl;
        cout << "Stopping prorgam..." << endl;
        csis << "ERROR!!! Trying to access invalid index." << endl;
        csis << "Stopping prorgam..." << endl;
        return _myarray[0];
    }
    return _myarray[getValidIndex(idx)];
}

///////////////////////////////////////////////////////////////////////////////
//sums the values of two intArray objects and returns a new object
IntArray operator+ ( IntArray a, IntArray b )
{
    assert( a.getSize() == b.getSize() );

    IntArray temp( a.low(), a.high() );
    for( int i = 0; i < a.getSize(); i++ )
    {
        temp._myarray[i] = a._myarray[i] + b._myarray[i];
    }
    return temp;
}

///////////////////////////////////////////////////////////////////////////////
// sums the values of two intArray objects into the first object
IntArray& IntArray::operator+= ( IntArray a )
{
    //check that the arrays are the same size
    assert( getSize() == a.getSize() );

    //loop through array and add the contents of both arrays and save the
    //...result in the first array
    for( int i = 0; i < getSize(); i++ )
    {
        _myarray[i] = _myarray[i] + a._myarray[i];
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
//checks if the values of two IntArray objects are all equal
int IntArray::operator== ( IntArray a )
{
    if( getSize() == a.getSize() )
    {
        int numMatches = 0;
        for( int i = 0; i < getSize(); i++ )
        {
            if( _myarray[i] == a._myarray[i] )
            {
                numMatches++;
            }
        }
        if( numMatches == getSize() )
        {
            return 1;
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//checks if two IntArray objects are NOT equal
int IntArray::operator!= ( IntArray a )
{
    int equal = 0;
    if( *this == a )
        equal = 1;
    return !equal;
}


///////////////////////////////////////////////////////////////////////////////
//prints out the name, indices, and values of an IntArray object
ostream& operator<< ( ostream& os, const IntArray& a )
{
    os << endl;
    for( int i = a.low(); i <= a.high(); i++ )
    {
        os << a.getName() << "[" << i << "]" << " = " << a._myarray[a.getValidIndex(i)] << endl;
    }
    return os;
}
///////////////////////////////////////////////////////////////////////////////


