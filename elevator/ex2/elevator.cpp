#include <iostream>

using namespace std;
class Elevator
{
    private:
        int floorSelected;
        int floorNumber;
    public:
    Elevator()
    {
        floorSelected = 0;
        floorNumber = 0;
    }
    Elevator( int selected, int number )
    {
        floorSelected = selected;
        floorNumber = number;
    }
    ~Elevator()
    {
        floorSelected = 0;
        go();
    }
    void selectFloor( int floor )
    {
        floorSelected = floor;
    }
    void go()
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

};
