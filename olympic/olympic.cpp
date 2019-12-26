///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

#include "olympic.h"

using namespace std;

std::ofstream csis;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    //declare the number of lanes to be 4
    const int lanes = 4;

    Ranker rank(lanes);

    // the csis.txt file will be created in the directory where the program is
    // run 
    csis.open( "csis.txt", ios_base::out );

    //First make a list of names and lane assignments
    Competitor* starters[lanes];

    starters[0] = new Competitor( "Emmylou Harris", 1 );
    starters[1] = new Competitor( "Nanci Griffith", 2 );
    starters[2] = new Competitor( "Bonnie Raitt", 3 );
    starters[3] = new Competitor( "Joni Mitchell", 4 );

    // The race is run; now assign a time to each person
    starters[0]->setTime((float)12.0); 
    starters[1]->setTime((float)12.8); 
    starters[2]->setTime((float)11.0); 
    starters[3]->setTime((float)10.3); 

    // Put everyone into the ranker
    for( int comp = 0; comp < lanes; comp++ )
    {
        rank.addList(starters[comp]);
    }

    // Now print out the list to make sure it's right
    cout << "Competitors by lane are:" << endl;
    csis << "Competitors by lane are" << endl;
    for( int lane = 1; lane <= lanes; lane++ )
    {
        rank.getLane(lane)->print();
    }

    // Finally, show how they finished
    cout << "\nWinners are:\n";
    csis << "\nWinners are:\n";
    for( int finish = 1; finish <= lanes; finish++ )
    {
        rank.getFinish(finish)->print();
    }

    //free memory allocated for starters[] array
    for( int i = 0; i < lanes; i++ )
    {
        delete starters[i];
    }

    csis.close();
    return 0;
}