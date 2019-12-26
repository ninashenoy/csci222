#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 20;

int main( int argc, char* argv[] )
{
    char buf1[MAX];
    char buf2[MAX];
    char buf3[MAX];

    cout << "Enter a string: ";
    //setw specifies the max number of characters the input buffer can accept
    cin >> setw(MAX) >> buf1;
    cout << "You entered " << buf1 << endl;
    

    cout << "Enter a string: ";
    //cin.get() allows us to read text containing blanks.=
    cin.get( buf2, MAX );
    cout << "You entered " << buf2 << endl;

    cout << "Enter a string: ";
    //this allows us to read strings with multiple lines depending on...
    //...the arguments that are passed in
    cin.get( buf3, MAX );
    cout << "You entered " << buf3 << endl;


    
}