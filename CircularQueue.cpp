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
	this->First = -1;
	this->Last = -1;
	this->MaxCapacity = N;
	this->Items = new double[MaxCapacity];
}

CircularQueue::~CircularQueue(){
	delete[] this->Items;
}

void CircularQueue::enqueue(double newitem){
	if(this->isFull()){
	  return;
	}

	if(this->First == -1 && this->Last == -1) {
		this->Items[0] = newitem;
		this->First=0;
		this->Last=0;
	}	

	if(this->Last == MaxCapacity - 1){
		this->Items[0] = newitem;
		this->Last = 0;
	} else {
		this->Items[Last + 1] = newitem;
		this->Last = Last + 1;
	}
}

double CircularQueue::dequeue() {
	if(this->isEmpty() || this->first == -1 || this->last == -1){
		return;
	}

	/*if(this->Last == -1) {
		return;
	} else {*/

		

}

bool CircularQueue::isFull(){
	if((this->First == 0 && this->Last == MaxCapacity - 1) || (this->First - this->Last == 1)){
		return true;
	} else return false;
}

bool CircularQueue::isEmpty(){
	return this->First == -1 || this->Last == -1;
}

int CircularQueue::size(){
	
}

int main(){
	return 0;
}
