#include <iostream>

class Base {
	public:
		virtual void say()
		{
			std::cout << "Hello World" << std::endl;
		}
};

class Derived1: virtual public Base{
};

class Derived2: virtual public Base {
};

class Derived: public Derived1, public Derived2
{
	
};

int main()
{
	Derived d1;
	d1.say();
}
