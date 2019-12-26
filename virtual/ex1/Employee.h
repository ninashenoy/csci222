///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////


#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

///////////////////////////////////////////////////////////////////////////////
class Employee 
{
private:

public:
    Employee( int rate );
    Employee( const Employee& emp );
    ~Employee();

    virtual int ComputePay();
    virtual void Print();


protected:
    int _HourlyRate;
};

#endif