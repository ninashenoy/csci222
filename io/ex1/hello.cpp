#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
    int age;
    //cout sends data to the monitor via <<
    cout << "please enter your age";
    //cin takes input from the keyboard via >> and places it into age
    cin >> age;
    //endl generats a linefeed
    cout << "Hello World! I am " <<age<< "today" << endl;
}