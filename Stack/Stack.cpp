#include "Stack.h"
#include<iostream>
#include<string>
using namespace std;
stack::stack() :top(-1)
{
}
bool stack::is_empty()
{
	return(top == -1);
}
bool stack::is_full()
{
	return(top == max_size - 1);
}
void stack::push(float x)
{
	if (is_full())
	{
		cout << "The stack is overflow";
		return;
	}
	stack_items[++top] = x;
}
float stack::pop()
{
	if (is_empty())
	{
		cout << "The stack is underflow";
		return 0;
	}
	float current_item = stack_items[top--];
	return current_item;
}
void stack::print_all_element()
{
	for (int i = 0; i <= top; i++)
	{
		cout << stack_items[i];
	}
}
int stack::peek()
{
	return stack_items[top];
}
float stack::eval_postfix(string post_fix)
{
	float op1, op2, val = 0;
	for (int i = 0; i < post_fix.length(); i++)
	{
		if (isdigit(post_fix[i]))
			push(post_fix[i] - 48);
		else
		{
			op2 = pop();
			op1 = pop();
			switch (post_fix[i])
			{
			case '+':
				val = op1 + op2;
				break;
			case '-':
				val = op1 - op2;
				break;
			case '/':
				val = op1 / op2;
				break;
			case '*':
				val = op1 * op2;
				break;
			}
			push(val);
		}
	}
	return pop();
}
int stack::precedence(char op)
{
	if (op == '^')
		return 3;
	if (op == '*' || op == '/')
		return 2;
	if (op == '+' || op == '-')
		return 1;
	return 0;
}
bool stack::isOperand(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}
string stack::infixToPostfix(string infix)
{
	string postfix = "";
	for (int i = 0; i < infix.length(); i++)
	{
		char c = infix[i];
		if (isOperand(c))
		{
			postfix += c;
		}
		else if (c == '(')
		{
			push(c);
		}
		else if (c == ')')
		{
			while (!is_empty() && stack_items[top] != '(')
			{
				postfix += char(stack_items[top]);
				pop();
			}
			if (!is_empty() && stack_items[top] == '(')
			{
				pop();
			}
		}
		else
		{
			while (!(is_empty()) && (precedence(c) <= precedence(stack_items[top])))
			{
				postfix += char(stack_items[top]);
				pop();
			}
			push(c);
		}
	}
	while (!is_empty())
	{
		postfix += char(stack_items[top]);
		pop();
	}
	return postfix;
}
stack::~stack()
{
}