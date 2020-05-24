///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main( int argc, char* argv[] )
{
    //create char array of size 26
    //ptr will point to char[0] (contains the address of char[0])
    char* ptr = new char[26];
    for( int i = 0; i < 26; i++ )
    {
        ptr[i] = 'A'+i;
        cout << ptr[i] << endl;
    }
    delete [] ptr;
    return 0;
}