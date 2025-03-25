#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &rightSide);
    virtual ~Bureaucrat();
};

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}



#endif