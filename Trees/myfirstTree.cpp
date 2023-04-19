#include <iostream>
#include <string>

using namespace std;

template <typename T>
class node{
	public:
		T data;
		node<T> *parent;
		node<T> *left;
		node<T> *right;
		node(T);
		node();
		void setData(T data);

                //just testing out my knowledge about overloading operators 
		template <typename>friend void operator++(node<T> &tree);
};


int main()
{
	node<string> *root = new node<string>("Akinyemi");
//	root->data = 23;
	cout << root->data << endl;

	//adding child to the root node;

	//adding the left child;
	node<string> *firstLeftChild = root->left = new node<string>("Ismail");

	//adding the right child
	node<string> *firstRightChild = root->right = new node<string>("Abass");

	//Adding the first left child Children
	firstLeftChild->left = new node<string>("Usman");
	firstLeftChild->right = new node<string>("Hassan");

	//Adding the first right children 
	firstRightChild->left = new node<string>("Usman");
	firstRightChild->right = new node<string>("Hassan");

	cout << root->left->left->data << endl;
	cout << root->left->right->data << endl;
	cout << root->right->left->data << endl;
	cout << root->right->right->data << endl;
}

template <typename T>
node<T>::node(T data){
	this->data = data;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

template <typename T>
node<T>::node(){
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}
template <typename T>
void node<T>::setData(T data){
	this->data = data;
}

template <typename T>
T operator++(node<T> &tree){
	return tree.data++;
}
