#include <bits/stdc++.h>

using namespace  std;

typedef struct node{
	int data;
	node *next;
}node;

// function to print node;
void printNode(node *head){
	node *tmp = head;

	if  (tmp == NULL){
		cout << "There is nothing to be printed";
	}else{
		while (tmp != NULL){
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
}

// function to addNode Begin

void addNodeBegin(int data, node **head){
	node *tmp = new node;
	tmp->data = data;
	tmp->next = *head;
	*head = tmp;
}

// function addNodeEnd

void addNodeEnd(int data, node** curNode){
	node *tmp = new node;
	tmp->data = data;
	tmp->next = NULL;
	if (*curNode == NULL){	
		(*curNode) = tmp;
	}else{
		(*curNode)->next = tmp;
	}
	*curNode = tmp;
}

// function to count Node 

int countNode(node *head){
	node *tmp = head;
	int count = 0;

	while (tmp != NULL){
		count++;
		tmp = tmp->next;
	}

	return count;
}

// delete node at the beginning
void deleteNodeBegin(node **head){
	node *tmp = *head;

	if (tmp == NULL){
		cout << "Nothing to be deleted" << endl;
	}else{
		*head =  (*head)->next;
		delete tmp;
	}
}

// delete node at the end

node* deleteNodeEnd(node** head){	
	node *tmp = *head;
	if (tmp == NULL){
		cout << "Nothing to be deleted" << endl;
		return NULL;
	}else if(tmp->next == NULL){
		delete tmp;
		tmp = NULL;
		*head = NULL;
		return tmp;
	}else{
		while (tmp->next->next != NULL){
			tmp = tmp->next;
		}
		delete tmp->next;
		tmp->next = NULL;
		return tmp;
	}
}

//function to print linkedlist in a reverse manner
void printListReverse(node* head)
{
	if (head->next != NULL){
		printListReverse(head->next);
		cout << head->data << endl;
	}
}

//function to print node in reverse manner using loop
void printReverseLoop(node* head)
{
	node* tmp = head;
	stack<int> dataStack;
	if (tmp == NULL){
		return;
	}else{
		while (tmp != NULL){
			dataStack.push(tmp->data);
			tmp = tmp->next;
		}
	}

	while (!dataStack.empty()){
		cout << dataStack.top() << endl;
		dataStack.pop();
	}
}
int main(){
	node *head; // head of the linked-list
	head = NULL; 
	node *curNode = head; // curNode to mark the current postion of the linked link;
	head = new node;
	head->data = 500;
	head->next = NULL;
	curNode = head;
	addNodeEnd(300, &curNode);
	printNode(head);
	addNodeBegin(900, &head);
	cout << "New change" << endl;
	printNode(head);
	cout << "printing the node in a reverse manner" << endl;
	printListReverse(head);
	deleteNodeBegin(&head);
	cout << "New change" << endl;
	printNode(head);
	curNode = deleteNodeEnd(&head);
	curNode = deleteNodeEnd(&head);
	curNode = deleteNodeEnd(&head);
	cout << "New change" << endl;
	printNode(head);
}

