//Queue template
#ifndef QUEUE_ADT
#define QUEUE_ADT

template <class T>
class Queue
{
private:
    // Structure for the queue nodes
    struct QueueNode
    {
        T value;          // Value in the node.  
        QueueNode *next;  // Pointer to next node
    };
  
    QueueNode *front;          // Pointer to the first node
    QueueNode *rear;           // Pointer to the last node
    int length;                // Number of nodes in the queue

public:
    Queue(){ front = rear = NULL; length = 0; } //Constructor
    ~Queue(); // Destructor

    // Queue operations: 
    bool isEmpty() { return rear == NULL; }
	bool push(T);
	T pop();
	T peek() { return front->value; }
	T peekRear() { return rear->value; }
	int getLength() { return length; } 
};

/**~*~*
  Member function dequeue deletes the value at the front
  of the queue and returns it.
  Assume queue has at least one node
  Using pop() boilerplate code from lab 4.5
*~**/
template <class T>
T Queue<T>::pop()
{
	QueueNode *pDel; // Temporary pointer
	// delete the value at the front of the queue
	T value = front->value;
	pDel = front;
	
	if( length == 1 )
        rear = NULL;

    //update links and count
	front = front->next;
	length--;
	delete pDel; //freeing memory 
	return value; //returning value of deleted node
}

/**~*~*
  Member function push: inserts the argument into the queue
  Using push() boilerplate code from lab 4.3
*~**/
template <class T>
bool Queue<T>::push(T item)
{
   QueueNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new QueueNode;
   if (!newNode)
    return false;

   newNode->value = item;
   newNode->next = NULL;
   
   // Update links and counter
   if (!front) // front is NULL: empty queue
    front = newNode;
   else
    rear->next = newNode;
       
   rear = newNode;
   length++;

   return true;
}

/**~*~*
   Destructor
   Using destructor boilerplate code from lab 4.4 with removed debug cout statements
*~**/
template<class T>
Queue<T>::~Queue()
{
    QueueNode *next;
    
    while(front != NULL) 
    {
        next = front->next;
        delete front;
        front = next;
    }
}

#endif