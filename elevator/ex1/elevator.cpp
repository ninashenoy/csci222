#include <iostream>
#define FLOORS 10

using namespace std;

struct elevator
{
    int floorSelected;
    int floorNumber;
    void initialize();
    void selectFloor( int floor );
    void go();
};

void elevator::initialize()
{
    floorSelected = 0;
    floorNumber = 0;
}

void elevator::selectFloor( int floor )
{
    floorSelected = floor;
    /*
    if( floor < 0 || floor >= FLOORS );
    {
        return;
    }
    */
}

void elevator::go()
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

int main( int argc, char* argv[] )
{
    elevator A;
    A.initialize();
    A.selectFloor(5);
    A.go();
}