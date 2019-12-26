#include <iostream>
#include <string.h>

using namespace std;

class Beta;

class Alpha
{
    private:
        char* s1;
    public:
        Alpha()
        {
            s1 = new char( strlen("Testing")+1);
            strcpy( s1, "Testing" );
        }
        friend void show(Alpha a, Beta b);
};

class Beta
{
    private:
        char* s2;
    public:
        Beta()
        {
            s2 = new char( strlen("one, two, three")+1);
            strcpy( s2, "one, two, three" );
        }
        friend void show( Alpha a, Beta b );
};

///////////////////////////////////////////////////////////////////////////////
void show( Alpha a, Beta b )
{
    cout << a.s1 << b.s2;
}

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    Alpha a;
    Beta b;
    show( a, b );
    return 0;
}
