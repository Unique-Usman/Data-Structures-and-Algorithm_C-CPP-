#include "node.h"
#include "Queue.h"
#include <iostream>

//This function push the new data to the end of the end of the Queue
template <typename T>
void Queue<T>::push(T data){
	if (head == NULL){
		node<T> *tmp = new node<T>(data, NULL);
		head= tmp;
		tail = head;
	}else{
		tail->next = new node<T>(data, NULL);
		tail = tail->next;
	}
}

//This return the last element at the back, similar to the top in the stack just the name is diffenrence. 
template <typename T>
T Queue<T>::back(){
	if (head == NULL){
		cout << "The Queue is empty"  << endl;
		return 0;
	}
	return tail->data;
}

//remove the element at the top
template <typename T>
int Queue<T>::pop(){
	if (head == NULL){
		cout << "Nothing to be poped " << endl;
		return 0;
	}
	else{
		node<T> *tmp = head;
		head = head->next;
		delete tmp;
		if (head == NULL)
			tail = head; 
		return 1;
	}
}

//check if the queue is empty
template <typename T>
bool Queue<T>::isEmpty(){
	if (head == NULL){
		return 1;
	}else{
		return 0;
	}
}

//check the size of the queue
template <typename T>
int Queue<T>::size(){
	int count = 0;
	node<T> *tmp = head;
	while(tmp != NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}

