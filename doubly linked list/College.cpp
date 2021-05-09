// Implementation file for the College class
// Written By: A. Student
// Changed By:
// IDE: Xcode


#include <iostream>
#include <iomanip>
#include <string>

#include "College.h"

using namespace std;

//**************************************************
// Constructor
//**************************************************
College::College()
{
    rank = -1;
    code = "";
    name = "";
    cost = -1;
}

//**************************************************
// Overloaded Constructor
//**************************************************
College::College(int rk, string cd, string nm, int ct)
{
    rank = rk;
    code = cd;
    name = nm;
    cost = ct;
}

//***********************************************************
// Displays the values of the College object member variables
// on one line (horizontal display)
//***********************************************************
void College::hDdisplay() const
{
    cout << left;
    cout << " " << setw(4) << code << "  ";
    cout << " " << setw(2) << rank << "  ";
    cout << " " << setw(27)<< name << "  ";
    cout << right;
    cout << " " << setw(7) << cost << " ";
    cout << left << endl;
}

//***********************************************************
// Displays the values of the College object member variables
// one per line (vertical display)
//***********************************************************
void College::vDisplay() const
{
    cout << "              Rank: " << rank << endl;
    cout << "       School Name: " << name << endl;
    cout << "Cost of Attendance: $" << cost << endl;
}

// overloaded operators
/* Write your code here to define the following oveloaded operator:
    - the stream insertion operator ( << )
 */

ostream& operator<<(ostream &out, const College &c)
{
  out << left;
  out << " " << setw(4) << c.code << "  ";
  out << " " << setw(2) << c.rank << "  ";
  out << " " << setw(27)<< c.name << "  ";
  out << right;
  out << " " << setw(7) << c.cost << " ";
  out << left << endl;
  
  return out;
}
