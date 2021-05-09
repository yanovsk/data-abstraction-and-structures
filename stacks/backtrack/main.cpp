#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "StackADT.h"

void printInfo();
//declaring function that reads file and processes it 
void readFile(string filename);

int main() {
  string filenames[] = {"numbers1.txt", "numbers2.txt", "numbers3.txt", ""};
  
  printInfo();
  for (int i = 0; filenames[i] != ""; i++)
  {
    // call a function to process the input file using a stack
    readFile(filenames[i]);
  }
  cout << endl;

  return 0;
}

//this function reads text file and processes every number 
//from the file according to the intsructions
void readFile(string filename) {
  Stack<int> s; //declaring stack object
  int item;

  ifstream fin(filename);
  
  cout << "\n\nInput File: " << filename;
  
  if(!fin.is_open()) //stop function if file can't be opened 
    exit(EXIT_FAILURE);

  //execute loop while there are integers left in the file 
  while(fin >> item) { 

    if(item > 1)   //pushing positive numbers onto stack
      s.push(item);

    if(item == 0)  //displaying the length of stack if read 0
      cout << "\nCount: " << s.getLength();

    //removing value/s from stack if negative integer is read
    if(item < 0) {
       //if absolute value of number is less than length of stack
      if(abs(item) < s.getLength()) {
        cout << "\nStack: ";
        //calling pop() as many times as the absolute value of number read
        for(int i = 0; i < abs(item); i++) {
          cout << s.pop() << " ";
        }
      //if ansolute value is more that number of elements in stack 
      } else {
        cout << "\nError";
      }
    }

    if(item == 1) {
      //if stack is not empty output top node
      if(!s.isEmpty())
        cout << "\nTop: " << s.peek();
      else
        cout << "\nTop: Empty";
    }
  }
  
  //after all numbers from file were processed
  //if stack has nodes in it
  if(!s.isEmpty()){
    cout << "\nStack: ";
    //pop each element and display it until no elements left
    while(!s.isEmpty()) { 
      cout << s.pop() << " ";
    }
  //if stack is empty output the message
  } else {
    cout << "\nStack: Empty";
  }
  //closing input file
  fin.close();
}

void printInfo()
{
   cout << " ~*~ Project: Stack ADT ~*~ ";
}