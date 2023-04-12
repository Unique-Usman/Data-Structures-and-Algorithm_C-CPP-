#include <iostream>
#define max 10
#include <string>
#include <type_traits>

using namespace std;

template <typename T>
class Stack{
	private:
		T arr[max];
		int top;
	public:
		Stack();
		bool isEmpty();
		bool isFull();
		void pop();
		void push(T data);
		T peek();
};


//default constructor which initialize the top to -1
template <typename T>
Stack<T>::Stack()
{
	this->top = -1;
}

//member function to check if the array is empty
template <typename T>
bool Stack<T>::isEmpty()
{
	return (top == -1 ? true : false);
}

//member function to check if the array is full
template <typename T>
bool Stack<T>::isFull()
{
	return (top == max - 1 ? true : false);
}

//member function to delete the element at the top
template <typename T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Nothing to be poped, the stack is empty. " << endl;
	}else
	{
		top--;
	}
}

//member function to push the new element into the array
template <typename T>
void Stack<T>::push(T data)
{
	if (isFull())
	{
		cout << "The stack is full: " << endl;
	}else
	{
		this->top++;
		this->arr[top] = data;
	}
}

//member function to get the element at the top
template <typename T>
T Stack<T>::peek()
{
	if (isEmpty())
	{
	//	return ( is_same<T, string>::value ? "" : 459862570843891290); 
        	if (std::is_same<T, std::string>::value)
        	{
            		return "";
        	}
        	else
        	{
            		return 459862570843891290;
        	}
	}else
	{
		return (arr[top]);
	}
}


//the driver main function
int main(){
        Stack<int> s1;
//      s1.push(20);
        s1.push(300);
        s1.pop();
        s1.peek();
}

