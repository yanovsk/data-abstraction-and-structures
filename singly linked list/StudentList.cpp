// Implementation file for the Student List class
// Modified by:
// IDE:

#include <iostream>         // For cout  and NULL
#include <string>
#include "StudentList.h"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
StudentList::StudentList()
{
    head = new ListNode(Student()); // head points to the sentinel node
    head->setNext(NULL);
    count = 0;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************

void StudentList::displayList() const
{
    ListNode *pCur;  // To move through the list
    
    // Position pCur: skip the head of the list.
    pCur = head->getNext();
    
    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        // Display the value in this node.
        cout << pCur->getData().getGpa() << " " << pCur->getData().getName() << endl;
        
        // Move to the next node.
        pCur = pCur->getNext();
    }
    cout << endl;
}

//**************************************************
// The insertNode function inserts a node with
// stu copied to its stu data member.
//**************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new ListNode(dataIn);
   
    // Initialize pointers
    pPre = head;
    pCur = head->getNext();
   
    // Find location: skip all nodes whose name is less than dataIn's name
    while (pCur != NULL && pCur->getData().getName()< dataIn.getName())
    {
        pPre = pCur;
        pCur = pCur->getNext();
    }
    
    // Insert the new node between pPre and pCur
    pPre->setNext(newNode);
    newNode->setNext(pCur);
    
    // Update the counter
    count++;
}

//**************************************************
// The deleteNode function searches for a node
// with target as its value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool StudentList::deleteNode(string target)
{
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;        // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pPre = head;
    pCur = head->getNext();
    // Find node containing the target: Skip all nodes whose name is less than the target
    while (pCur != NULL && pCur->getData().getName() < target)
    {
        pPre = pCur;
        pCur = pCur->getNext();
    }
    
    // If found, delete the node
    if (pCur != NULL && pCur->getData().getName() == target)
    {
        pPre->setNext(pCur->getNext());
        delete pCur;
        deleted = true;
        count--;
    }
    return deleted;
    
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
StudentList::~StudentList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node
    
    // Position nodePtr at the head of the list.
    pCur = head->getNext();
    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->getNext();
        // Delete the current node
        delete pCur;
        
        // Position pCur at the next node.
        pCur = pNext;
    }
    delete head; // delete the sentinel node
}

