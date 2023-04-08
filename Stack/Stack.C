#include "node.h"
#include "Stack.h"
#include <iostream>

template <typename T>
void Stack<T>::push(T data){
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
T Stack<T>::top(){
	if (head == NULL){
		cout << "The Stack is empty"  << endl;
		return 0;
	}
	return tail->data;
}

template <typename T>
int Stack<T>::pop(){
	if (head == NULL){
		cout << "Nothing to be poped " << endl;
		return -1;
	}else{
		if (head->next == NULL){
			delete head;
			head = NULL;
			tail = NULL;
		}else{
			node<T> *tmp1 = head;
			while(tmp1->next->next != NULL){
				tmp1 = tmp1->next;
			}
			tail = tmp1;
			delete tmp1->next;
		}
		return 0;
	}
}

template <typename T>
bool Stack<T>::isEmpty(){
	if (head == NULL){
		return 1;
	}else{
		return 0;
	}
}

template <typename T>
int Stack<T>::size(){
	int count = 0;
	node<T> *tmp = head;
	while(tmp != NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}


