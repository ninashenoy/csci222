///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __STUDENT_H__
#define __STUDENT_H__


//Constants defined below
#define MAX_FIRST_NAME_LEN 32
#define MAX_LAST_NAME_LEN 32

///////////////////////////////////////////////////////////////////////////////
// we are defining a class 'student'
class student
{
    //anything declared in the private section below is accessible only w/in
    //the class. all member functions of the class have access to private
    //or any other kind of variables.
private:
    char _first_name[MAX_FIRST_NAME_LEN]; //32 bytes
    char _last_name[MAX_LAST_NAME_LEN]; //32 bytes
    unsigned int _id; //4 bytes
    unsigned int _age; //4 bytes

    //this function will set all class variables to default values
    //we dont want anybody outside the class to call this function
    //that is why it is declared as private
    void set_defaults();



public:
    //public methods and variables are accessible by the external
    //world including methods of the class
    //you can have many constructors in a class. below are 2 examples. they
    //need to differ in the parameters that are passed to them.

    student( const char* first_name,
             const char* last_name,
             unsigned int id,
             unsigned int age );
    
    student();
    
    //a class can only have 1 destructor, does not have a return value.
    ~student();

    //print function takes no parameters and has no return value
    //prints the student object
    void print( void );
    


protected:
    //protected variables or functions are accessible only by objects that are
    //derived from the student class and not by the external world

};

#endif
