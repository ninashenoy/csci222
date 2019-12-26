#include <iostream>
#include <iomanip>

using namespace std;

class Alpha
{
    private:
        char ch;
    public:
        void init( char c )
        {
            ch = c;
        }
        Alpha increment()
        {
            ch++;
            return *this;
        }
        Alpha* whereAmI()
        {
            return this;
        }
        void print()
        {
            cout << ch;
        }
};
///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    Alpha a, b, c;
    a.init('a');
    b.init('b');
    c.init('c');
    a.print();
    cout << " is at " << a.whereAmI() << endl;
    a.print();
    cout << " is at " << a.whereAmI() << endl;
    b.print();
    cout << " is at " << b.whereAmI() << endl;
    c.print();
    cout << " is at " << c.whereAmI() << endl;
    c.increment().print();
    cout << " is at " << c.whereAmI() << endl;
    return 0;
}