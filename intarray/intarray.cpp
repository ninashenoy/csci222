///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
#include <assert.h>
#include "intarray.h"


#define MAX_ARRAY_SIZE 10

///////////////////////////////////////////////////////////////////////////////
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
int IntArray::high() const
{
    return _maxIndex;
}

///////////////////////////////////////////////////////////////////////////////
int IntArray::low() const
{
    return _minIndex;
}

///////////////////////////////////////////////////////////////////////////////
IntArray::IntArray()
{
    //set the name to null, memory will be allocated in setName()
    _name = NULL;
    _minIndex = 0;
    _maxIndex = MAX_ARRAY_SIZE;
    //allocate memory for the integer array
    _myarray = new int[getSize()];
    //loop and set every element in _myarray to 0
    for( int idx = low(); idx < high(); idx++ )
    {
        _myarray[getValidIndex(idx)] = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
IntArray::IntArray( int numElements )
{
    cout << "HELLO" << endl;
    //set the name to null, memory will be allocated in setName()
    _name = NULL;
    assert( numElements > 0 );

    _minIndex = 0;
    _maxIndex = numElements;
    _myarray = new int[getSize()];
    
    for( int idx = low(); idx < high(); idx++ )
    {
        _myarray[idx] = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
IntArray::IntArray( int lowIndex, int highIndex )
{
    //set the name to null, memory will be allocated in setName()
    _name = NULL;

    //the lower index must not be larger than the higher index
    assert( lowIndex < highIndex );

    _minIndex = lowIndex;
    _maxIndex = highIndex;
    _myarray = new int[getSize()];

    //loop through array and set values equal to 0
    for( int idx = low(); idx < high(); idx++ )
    {
        _myarray[getValidIndex(idx)] = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
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
void IntArray::setName( const char* name )
{
    //the assert ensures that this function is called only once
    assert( _name == NULL );
    _name = new char[ strlen(name) + 1 ];
    _name = strcpy( _name, name );
    return;
}

///////////////////////////////////////////////////////////////////////////////
const char* IntArray::getName() const
{
    if( _name == nullptr )
        return "";
    return _name;
}

///////////////////////////////////////////////////////////////////////////////
IntArray& IntArray::operator=( IntArray intarray )
{
    //copy max and min values from the object passed in to the object being
    //...created
    _minIndex = intarray._minIndex;
    _maxIndex = intarray._maxIndex;

    _myarray = new int[intarray.getSize()];
    for( int idx = 0; idx < getSize(); idx++ )
    {
        _myarray[idx] = intarray._myarray[idx];
    }

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
int& IntArray::operator[] ( int idx )
{
    if( idx >= getSize())
    {
        cout << "ERROR! Array out of bounds." << endl;
        cout << "Stopping program..." << endl;
    }
    return _myarray[getValidIndex(idx)];
}

///////////////////////////////////////////////////////////////////////////////
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
int IntArray::operator!= ( IntArray a )
{
    int equal = 0;
    if( *this == a )
        equal = 1;
    return !equal;
}


///////////////////////////////////////////////////////////////////////////////
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
void IntArray::print() const
{
    // print only if _name is set or else the program will die
    if( _name != NULL )
    {
        cout << "Name: " << _name << endl;
    }
    //_myarray will always be valid because we set values in the constructors
    for( int idx = low(); idx < high(); idx++ )
    {
        cout << "Value["<< idx << "] = " <<_myarray[getValidIndex(idx)] << endl;
    }
    return;
}


