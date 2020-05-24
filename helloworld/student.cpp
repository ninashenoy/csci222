///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#include "student.h"

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// constructors have no return value
student::student( const char* first_name,
                    const char* last_name,
                    unsigned int id,
                    unsigned int age )
{
    //first, let us use set_defaults to set every character in the first name buffer with null 
    //sizeof(_first_name) will return the length of the buffer, which is 32
    //strlen(_first_name) will return 0 because it will count the number
    //of characters until it hits null character
    set_defaults();
    strncpy( _first_name, first_name, MAX_FIRST_NAME_LEN-1 );
    strncpy( _last_name, last_name, MAX_LAST_NAME_LEN-1 );
    _id = id;
    _age = age;
    return;
}
    
///////////////////////////////////////////////////////////////////////////////
student::student(void)
{
    set_defaults();
    return;
}

///////////////////////////////////////////////////////////////////////////////
void student::set_defaults(void)
{
    //memset takes a pointer of the starting address of what you want to set,
    //the value to set it to, and how many bytes from the starting address
    //to set it to.
    //here we are setting _first_name and _last_name to null for 32 bytes
    memset( _first_name, 0, sizeof(_first_name) );
    memset( _last_name, 0, sizeof(_last_name) );
    _id = 0;
    _age = 0;
    return;
}

///////////////////////////////////////////////////////////////////////////////
//a class can only have 1 destructor, does not have a return value.
//since we are not allocating any resourcess, memory, files.....
//there is nothing to do in the destructor. 
student::~student(void)
{
    return;
}

///////////////////////////////////////////////////////////////////////////////
void student::print( void )
{
    printf( "First Name: %s\n", _first_name );
    printf( "Last Name: %s\n", _last_name );
    printf( "ID: %d\n", _id );
    printf( "Age: %d\n", _age);
    return;
}
    
