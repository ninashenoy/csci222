///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
void pass_value_int( int a );
void test_pass_by_int( void );

void pass_by_ptr_int( int* p );
void test_pass_by_ptr_int( void );

void ptr_to_ptr_int( int** _ip );
void test_ptr_to_ptr_int( void );

void pass_by_ref_int( int& val );
void test_pass_by_ref_int( void );

void pass_by_ref_int_ptr( int*& val );
void test_pass_by_ref_int_ptr( void );

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
     //test_pass_by_int();
     //test_pass_by_ptr_int();
     //test_ptr_to_ptr_int();
     //test_ptr_to_ptr_int_2();
     //test_pass_by_ref_int();
     test_pass_by_ref_int_ptr();
     return 0;
}

///////////////////////////////////////////////////////////////////////////////
void pass_by_ref_int( int& val )
{
     val = val*10;
     return;
}

///////////////////////////////////////////////////////////////////////////////
void test_pass_by_ref_int( void )
{
     int value = 5;
     pass_by_ref_int( value );
     return;
}

///////////////////////////////////////////////////////////////////////////////
void ptr_to_ptr_int_2( int** pptr )
{
     //pptr has a different address than what is passed in, since a copy is created
     // but the contents of pptr is the address of p from test function which in turn
     // points to i. After malloc we will point to a new address and not i anymore
     // allocate space to hold one integer pointer
     *pptr = (int*)malloc( sizeof(int*) * 1 );
}

///////////////////////////////////////////////////////////////////////////////
void test_ptr_to_ptr_int_2( void )
{
     //the size of a pointer in a 64-bit system is 8 bytes
     int i = sizeof(int**);
     i = sizeof(int*);
 
     int* p = NULL;
     int* k = NULL;
     //pointers k and p will point to i since they have the same contents 
     // ie the address of i
     k = &i;
     p = &i;

     cout << "value of i: " << i << " Address of i: " << &i << endl;
     cout << "contents of p: " << p << " Address of p: " << &p << endl;
     cout << "contents of k: " << k << " Address of k: " << &k << endl;

     //creates a pointer to a pointer, set to null
     int** pp = NULL;
     //contents of pp become the address of p, so pp points to p which...
     //...points to i
     pp = &p;
     //pp increments by 8 since the size of a pointer is 8 bytes
     pp++;
     
     //set pp back to the address of p
     pp = &p;

     ptr_to_ptr_int_2(pp);

     cout << "value of i after: " << i << " Address of i: " << &i << endl;
     cout << "contents of p after: " << p << " Address of p: " << &p << endl;
     cout << "contents of pp after: " << pp << " Address of pp: " << &pp << endl;

     return;
}

///////////////////////////////////////////////////////////////////////////////
void ptr_to_ptr_int( int** _tp )
{
     //_tp has a different address than what is passed in, but points to the...
     //...same variable. so changed made to tp are also made to the variable.
    *(*_tp) = 100;
    return;
}

///////////////////////////////////////////////////////////////////////////////
int myS = 100;
void pass_by_ptr_int( int* p )
{
    *p = 5;

    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The value of int variable is: " << *p << endl;

    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The address of the int variable is: " << &p << endl;

     //you cannot change what the pointer is pointing to because we have created...
     //...a copy of the pointer. In the test function, it will still point to the...
     //...original address. We can change the value of what it points to.
     p = &myS;
     return;
}

///////////////////////////////////////////////////////////////////////////////
void test_pass_by_ptr_int( void )
{
    int value = 5;

    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The value of int variable before:: " << value << endl;

    cout << __FILE__<< "::" << __LINE__  << "::" << __FUNCTION__ 
         << "::Address of int variable value is: " << &value << endl;
    
    int* p = &value;
    pass_by_ptr_int( p );

    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The value of int variable after: " << value << endl;
    return;

}

///////////////////////////////////////////////////////////////////////////////
void test_pass_by_int( void )
{
    int value = 5;

    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The value of int variable before:: " << value << endl;

    cout << __FILE__<< "::" << __LINE__  << "::" << __FUNCTION__ 
         << "::Address of int variable value is: " << &value << endl;
    
    pass_value_int( value );

    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The value of int variable after: " << value << endl;
    return;
}

///////////////////////////////////////////////////////////////////////////////
void pass_value_int( int a )
{
    a = 10;
    
    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The value of int variable is: " << a << endl;

    cout << __FILE__ << "::" << __LINE__ << "::" <<__FUNCTION__
         << "::The address of the int variable is: " << &a << endl;
    return;
}

///////////////////////////////////////////////////////////////////////////////
int myK = 1000;
void pass_by_ref_int_ptr( int*& val )
{
     *val = 100;
     //here, you can change the address of what the pointer is pointing to...
     //...not just the contents.
     val = &myK;
     return;

}

///////////////////////////////////////////////////////////////////////////////
void test_pass_by_ref_int_ptr( void )
{
     int value = 25;
     int* ptr = &value;
     pass_by_ref_int_ptr( ptr );
     // this will change the vlue of myK to 1001
     *ptr = *ptr + 1;
     return;
}