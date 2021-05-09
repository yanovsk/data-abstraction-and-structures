// Specification file for the ListNode class
// IDE: vsc
// Written By: Dimitri Yanovskyi
#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include "Student.h"

using std::string;

class ListNode
{
private:
    Student stu;        // store data
    ListNode *next;    // a pointer to the next node in the list

public:
    //Constructor
    ListNode(const Student &dataIn, ListNode *next = NULL){ stu = dataIn;}
    
    // setters
    // set a pointer to a pointer in the node
    void setNext(ListNode* nextPtr) {next = nextPtr;}

    // getters
    // return pointer in the node
    ListNode *getNext() const {return next;}
    Student getData() {return stu;} // return stu object in the listnode
};

#endif
