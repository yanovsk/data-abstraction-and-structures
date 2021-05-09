#include <iostream>
#include <string>
#include "QueueADT.h"

using namespace std;

int main() {

  Queue<string> nQue;   // Create the first queue (strings)
  string name;

  while(cin >> name) {  

    if(name == "#")
      break;
    
    nQue.push(name);
  }

  // Test the getLength function: - display the number of elements in the first queue

  if(!nQue.isEmpty()) {                 //checking if any element were entered 
    cout << nQue.getLength() << " ";
  } else {                              //in case "#" was entered first
    //displaying the msg and exiting program                        
    cout << "Empty Queue!\n";
    exit(EXIT_SUCCESS); 
  }
  
  // Create the second queue (doubles)
  Queue<double> uQue;

  // Test the getLength function: - display the number of elements in the second queue
  cout << uQue.getLength() << endl;

  // Write another loop to enter the number of units (double) into a parallel queue.
  double unit; 

  while(cin >> unit) {
    uQue.push(unit);
  }

  // Display the two queues in parallel.
  //storing front and rear values from 2 queues before executing pop() for entire queue
  name = nQue.peek();  
  unit = uQue.peekRear();

  //using return feature of pop() to output values from both queues in parallel
  while(!nQue.isEmpty()) { //loop executes until queue is empty
    cout << nQue.pop() << " " << uQue.pop() << endl;
  }

  // Display the front element in the first queue
  cout << name << endl;
  
  // Display the rear element in the second queue
  cout << unit << endl;

  return 0;
}
