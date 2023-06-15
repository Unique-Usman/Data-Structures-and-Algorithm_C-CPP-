#include <iostream>
#include "string"
struct INT
{
	public:
	int name;

	static int code;

	INT(int name)
	{
		this->name = name;
	}
	void print()
	{
		std::cout << name << std::endl;
	}
	void print(std::string a)
	{
		std::cout << a << name << std::endl;
	}
	static void say(std::string hello)
	{
		system("say hello");
	}
};


int main()
{
	INT in(5);
	in.print();
	in.print("Hello");
	in.INT::say("hello");
}
