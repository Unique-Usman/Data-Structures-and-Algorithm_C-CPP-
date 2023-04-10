#include "node.h"

template <typename T> //This is contructor for the node class
node<T>::node(T data, node<T>* next){
	this->data = data;
	this->next = next;
}
