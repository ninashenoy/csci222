///////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////

#include "calc.h"

// global
int result = 1000;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    // variable local to function
    int result = 10;

    // change value of the local variable in this function
    result = 10;

    // change value of the global variable declared outside the function to 2000
    // note the use of scope resulution operator
    ::result = 2000;

    // change value of result declared in namspace IntCalc
    IntCalc::result = 1000;
    //Create calc object from IntCalc namespace
    IntCalc::Calc calc;
    calc.add( 10, 10 );

    // change value of result declared in namspace DoubleCalc
    DoubleCalc::result = 1000.90;
    DoubleCalc::Calc d_calc;
    d_calc.add( 10.0, 20.0 );
}
