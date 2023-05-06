#include <iostream>

using namespace std;

class node
{
	public:
		int data;
		node *lchild, *rchild;
};

//function for creating a node
node* createNode(int data)
{
	node* n = new node;
	n->data = data;
	n->lchild = n->rchild = NULL;
	return n;
}

//function for inserting node
node* insertNode(node* root, int data)
{
	if (root == NULL)
	{
		root = createNode(data);
	}else if (data < root->data)
	{
		root->lchild = insertNode(root->lchild, data);
	}else
	{
		root->rchild = insertNode(root->rchild, data);
	}

	return root;
}

//function to print trees
void printNode(node *root)
{
	if (root != NULL)
	{
		printNode(root->lchild);
		cout << root->data << endl;
		printNode(root->rchild);
	}
}
int main()
{
	node *root = NULL;
	root = insertNode(root, 10);
	root = insertNode(root, 12);
	root = insertNode(root, 9);
	printNode(root);
}
