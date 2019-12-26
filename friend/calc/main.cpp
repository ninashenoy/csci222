///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <cmath>
#include <iostream>

#include "calc_test.h"

using namespace std;

// this object gets constructed before main function is called
// this makes sense
CalcTest ct;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    CalcTest calc_test;
    calc_test.test_all();

    {
        CalcTest ctest;
        ctest.test_all();
        // ctest gets destroyed as it goes out of scope
    }

    return 0;
    // calc_test gets destroyed as it function main terminates
}