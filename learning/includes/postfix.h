#pragma once
#include <string>
#include <map>

//helper methods
bool isOperator(char c);
double operate(char operation, double a, double b);

//primary parser method for api call
double parseExpression(std::string str);

int run_postfix();