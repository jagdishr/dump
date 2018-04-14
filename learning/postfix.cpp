#include <postfix.h>
#include <stack>
#include <exception>
#include <iostream>

std::map<char, double> varValues{ { 'a', 4 },{ 'b', 2 },{ 'c', 8 },{ 'd', 5 } };

bool isOperator(char c)
{
	if (c == '+' ||
		c == '-' ||
		c == '*' ||
		c == '/')
	{
		return true;
	}
	return false;
}

double operate(char operation, double a, double b)
{
	switch (operation)
	{
	case '+':
		return (a + b);
	case '-':
		return (a - b);
	case '*':
		return (a * b);
	case '/':
		return (a / b);
	}
	throw std::runtime_error("Unknown operator encountered in expression");
	return 0;
}

double parseExpression(std::string str)
{
	std::stack<double> varStack;

	for (auto s : str)
	{
		if (!isOperator(s))
		{
			varStack.push(varValues[s]);
		}
		else
		{
			double var1 = varStack.top();
			varStack.pop();
			double var2 = varStack.top();
			varStack.pop();
			double result = operate(s, var2, var1);
			varStack.push(result);
		}
	}
	double result = varStack.top();
	return result;
}


int run_postfix()
{
	std::string expr("ab+cd-*");

	std::cout << "Parsed value of post-fix expression " << expr << " is: " << parseExpression(expr);

	return 0;
}