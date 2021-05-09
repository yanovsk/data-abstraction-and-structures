#include <iostream>
using namespace std;

class Stack_int
{
private:`
   struct StackNode {
       int value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_int(){ top = NULL; length = 0; }    //Constructor
   //~Stack_int();                            // Destructor

   // Stack operations
   bool isEmpty() { return top == nullptr; }
   bool push(int);
   void pop();
   int peek() { return top->value; }
   int getLength() { return length; }
};

/**~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_int::push(int item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}

/**~*~*
  Member function pop pops the value at the top
  of the stack off, and returns it
  Assume stack is not empty
*~**/

/* Define the pop function */
void Stack_int::pop() {

  StackNode *temp;       //pointer to temp node
  temp = new StackNode;  //allocating memory for temp node

  //updating links   
  temp = top;            //assign current top to temp to be deleted

  cout << temp->value;   //display the integer value stored in node 

  top = top->next;       //Assign second node to top

  //temp->next = NULL;     // Destroy connection between fist and second nodes

  delete temp;           // Release memory of temp node
}



int main() {

  Stack_int s;
  int item;

  /* Write your code here to test the push and pop functions */

  while (true) {        //defining while loop
    cin >> item;        // taking input from the user
    
    if (item <= 0) {    //checking if user entered 0 or negative number
      break;            //stop executing loop if condition is satisfied
    }    
    s.push(item);       //calling push() function to add inputted number onto the stack
  }

  if(s.isEmpty()) {               //checking if the first input is 0 or negative number
    cout << "Empty Stack!\n";     //if condition is met - displaying message
  } else {   
    while(!s.isEmpty()) {   //loop that executes pop() until list is empty
      s.pop();              // calling pop() function to delete elements from stack
      cout << endl;
    }
  }
  
  return 0;
}