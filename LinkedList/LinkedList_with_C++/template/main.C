#include "Chain.h"
#include "ChainNode.h"
#include "ChainNode.C"
#include "Chain.C"

#include <iostream>
using namespace std;

int main()
{
  Chain<int> c;
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

