#include "ReverseString.h"

ReverseString& ReverseString::operator= ( const ReverseString& src )
{
    char* new_buf = new char[src.length];
    strcpy( new_buf, src.buf );

    reset();
    length = src.length;
    buf = new_buf;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
ReverseString ReverseString::operator~ ()
{
    ReverseString temp;
    temp.length = getLength() + 1;
    temp.buf = new char[temp.length];

    int idx = getLength()-1;
    for( int i = 0; i < getLength(); i++ )
    {
        temp.buf[i] = buf[idx];
        idx--;
    }
    return temp;
}