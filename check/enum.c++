#include <iostream>

enum Example {
	A = 9, B = 3, C = 3
};

class Base
{
	private:
		int a;
};

class Derived : private Base{
	int b;
};
class Derived2: private Derived{
	
};
int main()
{
	Derived2 p;
	std::cout << sizeof(p) << std::endl;
	Example value = B;
	float a = 45.5f;
	double d = 43.3;
	std::cout << sizeof(a) << std::endl;
	std::cout << sizeof(d) << std::endl;
	std::cout << a << std::endl;
}
