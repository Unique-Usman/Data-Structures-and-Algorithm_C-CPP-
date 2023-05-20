#ifndef CHAINNODE_H
#define CHAINNODE_H
#include "node.h"
#include <iostream>
using namespace std;
	class chainNode{
		private:
			static node* firstNode;
			static node* currentNode;
		public:
			static void printNode();
			static void insertNodeEnd();
			static void insertNodeFront(int);
        		static void insertbegin(int);
        		static void insertend(int);
        		static void remove(int);
        		static void printchain();
       			static void printReverse();
			static void reverseNode();
        		static int countNodes();
        		static void insertAfter(int,int); // inserts a node after finding the specified data
};

#endif
