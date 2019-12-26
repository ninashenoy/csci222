///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "elevator.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    int i;
    Elevator **eptr;

    eptr = new Elevator *[5];
    for( i = 0; i < 5; i++ ) 
    {
        eptr[i] = new Elevator;
    }
    for( i = 0; i < 5; i++ )
    {
        eptr[i] -> selectFloor(i);
        eptr[i] -> go();
    }    
    for( i = 0; i < 5; i++ )
    {
        cout << eptr[i] -> getFloor() << endl;
    }
    for( i = 0; i < 5; i++ )
    {
        delete eptr[i];
    }
    delete [] eptr;

}