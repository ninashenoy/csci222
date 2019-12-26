#include "elevator.cpp"

int main( int argc, char* argv[] )
{
    Elevator a;
    Elevator b(7, 2);

    a.selectFloor(7);
    a.go();

    return 0;
}