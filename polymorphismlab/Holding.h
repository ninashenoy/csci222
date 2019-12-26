///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

///////////////////////////////////////////////////////////////////////////////

//This class is an abstract base class becuse it cannot be instantiated.
class Holding
{
    protected:
        char* _title;
        int _callNum;

    public:
        Holding( const char* title, int callNum );
        Holding( const Holding& src );
        ~Holding();

        //a pure virtual function has no body
        virtual void print() = 0;

};