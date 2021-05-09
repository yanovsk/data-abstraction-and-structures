#ifndef STACK_ADT
#define STACK_ADT
#include<iostream>

template <class T>
class Stack
{
private:
  struct StackNode
  {
    T value;          // Value in the node.  
    StackNode *next;  // Pointer to next node
  };

  StackNode *top;     // Pointer to the stack top
  int length;

public:
  Stack(){ top = NULL; length = 0; }
  ~Stack() {} 

  // Stack operations:
  bool push(T);
  T pop();
  T peek(){ return top->value; }
  bool isEmpty() { return (!getLength()); }
  int getLength(){ return length; }
};

//Member function push inserts the argument onto the stack.
template<class T>
bool Stack<T>::push(T item) {
  StackNode *newNode;  //pointer to new node

  newNode = new StackNode; //Allocate new node and store number there

  if(!newNode) //check in case malloc for new node fails
    return false;

  newNode->value = item; //inserting new value to the node

  //updating links and counter
  newNode->next = top;
  top = newNode;
  length++;

  return true;
}

//Member function pop deletes the value at the top of the stack and returns it.
template<class T>
T Stack<T>::pop() {

  length--; //decrease stack size by 1 each call

  //assigning value of current top node to temp variable
  T temp = top->value; 
  
  //declaring pointer node object and copying data from top node to it
  StackNode *tempNode = top; 
  //updating links
  top = top->next;
 
  //destroying node
  delete tempNode;
    
   //returning variable of deleted node
   return temp;
}
#endif