///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "student.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    Student* ptr[4];
    ptr[0] = new Student( "Nina", "Shenoy", Student::Major::Biology, 4.4 );
    ptr[1] = new Student ( "Leo", "Shenoy", Student::Major::Math, 4.0 );
    ptr[2] = new Student( "Shadow", "Shenoy", Student::Major::History, 3.8 );
    ptr[3] = new Student( "Jane", "Doe", Student::Major::Psychology, 3.9 );

    for( Student* student : ptr )
    {
        student->printInfo();
    }

    for( Student* student : ptr )
    {
        delete student;
    }

    return 0;

}