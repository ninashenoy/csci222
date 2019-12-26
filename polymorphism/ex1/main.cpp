#include "student.cpp"
#include <stdio.h>
int main()
{
    Person* persPtr[100];
    Student *studPtr;
    Professor *profPtr;
    int n = 0;
    char choice;

    do {
        cout << "Enter student or professor (s/p): ";
        cin >> choice;
        if( choice == 's')
        {
            studPtr = new Student;
            studPtr->setName();
            studPtr->setGPA();
            persPtr[n++] = studPtr;
        }
        else if( choice == 'p')
        {
            profPtr = new Professor;
            profPtr->setName();
            profPtr->setNumPubs();
            persPtr[n++] = profPtr;
        }
        else
        {
            cout << "Invalid Choice." << endl;
        }
        cout << "Enter another (y/n): ";
        cin >> noskipws >> choice;
    } while( choice == 'y' );

    for( int i = 0; i < n; i++ )
    {
        persPtr[i]->getName();
        if( persPtr[i]->isOutstanding() )
        {
            cout << "THIS PERSON IS OUTSTANDING!!!" << endl;
        }
    }
    return 0;
}