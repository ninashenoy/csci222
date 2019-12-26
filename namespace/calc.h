///////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////


#ifndef _CALC_H_
#define _CALC_H_

// namespaces are collection of classes, functions and variables

namespace IntCalc
{
    // global variable in namespace
    // we have to extern it and define it in the cpp file otherwise compiler 
    // will complain of multiple definitions
    extern int result;
    

    ///////////////////////////////////////////////////////////////////////////////
    class Calc
    {
        private:
            int result;

        public:
            Calc();
            ~Calc();

            int add( int a, int b );

            int mul( int a, int b );

            int div( int a, int b );

            int sub( int a, int b );
    };
}

namespace DoubleCalc
{
    // global variable in namespace
    // we have to extern it and define it in the cpp file otherwise compiler 
    // will complain of multiple definitions
    extern double result;

    ///////////////////////////////////////////////////////////////////////////////
    class Calc
    {
        private:
            int result;

        public:
            Calc();
            ~Calc();

            double add( double a, double b );

            double mul( double a, double b );

            double div( double a, double b );

            double sub( double a, double b );
    };
}

#endif
