#include <iostream>

class A
{
	protected: 
		int a = 9;
};

class B : public A
{
	public:
		int a = 9;
};

int main()
{
	B b;
	std::cout << b.a << std::endl;
}
