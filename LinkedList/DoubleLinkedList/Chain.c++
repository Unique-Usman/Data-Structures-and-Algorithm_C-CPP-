#include "Chain.h"

void chainNode::printNode()
{
	node* tmp = firstNode;
	while (tmp != NULL)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

void chainNode::insertNodeFront(int data)
{
	if (firstNode == NULL)
	{
		firstNode = new node(data);
		firstNode->next = NULL;
		firstNode->prev = NULL;
		currentNode = firstNode;
	}else{
		node* tmp = new node(data);
		tmp->next = firstNode;
		firstNode->prev = tmp;
		firstNode = tmp;
	}
}
