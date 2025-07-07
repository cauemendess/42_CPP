#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>


class RPN
{
private:
    std::stack<double> _numbers;

    void _processOperator(char op);
    void _processNumber(const std::string &number);
    void _validateExpression(const std::string &expression);
    double _performOperation(double a, double b, char op);
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    void calculate(const std::string &expression);
    ~RPN();
};







#endif