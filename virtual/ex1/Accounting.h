///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////


#ifndef _ACCOUNTING_H_
#define _ACCOUNTING_H_

#include "Employee.h"

///////////////////////////////////////////////////////////////////////////////
class Accounting: public Employee
{
private:
    bool _Certified;

public:
    Accounting( int rate, bool certified );
    Accounting( const Accounting& emp );
    ~Accounting();

    virtual int ComputePay();
    virtual bool USAACertified() { return _Certified; };
};


#endif