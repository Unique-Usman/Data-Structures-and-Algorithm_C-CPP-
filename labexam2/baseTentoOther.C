#include <iostream>
#include <string>
#include <stack>

using namespace std;

//function to validate if the input is actually in base10
bool validateInput(string s1)
{
	for (int i = 0; i < s1.length(); i++){
		if (s1[i] >= '0' && s1[i] <= '9')
			continue;
		else
			return false;
	}

	return true;
}

int main()
{
	string data; //data variable to get the data from the user
	int base;  //the base to be specified by the user.
	cout << "Input the data in base 10 which you want to convert " << endl;
	cin >> data; //getting the data from the user. 
	cout << "Input the base you want to convert the number to. The base should be from base 1 to 10 and also base 16, it also work for other base." << endl;
	cin >> base;
	stack<int> s1; //this will store the converted string.

	//validating the input
	while (!validateInput(data)){
		cout << "Invalid input, input should be base 10, input a number in base 10" << endl;
		cin >> data; //getting the data from the user. 
	}
	
	long int data2 = stol(data); //converting the data to int. 
	
	if (data2 == 0){
		s1.push(0); //incase the input number is 0
	}

	// converting to base based on the specified base
	while (data2 != 0)
	{
			int res = data2 % base;
			s1.push(res);
			data2 = data2 / base;
	}

	//outputing the result of  the conversion.
	cout << "Your conversion of " << data << " to base " << base << " is: " << endl;  	
	while (!s1.empty())
	{
		if (base == 16){
			int top = s1.top();
			//handling if the base is 16
			switch(top){
				case 10:
					cout << 'A';
					break;
				case 11: 
					cout << 'B';
					break;
				case 12: 
					cout << 'C';
					break;
				case 13:
					cout << 'D';
					break;
				case 14:
					cout << 'E';
					break;
				case 15: 
					cout << 'F';
					break;
				default: 
					cout << top;
			}
			s1.pop();
			cout << " "; //this is to add space in betweem the output for clearity
		}else{
			cout << s1.top();
			cout << " "; //this is to add space in between the output for clearity
			s1.pop();
		}
	}

	cout << endl;
}
