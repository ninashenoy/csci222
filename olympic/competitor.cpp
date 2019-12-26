///////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>

#include "competitor.h"

using namespace std;

extern ofstream csis;

///////////////////////////////////////////////////////////////////////////////
// Constructor, takes const char* for name and an int for lane
// We use const char* because we will not be changing the string in the function
Competitor::Competitor( const char* name, int lane )
{
    _name = new char[ strlen(name) + 1 ];
    strcpy( _name, name );
    _lane = lane;
}

///////////////////////////////////////////////////////////////////////////////
// delete [] deallocates the memory allocated by 'new' in the constructor
Competitor::~Competitor()
{
    delete [] _name;
}

///////////////////////////////////////////////////////////////////////////////
// takes a float for time, sets the time for a competitor
void Competitor::setTime( float time )
{
    _time = time;
}

///////////////////////////////////////////////////////////////////////////////
// returns the name of the competitor
const char* Competitor::getName()
{
    return _name;
}

///////////////////////////////////////////////////////////////////////////////
// returns the lane of a competitor
int Competitor::getLane()
{
    return _lane;
}

///////////////////////////////////////////////////////////////////////////////
// returns the time of a competitor
float Competitor::getTime()
{
    return _time;
}

///////////////////////////////////////////////////////////////////////////////
// prints out the lane, competitor name, and time all in one line
void Competitor::print()
{
    cout << "*************************************************" << endl;
    csis << "*************************************************" << endl;
    cout << "Lane: " << _lane << " Name: " << _name << " Time: " << _time << endl;
    csis << "Lane: " << _lane << " Name: " << _name << " Time: " << _time << endl;
    return;
}

///////////////////////////////////////////////////////////////////////////////
