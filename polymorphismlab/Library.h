///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Recording.h"
#include "Book.h"
#include "Holding.h"

#define MAX_SIZE 40
///////////////////////////////////////////////////////////////////////////////
class Library
{
    private:
        Holding* hptr = nullptr;
        char title[MAX_SIZE];
        char author[MAX_SIZE];
        char performer[MAX_SIZE];
        char format[MAX_SIZE];
        char holdingChoice;
        char formatChoice;
        int holdingCount;
        int callNumber;
    
    public:
        Library();
        ~Library();
        Holding* newHolding();

};
