#include <iostream>
#include <stdio.h>

using namespace std;

int main( int argc, char* argv[] )
{
    //turn on buffered output for cout
    cout.unsetf( ios::unitbuf );

    //using printf and cout in the same program is bad practice...
    //...here it is for the sake of learning flush()

    //without flush, the printf statements will execute first. 
    //cout does not execute because the buffer has not flushed.
    //only prints when destructor is called.
    
    printf( "Print this first.\n" );
    cout << "Print this second.\n";
    cout.flush();
    printf( "Print this third.\n" );
    cout << "Print this last.\n";
    cout.flush();
    return 0;

}