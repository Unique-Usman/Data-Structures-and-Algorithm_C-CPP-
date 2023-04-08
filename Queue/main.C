#include "node.h"
#include "Queue.h"
#include "Queue.C"
#include "node.C"
#include <iostream>
using namespace std;


int main(){
	Queue<int> s1;
	s1.push(4);
	cout << s1.top() << endl;
	cout << s1.size() << endl;
	cout << (s1.isEmpty() ? "yes" : "No") << endl;
	s1.pop();
	cout << (s1.isEmpty() ? "yes" : "No") << endl;
}
