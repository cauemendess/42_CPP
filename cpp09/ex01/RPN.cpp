#include "RPN.hpp"
#include <cstdlib>


RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

void RPN::calculate(const std::string &expression)
{
    _validateExpression(expression);
    for (size_t i = 0; i < expression.size(); ++i)
    {
        char c = expression[i];
        if (isdigit(c))
        {
            _processNumber(std::string(1, c));
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            _processOperator(c);
        }
    }
    if (_numbers.size() != 1)
    {
        throw std::runtime_error("Invalid expression: final stack should contain exactly one number");
    }
    std::cout << _numbers.top() << std::endl;
}

void RPN::_validateExpression(const std::string &expression)
{
    for (size_t i = 0; i < expression.size(); ++i)
    {
        char c = expression[i];
        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && !isspace(c))
        {
            throw std::runtime_error("Invalid character in expression");
        }
    }
}
void RPN::_processNumber(const std::string &number)
{
    char *endptr;
    double num = std::strtod(number.c_str(), &endptr);
    
    if (endptr == number.c_str() || *endptr != '\0')
    {
        throw std::runtime_error("Invalid number format");
    }
    
    _numbers.push(num);
}

void RPN::_processOperator(char op)
{
    if (_numbers.size() < 2)
    {
        throw std::runtime_error("Not enough numbers in stack for operation");
    }
    double b = _numbers.top();
    _numbers.pop();
    double a = _numbers.top();
    _numbers.pop();
    double result = _performOperation(a, b, op);
    _numbers.push(result);
}

double RPN::_performOperation(double a, double b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Division by zero");
            return a / b;
        default:
            throw std::runtime_error("Unknown operator");
    }

}