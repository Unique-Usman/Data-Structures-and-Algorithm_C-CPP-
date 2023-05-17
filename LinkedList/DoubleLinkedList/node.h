#ifndef NODE_H
#define NODE_H
	#include <bits/stdc++.h>
	class node{
		int data;
		node* next;
		node* prev;
		public:
		node(int data):this->data(data){}
		friend class chainNode;
	};
#endif
