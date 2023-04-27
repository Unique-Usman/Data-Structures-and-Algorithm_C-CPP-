#include <bits/stdc++.h>

using namespace std;

double fib(int n)
{
	if (n < 2){
		return n;
	}
	return fib(n - 1) + fib(n -2);
}

int main()
{
	cout << fib(50) << endl;
}
