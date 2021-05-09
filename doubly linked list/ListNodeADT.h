// Specification file for the ListNode class
// IDE:
// Written By:
#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
//#include "College.h"
// ^^^  not included here anymore

template <class T>
class ListNode
{
private:
    T data;      // store data
    ListNode *forw;    // a pointer to the next node in the list
    ListNode *back;    // a pointer to the previous node in the list
public:
    //Constructor
    ListNode(){forw = back = NULL;}
    ListNode(const T &dataIn, ListNode *forw = NULL, ListNode *back = NULL){ data = dataIn;}
    
    // setters
    void setNext(ListNode* nextPtr) {forw = nextPtr;}
    void setPrev(ListNode* backPtr) {back = backPtr;}

    // getters
    ListNode *getNext() const {return forw;}
    ListNode *getPrev() const {return back;}

    T getData() {return data;}

};


#endif
