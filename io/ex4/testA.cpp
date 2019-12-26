#include <iostream>
#include <fstream>
#include "testA.h"

using namespace std;

//this statement is only included in the file with the main function
ofstream csis;

int main( int argc, char* argv[] )
{
    int a = 3, b = 4, c = 5;

    //open csis.txt
    csis.open( "csis.txt" );

    cout << "All you need is love" << endl;
    csis << "All you need is love" << endl; //writes to csis.txt

    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    csis << "a = " << a << " b = " << b << " c = " << c << endl; //writes to csis.txt

    cout << 'A' << endl;
    csis << 'A' << endl;

    foo();

    cout << "Samantha" << endl; 
    csis << "Samantha" << endl; //writes to csis.txt

    //close csis.txt
    csis.close();
}