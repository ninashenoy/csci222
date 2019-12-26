///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

//system includes
#include <iostream>

//app includes
#include "Employee.h"
#include "Accounting.h"
#include "Engineering.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    //create array of 5 pointers to Employee base class
    Employee* ptrEmp[5];

    //pointer at ptrEmp[0], ptrEmp[1] points to Employee object
    //since Employee is the base class and is not derived from any other class 
    //and has 2 virtual functions, a vtable
    //and a vptr is created. The vtable will contain the pointers to the 
    //virtual functions of employee. For every instance of Employee, a new vptr
    //is created, however, there will always be one vtable.
    ptrEmp[0] = new Employee(10);
    ptrEmp[1] = new Employee(20);

    //pointer at ptrEmp[2], ptrEmp[3] points to Accounting object
    //since Accounting is derived from Employee, a vtable is created with the 2
    //virtual functions from Employee. Accounting has an overloaded virtual function
    //from Employee, so the pointer in the vtable is replaced by the pointer
    // to the function in Accounting. Accounting also has a virtual function that is not
    //in Employee, so this is added to the vtable, thus creating a vtable with 3 pointers.
    //There is one vtable for Accounting regardless of how many instances of Accounting there are.
    ptrEmp[2] = new Accounting(45, false);
    ptrEmp[3] = new Accounting(50, true);


    //pointer at ptrEmp[4] points to Engineering object
    //since Engineering is derived from Employee, a vtable is created with the 2
    //virtual functions from Employee. Engineering has overloaded virtual functions
    //from Employee, so the pointers in the vtable ar replaced by the pointer to the 
    //functions in Engineering. This created a vtable with 2 pointers (functions).
    //There is one vtable for Engineering regardless of how many instances of Engineering there are.

    ptrEmp[4] = new Engineering(60, true);

    //loop through ptrEmp[] and compute pay
    //print salary of employees
    for( int i = 0; i < sizeof(ptrEmp)/sizeof(Employee*); i++)
    {
        //calls ComputePay function based on the type of object being...
        //...pointed to, not the type of pointer
        ptrEmp[i]->ComputePay();

        //calls the Print() function based on the type of object being...
        //...pointed to, not the type of pointer
        ptrEmp[i]->Print();
    }
    return 0;
}
