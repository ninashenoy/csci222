#include <iostream>
#include <string.h>

const int MAX = 80;

using namespace std;

class String 
{
    private:
        char str[MAX];
    public:
        String();
        String( const char* s );
        void display();
        void concat( String s );
};

String::String()
{
    str[0] = '\0';
}

String::String( const char* s )
{
    strcpy( str, s );
}

void String::display()
{
    cout << str << endl;
}

void String::concat( String s )
{
    if( strlen(str) + strlen(s.str) < MAX )
    {
        strcat( str, s.str );
    }
    else
    {
        cout << "The string is too long." << endl;
    }
}