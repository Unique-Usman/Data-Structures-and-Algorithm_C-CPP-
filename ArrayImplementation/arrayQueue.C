#include <iostream>
#define max 5 //max is maximum number the queue can take 
using namespace std;

template <typename T>
class queue
{
	private:
		T arr[max];
		int top;
		int back;
		int n; //n is the size of the array
	public:
		queue(); //constructor
		bool isEmpty(); //check whether the queue is empty
		bool isFull(); //check whether the queue is full 
		int size();  // check the size of the queue
		void push(T data); //push element into the queue
		void pop(); //delete the element using the FIFO i.e element at the front
		T front(); //return the the element at the top of the array
};


template <typename T>
queue<T>::queue(){
	top = -1; 
	back = -1;
	n = 0;
}


template <typename T>
bool queue<T>::isEmpty(){
	return (top == -1 && back == -1 ? true : false);
}

template <typename T>
bool queue<T>::isFull(){
	return (top == 0 && back == max - 1 ? true : false);
}

template <typename T>
int queue<T>::size(){
	return (n);
}

template <typename T>
void queue<T>::push(T data){
	if (isFull()){
		cout << "The queue is full. " << endl;
	}else if(isEmpty()){
		top = (top + 1) % max;
		back = (back + 1 + max) % max;
		arr[top] = data;
		n++;
	}else{
		top = (top + 1) % max;
		arr[top] = data;
		n++;
	}
}

template <typename T>
void queue<T>::pop(){
	if (isEmpty()){
		cout << "The stack is empty " << endl;
	}else if (top == back){
		top = -1;
		back = -1;
		n--;
	}else{
		n--;
		back = (back + 1 + max) % max;
	}
}

template <typename T>
T queue<T>::front(){
	return arr[top];
}

int main(){
	queue<int> q1;
	q1.push(4);
	q1.push(10);
	q1.pop();
	cout << q1.front() << endl;
}
