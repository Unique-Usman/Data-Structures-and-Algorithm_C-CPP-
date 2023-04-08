#include "node.h"

template <typename T>
node<T>::node(T data, node<T>* next){
	this->data = data;
	this->next = next;
}
