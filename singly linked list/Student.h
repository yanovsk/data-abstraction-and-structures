// Specification file for the Student class
// Modified by:
// IDE:

#ifndef STUDENT_H
#define STUDENT_H

//using namespace std;  //<==== This statement
// in a header file of a complex project could create
// namespace management problems for the entire project
// (such as name collisions).
// Do not write namespace using statements at the top level in a header file!
// Got it! - DY

using std::string;

class Student
{
private:
    double gpa;
    string name;
    
public:
    Student() {name = ""; gpa = -1;}  // Constructor
    Student(double g, string n) {name = n; gpa = g;}  // Overloaded Constructor
    
    // Setters and getters
    void setName(string n) {name = n;}
    void setGpa(double g) {gpa = g;}
    string getName() const {return name;}
    double getGpa() const {return gpa;} 
};
#endif
