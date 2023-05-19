#ifndef CHAINNODE_H
#define CHAINNODE_H
#include "node.h"
#include <iostream>
	class chainNode{
		private:
			static node* firstNode;
			static node* currentNode;
		public:
			static void printNode();
			static void insertNodeEnd();
			static void insertNodeFront();
        		static void insertbegin(T);
        		static void insertend(T);
        		static void remove(T);
        		static void printchain();
       			static void printReverse();
			static void reverseNode();
        		static int countNodes();
        		static void insertAfter(T,T); // inserts a node after finding the specified data
};

	};
#endif
