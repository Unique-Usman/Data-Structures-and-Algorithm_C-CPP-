#include <iostream>
#include <string>
#include <stdexcept>
#define max 10

using namespace std;

template <typename T>
class Stack
{
	private:
		T arr[max];
		int peek;
	public:
		Stack();
		bool isEmpty();
		T top();
		void push(T data);
		T pop();
		int size();
		bool isFull();
};

template <typename T>
Stack<T>::Stack()
{
	peek = -1;
}
template <typename T>
bool Stack<T>::isEmpty()
{
	return (peek == -1 ? true : false);
}

template <typename  T>
T Stack<T>::top()
{
	try{
		if (isEmpty()){
			throw "The stack is empty ";
		}
		return arr[peek];
	}catch(const char *err){
		cout << "Error was found" << endl << err << endl;
		exit(1);
	}
}

template <typename T>
void Stack<T>::push(T data)
{
	try{
		if (isFull())
			throw "The stack is full: ";
		peek++;
		this->arr[peek] = data;
	}catch(const char *err){
		cout << "Error was found" << endl << err << endl;
		exit(1);
	}
}

template <typename T>
T Stack<T>::pop()
{
	try{
		if (isEmpty())
			throw "The stack is empty";
		return arr[peek--];
	}catch(const char *err){
		cout << "Error was found" << endl << err << endl;
		exit(1);
	}
}

template <typename T>
int Stack<T>::size()
{
	return peek++;
}

template <typename T>
bool Stack<T>::isFull()
{
	return (++peek == max ? true : false);
}


int main()
{
	Stack<int> s2;
	s2.pop();
}
