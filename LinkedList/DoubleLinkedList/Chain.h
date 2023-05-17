#ifndef CHAINNODE_H
#define CHAINNODE_H
#include "node.h"
	class chainNode{
		private:
			static node* firstNode;
			static node* currentNode;
		public:
			static void pirntNode();
			static void insertNodeEnd();
			static void insertNodeFront();
	};
#endif
