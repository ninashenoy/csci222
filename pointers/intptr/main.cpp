///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int main( int argc, char* argv[] )
{
    // new will allocate a block memory (400 bytes) and call a constructor
    int* ptr = nullptr;
    ptr = new int[100];

    //set values in the int array
    for( int i = 0; i < 100; i++ )
    {
        ptr[i] = i;
        printf("The address of p[%d] = %p, the contents = %d\n", i, &ptr[i], ptr[i]);

    }

    // we use delete[] instead of a forloop because we are deallocating an array
    // ... of objects allocated by new
    delete [] ptr;
    return 0;
}