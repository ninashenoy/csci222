///////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////

#include "calc.h"

namespace IntCalc
{
    int result = 10;
    
    ///////////////////////////////////////////////////////////////////////////////
    Calc::Calc()
    {
        result = 0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    Calc::~Calc()
    {
    }

    ///////////////////////////////////////////////////////////////////////////////
    int Calc::add( int a, int b )
    {
        result = a + b;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    int Calc::mul( int a, int b )
    {
        result = a * b;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    int Calc::div( int a, int b )
    {
        result = a / b;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    int Calc::sub( int a, int b )
    {
        result = a - b;
        return result;
    }
// namespace end IntCalc
}

namespace DoubleCalc
{
    double result = 10.0;

    ///////////////////////////////////////////////////////////////////////////////
    Calc::Calc()
    {
        result = 0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    Calc::~Calc()
    {
    }

    ///////////////////////////////////////////////////////////////////////////////
    double Calc::add( double a, double b )
    {
        result = a + b;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    double Calc::mul( double a, double b )
    {
        result = a * b;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    double Calc::div( double a, double b )
    {
        result = a / b;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    double Calc::sub( double a, double b )
    {
        result = a - b;
        return result;
    }
// namespace end DoubleCalc
}