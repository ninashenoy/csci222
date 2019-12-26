/////////////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _CALC_H
#define _CALC_H

class CalcTest;
/////////////////////////////////////////////////////////////////////////////////
class Calc
{
    private:

    public:
        Calc();
        ~Calc();

        int add( int a, int b );
        double add( double a, double b );

        int sub( int a, int b );
        double sub( double a, double b );


        int mul( int a, int b );
        double mul( double a, double b );

        int div( int a, int b );
        double div( double a, double b );

        friend class CalcTest;

};
#endif