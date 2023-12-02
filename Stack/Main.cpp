#include<iostream>
#include<string>
#include "stack.h"
using namespace std;
int main()
{
	stack s;
	string n;
	cout << "enter string in postfix\n";
	cin >> n;
	cout << s.eval_postfix(n) << endl;
	cout << "Enter string in infix\n";
	cin >> n;
	cout << s.infixToPostfix(n) << endl;
	return 0;
}