///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Holding.h"

///////////////////////////////////////////////////////////////////////////////

//Recording is a class derived from Holding
class Recording : public Holding
{
    private:
        char* _performer;
        char* _format;


    public:
        Recording( const char* title, int callNum, const char* format,
                   const char* performer );
        Recording( const Recording& src );
        ~Recording();

        virtual void print();

};