#include <iostream>

using namespace std;

class ChainNode {
  friend class Chain;
  public:
        ChainNode (int element=0, ChainNode *next=0) // constructor
        {       data = element; link = next;    }
  private:
        int data; 
        ChainNode *link;
};

class Chain {
  private:
        ChainNode *first;
	ChainNode *curNode; // This is the current node which I declared myself. 
  public:
        Chain() { first = NULL; } // constructor
        void insertbegin(int);
        void insertend(int);
        void remove(int);
        void printchain();
	int countNodes();
	void reverseLink();
        void insertAfter(int,int); // inserts a node after finding the specified data
        ~Chain() {              // destructor
                        ChainNode *tmp;
                        while (first) {
                                tmp = first->link;
                                delete first;
                                first = tmp;
                                }
                 }

};

int main()
{
  Chain c;
  short int choice;
  int data, item;
  do
  {
    cout << endl << "   Insert at: 1. Beginning 2. End  3. After an item 4. Stop " << endl;
        cout << "   Enter your choice (1/2/3/4): ";
    cin >> choice;
    switch (choice)
    {
        case 1: cout << "Data to be inserted at beginning: ";
                cin >> data;
                c.insertbegin(data);
                break;
        case 2: cout << "Data to be inserted at end: ";
                cin >> data;
                c.insertend(data);
                break;
        case 3: cout << "Data to be inserted: ";
                cin >> data;
                cout << "Item after which data is to be inserted: ";
                cin >> item;
                c.insertAfter(data,item);
                break;
    }
  } while (choice != 4);
  c.printchain();
  cout << "Enter node to be removed : ";
  cin >> data;
  c.remove(data);
  c.printchain();
  c.reverseLink();
  c.printchain();
  return 0;
}

void Chain::printchain()
{
	ChainNode *tmp = first;
	
	while (tmp != NULL){
		cout << tmp->data << endl;
		tmp = tmp->link;
	}
}

void Chain::insertbegin(int x)
{
  if (first) // list already exists
  {
        ChainNode *tmp = new ChainNode(x, 0);
        tmp->link = first;
        first = tmp;
  }
  else{
        first = new ChainNode(x,0);
	curNode = first;
	}
}

void Chain::insertend(int x)
{
  if (first)  // list already exists
  {
	curNode = (curNode->link = new ChainNode(x, 0));
  }
  else{ 
        first = new ChainNode(x,0);
	curNode = first;
  } // empty list; creating the first node of the list
}

int Chain::countNodes(){
	ChainNode *tmp =  first;
	int count = 0;
	while (tmp != NULL){
		count++;
		tmp = tmp->link;
	}

	return (count);
}

/**
 * data = data to be inserted
 * item = item after which data will be inserted. 
 */
void Chain::insertAfter(int data, int item){ 
	ChainNode *tmp = first;

	while (tmp != NULL){
		if (tmp->link == NULL){
			if (tmp->data == item){
				ChainNode *tmp1 = new ChainNode(data, 0);
				tmp->link = tmp1;
				curNode = tmp1;
				return;
			}else{
				return;
			}
		}else{
			if (tmp->data == item){
				ChainNode *tmp1 = new ChainNode(data, 0);
				tmp1->link = tmp->link;
			       	tmp->link = tmp1;
				tmp = tmp->link->link; //to update the tmp after a node has been inserted;	
			}else{
			
				tmp = tmp->link;
			}
		}
	}
}

void Chain::remove(int x){
	ChainNode *tmp = first;
	bool hasRemoved = false; // this is to track whether any of the element has been remvoed or not to be printout chain does not contain chainNode
	while (tmp != NULL) {
		if ( tmp->link == NULL){
			if (tmp->data == x){
			//	first = tmp == first ? NULL : first;
				if (first == tmp){
					first = NULL;
					curNode == first;
				}else{
					first->link = NULL;
					curNode = first;
				}
				delete tmp;
				return;
			}else{
				if (!hasRemoved){
					cout << "Not found" << endl;
				} 
				return;
			}
		}else{
			if (tmp->data == x){
				if (tmp == first){
					first = tmp->link;
					delete tmp;
					tmp = first;
					hasRemoved = true;
				}else{
					ChainNode* tmp1 = tmp;
					tmp = tmp->link;
					delete tmp1;
					hasRemoved = true;
				}
			}else{
			
				tmp = tmp->link;
			}
		}
        }
}
//Program to reverse linked list
void Chain::reverseLink(){
	curNode = first; 
	ChainNode* prev = NULL;
	ChainNode* curr = first;

	while (curr != NULL){
		ChainNode* next = curr->link;
		curr->link = prev;

		prev = curr;
		curr = next;
	}
	first = prev;
}
