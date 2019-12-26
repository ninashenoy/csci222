///////////////////////////////////////////////////////////////////////////////
// Nina Shenoy
// 012053716
// C/C++ for Visual Studio
// Linux OS
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "Library.h"

using namespace std;

#define MAX_SIZE 40
#define NUM_HOLDINGS 5

ofstream csis;
///////////////////////////////////////////////////////////////////////////////

int main()
{
    //create array of 5 pointers to Holding
    Holding* holdings[NUM_HOLDINGS];
    //create Library object
    Library lib;

    //open csis.txt
    csis.open("csis.txt");

    cout << "Enter holdings to be stored in a list: " << endl << endl;
    csis << "Enter holdings to be stored in a list: " << endl << endl;


    //create new holdings for array holdings
    for( int i = 0; i < NUM_HOLDINGS; i++ )
    {
        holdings[i] = lib.newHolding();
    }

    cout << "Here are the holdings: " << endl << endl;
    csis << "Here are the holdings: " << endl << endl;
    //print each object in holdings
    for( int i = 0; i < NUM_HOLDINGS; i++ )
    {
        holdings[i]->print();
    }
    csis.close();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
Library::Library()
{
    if( hptr != nullptr )
        hptr = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
Library::~Library()
{
    //nothing to free
}
///////////////////////////////////////////////////////////////////////////////
Holding* Library::newHolding()
{
    //reset buffers that hold data
    memset( title, 0, MAX_SIZE );
    memset( author, 0, MAX_SIZE );
    memset( performer, 0, MAX_SIZE );
    memset( format, 0, MAX_SIZE );
    
    //choose type of holding to enter
    cout << "Enter B for Book, R for Recording: ";
    csis << "Enter B for Book, R for Recording: ";

    cin >> holdingChoice;
    csis << holdingChoice << endl;
    cin.ignore();
    //enter data for book
    if( holdingChoice == 'B' )
    {
        cout << "Enter book title: ";
        csis << "Enter book title: ";

        cin.getline( title, MAX_SIZE );
        csis << title << endl;;

        cout << "Enter author: ";
        csis << "Enter author: ";

        cin.getline( author, MAX_SIZE );
        csis << author << endl;

        cout << "Enter call number: ";
        csis << "Enter call number: ";

        cin >> callNumber;
        csis << callNumber << endl;

        //holding pointer points to object of type Book
        hptr = new Book( title, callNumber, author );
    }
    //enter data for recording
    else if( holdingChoice == 'R' )
    {
        cout << "Enter recording title: ";
        csis << "Enter recording title: ";

        cin.getline( title, MAX_SIZE );
        csis << title << endl;

        cout << "Enter performer: ";
        csis << "Enter performer: ";

        cin.getline( performer, MAX_SIZE );
        csis << performer << endl;

        cout << "Enter format: (M)P3, (W)AV, (A)IFF: ";
        csis << "Enter format: (M)P3, (W)AV, (A)IFF: ";

        cin >> formatChoice;
        csis << formatChoice << endl;
        cin.ignore();
        if( formatChoice == 'M' )
        {
            strcpy( format, "MP3" );
        }
        else if( formatChoice == 'A')
        {
            strcpy( format, "AIFF" );
        }
        else if( formatChoice == 'W' )
        {
            strcpy( format, "WAV" );
        }
        else
        {
            cout << "invalid format!!!" << endl;
            csis << "invalid format!!!" << endl;

        }

        cout << "Enter call number: ";
        csis << "Enter call number: ";

        cin >> callNumber;
        csis << callNumber << endl;

        //holding pointer points to object of type Recording
        hptr = new Recording( title, callNumber, format, performer );
    }
    else
    {
        cout << "invalid holding!!! << endl";
        csis << "invalid holding!!! << endl";

    }

    //return pointer to Holding
    return hptr;
    
}