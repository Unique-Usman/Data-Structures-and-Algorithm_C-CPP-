#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int precedence(char symbol); //function for checking precedence
void infixToPosfix(string infix, queue<char> &postfix); //function for changing prefix to postfix

//the main driver
int main()
{
	string infix;
	queue<char> postfix;
	cout << "Input the infix string that you want to conveert to postfix: "  << endl;
	getline(cin, infix);
	infixToPosfix(infix, postfix);

	while (!postfix.empty())
	{
		cout << postfix.front();
		postfix.pop();
	}

	return (0);
}


/**
 *@infix: The infix string to be changed to postfix
 *@postfix: The postfix queue
 */
void infixToPosfix(string infix, queue<char> &postfix)
{
        int size = infix.length();
        stack<char> tmp; //This will be used as temporary storage for operators and bracket

	//traversing through each character in a string. 
        for (int i = 0; i < size; i++)
        {
                char symbol = infix[i];
                switch(symbol){
                        case '(':
                                tmp.push(symbol);
                                break;
                        case ')':
                                while (tmp.top() != '(')
                                {
                                        postfix.push(tmp.top());
                                        tmp.pop();
                                }
                                tmp.pop();
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '^':
                                while (!tmp.empty() && precedence(tmp.top()) >= precedence(symbol))
                                {
                                        postfix.push(tmp.top());
                                        tmp.pop();
                                }
                                tmp.push(symbol);
                                break;
                        default:
                                postfix.push(symbol);
                }
        }

	//pushing the remaining operator into the postfix queue
	while (!tmp.empty())
	{
		postfix.push(tmp.top());
		tmp.pop();
	}
}

// checking for the precedence of the operators 
int precedence(char symbol){
	int value;

        switch(symbol)
        {
                case '^':
                        value =  3;
                        break;
                case '+':
                case '-':
                       value = 1;
                        break;
                case '*':
                case '/':
                        value = 2;
                        break;
		default:
			value = 0;
        }

	return (value);
}
