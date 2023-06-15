#include <iostream>

class A
{
private: void virtual say() = 0;
};

class B	: public A{
	public: void say() override {
		std::cout << "Hello World";
	}
};


int main()
{
	B b;
	b.say();
}
