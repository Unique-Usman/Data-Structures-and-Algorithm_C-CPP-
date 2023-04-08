#include "node.h"
#include "Stack.h"
#include "Stack.C"
#include "node.C"
#include <iostream>
using namespace std;


int main(){
	Stack<int> s1;
	s1.push(4);
	cout << s1.top() << endl;
	cout << s1.size() << endl;
	cout << (s1.isEmpty() ? "yes" : "No") << endl;
	s1.pop();
	cout << (s1.isEmpty() ? "yes" : "No") << endl;
}
