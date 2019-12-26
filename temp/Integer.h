///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#include <sys/types.h>

class Integer
{
private:
    int32_t _value; 

public:
    Integer( int32_t value = 0 )
    {
        _value = value;
    }

    ~Integer()
    {

    }

    
    Integer( const Integer& ref )
    {
        _value = ref._value;
    }


    void Add( int value );
    void Add( const Integer& obj );
    void Add( char ch );
    void Add( double d );
    void Add( float f );

/*
    Integer operator +( const Integer& r_obj )
    {
        Integer t;
        t._value = r_obj._value + _value;
        return t; 
    }

    Integer operator +( int32_t r_value )
    {
        Integer t;
        t._value = r_value + _value;
        return t; 
    }
*/

   friend Integer operator+( const Integer& a, const Integer& b );
   friend Integer operator+( int32_t a, const Integer& b );
   friend Integer operator+( const Integer& a, int b );
   

};

Integer operator+( const Integer& a, const Integer& b )
{
    Integer t;
    t._value = a._value + b._value; 
    return t;
}

Integer operator+( int32_t a, const Integer& b )
{
    Integer t;
    t._value = a + b._value; 
    return t;
}

Integer operator+( const Integer& a, int32_t b )
{
    Integer t;
    t._value = a._value + b; 
    return t;
}

