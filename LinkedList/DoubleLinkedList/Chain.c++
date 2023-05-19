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

