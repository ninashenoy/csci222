///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

///////////////////////////////////////////////////////////////////////////////
class Employee
{
    public:
        enum EmployeeType 
        { 
            Engineering,
            Admin, 
            Accounting, 
        };

    private:
        EmployeeType    _type;
        std::string     _name;
        u_int32_t       _ID;

    public:
        Employee(EmployeeType type,
                 std::string name,
                 u_int32_t ID );

        ~Employee();

        EmployeeType GetType();

        std::string GetName();

        u_int32_t GetID();

        void PrintInfo();

        virtual int ComputePay();
};

#endif
