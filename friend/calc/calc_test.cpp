///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

// std lib includes
#include <iostream>
#include <assert.h>

// app includes
#include "calc_test.h"
#include "calc.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////
// constructor
CalcTest::CalcTest()
{

}

///////////////////////////////////////////////////////////////////////////////
// destructor
CalcTest::~CalcTest()
{

}

///////////////////////////////////////////////////////////////////////////////
// uses function overloading to be able to add doubles and integers
void CalcTest::test_add()
{
    Calc calc;

    int i = calc.add( 10, 20 );
    cout << "Testing add( 10, 20 ), output = " << i << endl;
    //continues if expression is true
    assert( i == 30 );

    double d = calc.add( 10.00, 20.00 );
    cout << "Testing add( 10.00, 20.00 ), output = " << d << endl;
    assert( d == 30.00 );


    i =  calc.add( (int)10.90, (int)20.70 );
    cout << "Testing add( 10.90, 20.70 ), output = " << i << endl;
    assert( i == 30 );

    d = calc.add( (double)10, (double)20 );
    cout << "Testing add( 10, 20 ), output = " << d << endl;
    assert( d == 30.0 );
}

///////////////////////////////////////////////////////////////////////////////
// uses function overloading to be able to subtract doubles and integers
void CalcTest::test_sub()
{
    Calc calc;

    int i = calc.sub( 10,20 );
    cout << "Testing sub( 10, 20 ), output  = " << i << endl;
    //continues if expression is true
    assert( i == -10 );

    double d = calc.sub( 10.0, 20.0 );
    cout << "Testing sub( 10.0, 20.0 ), output  = " << d << endl;
    assert( d == -10.0 );
}

///////////////////////////////////////////////////////////////////////////////
// uses function overloading to be able to multiply doubles and integers
void CalcTest::test_mul()
{
    Calc calc;

    int i = calc.mul( 10, 20 );
    cout << "Testing mul( 10, 20 ), output = " << i << endl;
    //continues if expression is true
    assert( i == 200 );

    double d = calc.mul( 10.0, 20.0 );
    cout << "Testing sub( 10.0, 20.0 ), output  = " << d << endl;
    assert( d == 200.0 );
}

///////////////////////////////////////////////////////////////////////////////
// uses function overloading to be able to divide doubles and integers
void CalcTest::test_div()
{
    Calc calc;

    int i = calc.div( 10, 20 );
    cout << "Testing div( 10, 20 ), output = " << i << endl;
    //continues if expression is true
    assert( i == 0 );
    double d = calc.div( 10.0, 20.0 );
    cout << "Testing div( 10.0, 20.0 ), output = " << d << endl;
    assert( d = 0.5 );

}

///////////////////////////////////////////////////////////////////////////////
// tests all operator functions
void CalcTest::test_all()
{
    test_add();
    test_sub();
    test_mul();
    test_div();
}
