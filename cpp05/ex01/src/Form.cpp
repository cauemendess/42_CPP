#include "./includes/Form.hpp"
#include "./includes/Bureaucrat.hpp"


Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form " << _name << " created" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form " << _name << " created" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form " << _name << " created by copy" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form &Form::operator=(const Form &rightSide)
{
    std::cout << "Form Assignation operator called" << std::endl;
    if (this != &rightSide)
        this->_signed = rightSide._signed;
    return (*this);
}


std::string Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSigned(void) const
{
    return (this->_signed);
}

int Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

void Form::execute(Bureaucrat const &executor) const
{
    if (!this->_signed)
        throw Form::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw Form::GradeTooLowException();
    std::cout << executor.getName() << " executes " << this->_name << std::endl;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->_signed)
        throw Form::FormNotSignedException();
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}


const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low");
}

const char *Form::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, Form const &value)
{
	out << "Form " << value.getName() << " needs " << value.getGradeToSign() << " to be signed and is " << (value.getSigned() ? "signed" : "not signed");
	return (out);
}