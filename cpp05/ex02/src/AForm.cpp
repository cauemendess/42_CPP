#include "./includes/AForm.hpp"
#include "./includes/Bureaucrat.hpp"


AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm " << _name << " created" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm " << _name << " created" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "AForm " << _name << " created by copy" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm " << _name << " destroyed" << std::endl;
}

AForm &AForm::operator=(const AForm &rightSide)
{
    std::cout << "AForm Assignation operator called" << std::endl;
    if (this != &rightSide)
        this->_signed = rightSide._signed;
    return (*this);
}


std::string AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSigned(void) const
{
    return (this->_signed);
}

int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " executes " << this->_name << std::endl;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->_signed)
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}


const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("AForm is not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &value)
{
	out << "AForm " << value.getName() << " needs " << value.getGradeToSign() << " to be signed and is " << (value.getSigned() ? "signed" : "not signed");
	return (out);
}