#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
class Person{
    protected:
        char name[40];
    public:
        void setName(){
            cout << "Enter name: ";
            cin >> name; 
        }
        void getName(){
            cout << "Name is " << name << endl;
        }
        virtual int isOutstanding() = 0;
};

///////////////////////////////////////////////////////////////////////////////
class Student : public Person {
    private:
        float gpa;
    public:
        void setGPA() {
            cout << "Enter students gpa: ";
            cin >> gpa;
        }
        virtual int isOutstanding() {
            return gpa > 3.5;
        }
};

///////////////////////////////////////////////////////////////////////////////
class Professor : public Person {
    private:
        int numPubs;
    public:
        void setNumPubs() {
            cout << "Enter number publications: ";
            cin >> numPubs;
        }
        virtual int isOutstanding() {
            return numPubs > 100;
        }
};

