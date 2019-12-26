#include "string.cpp"

int main( int argc, char* argv[] )
{
    String s1, s2( "Hello, world." ), s3( "Nina" );

    s1 = s2;
    s3.concat(s2);
    s1.display();
    s2.display();
    s3.display();

    return 0;
}