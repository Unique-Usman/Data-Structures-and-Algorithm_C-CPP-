#ifndef NODE_H
#define NODE_H
#include <string>

	template <typename T>
	class node{
		template <typename>friend class Stack;
		private:
			T data;
			node<T> *next;
		public:
			node(){};
			node(T data,node<T> *next); 
	};
#endif
