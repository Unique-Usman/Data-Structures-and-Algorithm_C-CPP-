#ifndef CHAINNODE_H
#define CHAINNODE_H
#include "node.h"
#include <iostream>
template <typename T>
using namespace std;
	class chainNode{
		private:
			static node<T> *firstNode;
			static node<T> *currentNode;
		public:
			static void printNode();
			static void insertNodeEnd();
			static void insertNodeFront(T);
        		static void insertbegin(T);
        		static void insertend(T);
        		static void remove(T);
        		static void printchain();
       			static void printReverse();
			static void reverseNode();
        		static int countNodes();
        		static void insertAfter(T,T); // inserts a node after finding the specified data
};

#endif
