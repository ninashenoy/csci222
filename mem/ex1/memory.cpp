///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>

#include "memory.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////
void input( char**& pptr, int& counter )
{
    const int MAX = 256;

    cout << "Enter String: " ;
    char buf[MAX];
    //end input with Ctrl-D
    while( !(cin >> buf).eof() )
    {
        //get exact amount of space
        char* temp = new char( strlen(buf)+1 );
        strcpy(temp, buf);

        //array of pointers grows dynamically
        char** temp_pptr = new char*[counter+1];
        for( int i = 0; i < counter; ++i )
        {
            temp_pptr[i] = pptr[i];
        }
        temp_pptr[counter++] = temp;
        //release old space for array of pointers
        delete [] pptr;
        //update pointer to current array of pointers
        pptr = temp_pptr;
        cout << "Next String: ";
    }
}

void output( char** pptr, int counter )
{
    const char QUOTE = '"';

    if( counter > 0 )
    {
        cout << "\nThe Strings:\n";
        for( int i = 0; i < counter; ++i )
        {
            cout << QUOTE << pptr[i] << QUOTE << '\n';
        }
    }
    else
    {
        cout << "Empty List\n";
    }
}

void release( char** pptr, int counter )
{
    for( int i = counter-1; i >= 0; --i )
    {
        delete [] pptr[i];
    }
    delete[] pptr;
}