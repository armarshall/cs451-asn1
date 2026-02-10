// @Author: Aidan Marshall
// @Author: Partner’s Name (if done in pair)

#include <iostream> //imports cout/cin

using namespace std; //Mandatory to use cout/cin

class CircularQueue{
 	private: // You may not rename nor add more attributes
 		int First; // position for First/Front/Head
 		int Last; // position for Last/Rear/Tail
 		int MaxCapacity; //Maximum capacity for items
 		double* Items; //The actual items stored in the queue

 	public: //You may add more methods if you want
 		CircularQueue(int N); /* Constructor will allocate double array for N Items, set Maximum capacity as N, and initialize First & Last. */
 		~CircularQueue(); /* Destructor will deallocate the double array */
 		void enqueue(double newitem); // Enqueues newitem
 		double dequeue(); // Dequeues the appropriate item and returns it
 		bool isEmpty(); // Verifies if the queue is empty
 		bool isFull(); // Verifies if the queue is full
 		int size(); /* Returns how many items are in the queue (attention: this is not the same as the MaxCapacity) */
};

CircularQueue::CircularQueue(int N){
	this->First = 0;
	this->Last = N - 1;
	this->MaxCapacity = N;

	for(int i = 0; i < MaxCapacity; i++){
		*Items = NULL;
	}
}

int main(){
	return 0;
}
