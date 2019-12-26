///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "elevator.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
Elevator::Elevator()
{
    floorSelected = 0;
    floorNumber = 0;
}
Elevator::Elevator( int selected, int number )
{
    floorSelected = selected;
    floorNumber = number;
}
Elevator::~Elevator()
{
    floorSelected = 0;
    go();
}
void Elevator::selectFloor( int floor )
{
    floorSelected = floor;
}
void Elevator::go()
{
    if( floorNumber < floorSelected )
    {
        while( ++floorNumber < floorSelected )
        {
            cout << "floor " << floorNumber << " going up!" << endl;
        }
    }
    else if( floorNumber > floorSelected )
    {
        while( --floorNumber > floorSelected )
        {
            cout << "floor " << floorNumber << " going down!" << endl;
        }
    }
    cout << "floor " << floorNumber << " stopping." << endl;
}
int Elevator::getFloor()
{
    return floorNumber;
}

