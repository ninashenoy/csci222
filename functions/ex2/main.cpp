///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "EmployeeAcc.h"
#include "EmployeeAdmin.h"
#include "EmployeeEng.h"

const int MAXCOUNT = 3;

using namespace std;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    EmployeeEng* ptrEng[MAXCOUNT];
    EmployeeAdmin* ptrAdmin[MAXCOUNT];
    EmployeeAcc* ptrAcc[MAXCOUNT];

    for( int i = 0; i < MAXCOUNT; i++ )
    {
        std::string name = "eng_" + std::to_string(i+100);
        ptrEng[i] = new EmployeeEng( name, i+100 );

        name = "admin_" + std::to_string(i+200);
        ptrAdmin[i] = new EmployeeAdmin( name, i+200 );

        name = "acc_" + std::to_string(i+300);
        ptrAcc[i] = new EmployeeAcc( name, i+300 );
    }

    for( int i = 0; i < MAXCOUNT; i++ )
    {
        ptrEng[i]->PrintInfo();
        ptrAdmin[i]->PrintInfo();
        ptrAcc[i]->PrintInfo();
    }

    for( int i = 0; i < MAXCOUNT; i++ )
    {
        delete ptrEng[i];
        delete ptrAdmin[i];
        delete ptrAcc[i];
    }

    return 0;
}