#include "Chain.h"

typename <template T
void chainNode<T>::printNode()
{
	node<T>* tmp = firstNode;
	while (tmp != NULL)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

typename <template T
void chainNode<T>::insertNodeFront(int data)
{
	if (firstNode == NULL)
	{
		firstNode = new node<T>(data);
		firstNode->next = NULL;
		firstNode->prev = NULL;
		currentNode = firstNode;
	}else{
		node<T>* tmp = new node<T>(data);
		tmp->next = firstNode;
		firstNode->prev = tmp;
		firstNode = tmp;
	}
}
