///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _EMPLOYEEACC_H_
#define _EMPLOYEEACC_H_

#include "Employee.h"

///////////////////////////////////////////////////////////////////////////////
class EmployeeAcc : public Employee
{
    private:

    public:
        EmployeeAcc( std::string name, u_int32_t ID );
        ~EmployeeAcc();

        virtual int ComputePay();
};

#endif