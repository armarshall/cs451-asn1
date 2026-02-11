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
	// You can't enqueue to a full list
	if(this->isFull()){
	  	return;
	}

	// Set First and Last to 0 if it's the first item
	if(this->isEmpty()){
		this->First=0;
		this->Last=0;
		this->Items[0] = newitem;

		return;
	}	

	// Add the new item to the queue, and adjust Last
	int newindex = (this->Last + 1) % MaxCapacity;
	this->Items[newindex] = newitem;
	this->Last = newindex;
}

double CircularQueue::dequeue() {
	int size = this->size();
	
	// You can't dequeue from an empty list
	if(size == 0){
		return -1;
	}

	// Save the old item
	double olditem = Items[this->First];

        if(size == 1){ // If size was originally 1, it's now 0. We have to adjust First and Last back to -1
                this->First = -1;
                this->Last = -1;	
	} else this->First = (this->First + 1) % MaxCapacity; // Move first up one spot

	return olditem;	

}

bool CircularQueue::isFull(){
	return this->size() == MaxCapacity;
}	

bool CircularQueue::isEmpty(){
	return this->size() == 0;
}

int CircularQueue::size(){
	// If the list is empty
	if(this->First == -1 || this->Last == -1){
		return 0;
	}
	
	int temp = this->First;
	int count = 1;

	// Go around the queue until first reaches last
	while(temp != this->Last){
		count++;
		temp = (temp + 1) % MaxCapacity;
	}

	return count;
}

int main(){
	CircularQueue* c = new CircularQueue(6);
	c->enqueue(3);
	c->enqueue(2);
	c->enqueue(9);
        c->enqueue(5);
	c->enqueue(6);
        c->enqueue(7);	

	printf("%d\n", c->size());

	printf("%f\n", c->dequeue());
	printf("%d\n", c->size());

	printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

	printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

	c->enqueue(12);
        c->enqueue(15);
        c->enqueue(17);

	printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

        printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

        printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

	printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

        printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

        printf("%f\n", c->dequeue());
        printf("%d\n", c->size());

	return 0;
}
