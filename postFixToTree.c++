#include <bits/stdc++.h>

using namespace std; 

class node
{
	public:
		char data; 
		node* lchild;
		node* rchild;
};

//create new node function
node* createNewNode(char data){
        node* tmp = new node;
        tmp->data = data;
        tmp->lchild = tmp->rchild = NULL;
        return (tmp);
}

//code to print in postorderly
void postOrderPrint(node* root)
{
        if (root != NULL)
        {
                postOrderPrint(root->lchild);
                postOrderPrint(root->rchild);
                cout << root->data << endl;
        }
}
//print data in an inorder manner
void inOrderPrint(node* root)
{
        if (root != NULL)
        {
                inOrderPrint(root->lchild);
                cout << root->data << endl;
                inOrderPrint(root->rchild);
        }
}

//print data in a preOrder manner
void preOrderPrint(node* root)
{
        if (root != NULL)
        {
                cout << root->data << endl;
                preOrderPrint(root->lchild);
                preOrderPrint(root->rchild);
        }
}

//Evaluating arithmetic tree. 
string evaluateTree(node *root)
{
	if (root->lchild == NULL && root->rchild == NULL)
	{
		string str(1, root->data); //converting the character to string
		return str;
	}
	return evaluateTree(root->lchild) + root->data + evaluateTree(root->rchild);
}
int main()
{
	string postFix;
	stack<node*> tree;
      	cout << "Input the postfix expression to be converted to a tree in upperCase: " << endl;	
	cin >> postFix;


	//making the tree from the string
	for (int i = 0; i < postFix.length(); i++)
	{
		if (postFix[i] >= 'A' && postFix[i] <= 'Z')
		{
			tree.push(createNewNode(postFix[i]));
		}else{
			node* tmp = createNewNode(postFix[i]);
			tmp->rchild = tree.top();
			tree.pop();
			tmp->lchild = tree.top();
			tree.pop();
			tree.push(tmp);
		}
	}
	
	//root is the tree created from the string
	node* root = tree.top();
	
	cout << "Printing the tree using postOrder/Postfix: " << endl;
	postOrderPrint(root);
	cout << "Printing the inorder/Infix form of the tree: " << endl;
	inOrderPrint(root);
	cout << "Printing the Preorder/Prefix form of the tree: " << endl;
	preOrderPrint(root);

	cout << "Evaluating the tree: " << endl;	
	string answer = evaluateTree(root);
	cout << answer << endl;
}
