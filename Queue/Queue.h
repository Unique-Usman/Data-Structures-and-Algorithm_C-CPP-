#ifndef STACK_H
#define STACK_H
#include <string>
#include "node.h"
#include <iostream>

using namespace std;
template <typename T>
class Queue{
	private:
		node<T> *head = NULL;
		node<T> *tail = NULL;
	public:
		void push(T data);
		int pop(); //return 0 if success and -1 if not
		T top();
		bool isEmpty();
		int size();
};

#endif
