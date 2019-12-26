#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student
{
   private:
       char* _name;
       int _id;
       static int _numStudents;

   public:
       Student( const char* name );
       ~Student();

       void setID( int id );
       char* getName();
       static int getNumStudents();
};
#endif
