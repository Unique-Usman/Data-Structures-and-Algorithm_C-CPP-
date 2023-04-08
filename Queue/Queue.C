#include "node.h"
#include "Queue.h"
#include <iostream>

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

template <typename T>
T Queue<T>::top(){
	if (head == NULL){
		cout << "The Queue is empty"  << endl;
		return 0;
	}
	return tail->data;
}

template <typename T>
int Queue<T>::pop(){
	if (head == NULL){
		cout << "Nothing to be poped " << endl;
		return 0;
	}else{
		node<T> *tmp = head;
		head = head->next;
		delete tmp;
		return 1;
	}
}

template <typename T>
bool Queue<T>::isEmpty(){
	if (head == NULL){
		return 1;
	}else{
		return 0;
	}
}

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

