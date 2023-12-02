#include<iostream>
#include<string>
#define max_size 100
using namespace std;
class stack
{
private:
	float stack_items[max_size];
	int top;
public:
	stack();
	bool is_empty();
	bool is_full();
	void push(float x);
	float pop();
	void print_all_element();
	int peek();
	float eval_postfix(string post_fix);
	int precedence(char op);
	bool isOperand(char c);
	string infixToPostfix(string infix);
	~stack();
};

