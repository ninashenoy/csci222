///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__

///////////////////////////////////////////////////////////////////////////////
class Elevator
{
    
    private:
        int floorSelected;
        int floorNumber;
    public:
        Elevator(); 
        Elevator( int selected, int number );
        void selectFloor( int floor ) ;
        void go();
        int getFloor();
        ~Elevator();

};

#endif
