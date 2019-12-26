///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <string>

///////////////////////////////////////////////////////////////////////////////
class Student
{
    public:
        enum Major
        {
            Biology,
            Math,
            Psychology,
            History
        };
    private:
        Major _major;
        std::string _first_name;
        std::string _last_name;
        double _GPA;
    public:
        Student( std::string firstname, std::string lastname,
                Major major, double gpa );
        ~Student();

        std::string getFullName();
        double getGPA();
        Major getMajor();
        void printInfo();
};