///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    char charName[50];
    strcpy( charName, "nina shenoy" );
    
    int intArray[10];
    for( int i = 0; i < 10; i++ )
    {
        intArray[i] = i;
    }
    memset( intArray, 0, 5 );

    char str1[] = "Hello";
    char str2[] = "World";
    memcpy( str1, str2, sizeof(str2) );
    cout << str1 << endl;

    char str3[] = "This is a string";
    char* sptr;
    char* sptrn;
    sptr = strstr( str3, "string" );
    sptrn = strstr( str3, "pineapple" );
    cout << sptr << endl;
    //cout << sptrn << endl;

    char* buffer;
    buffer = (char*) malloc ( 10*sizeof(char) );
    if( buffer == NULL ) exit(1);
    for( int i = 0; i < sizeof(buffer); i++ )
    {
        buffer[i] = 'A' + i;
    }
    for( int i = 0; i < sizeof(buffer); i++ )
    {
        cout << buffer[i] << endl;
    }
    free( buffer );

}