///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _EMPLOYEEENG_H_
#define _EMPLOYEEENG_H_

#include <string>

#include "Employee.h"

///////////////////////////////////////////////////////////////////////////////
class EmployeeEng: public Employee
{
    private:

    public:
        EmployeeEng( std::string name, u_int32_t ID );
        ~EmployeeEng();

        virtual int ComputePay();
};

#endif