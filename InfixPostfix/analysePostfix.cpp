#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;


//analyse postfix function, it takes string (of number) postfix as an argument and return the value i.e intput- 44+ output = 8 
int analyzePostfix(string postfix)
{
	stack<char> tmp;
	int size = postfix.length();
	int value;
	for (int i = 0; i < size; i++)
	{
		char symbol = postfix[i];

		if (symbol >= '0' && symbol <= '9')
		{
			tmp.push(symbol);
		}else
		{
			int a = tmp.top() - '0';
			tmp.pop();
			int b = tmp.top() - '0';
			tmp.pop();

			switch(symbol)
			{
				case '*':
					value = b * a;
					break;
				case '-':
					value = b - a;
					break;
				case '+':
					value = b + a;
					break;
				case '/':
					value = b / a;
					break;
				case '^':
					value = pow(b, a);
					break;
			}
			tmp.push(value);
		}
	}

	value = tmp.top();
	tmp.pop();

	return (value);
}

int main()
{
	string postfix = "47-";
	cout << analyzePostfix(postfix) << endl;
}
