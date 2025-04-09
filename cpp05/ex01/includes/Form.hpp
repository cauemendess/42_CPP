#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>


class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &rightSide);
    std::string getName(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool getSigned(void) const;
    void beSigned(Bureaucrat const &bureaucrat);
	void execute(Bureaucrat const &executor) const;
    class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
    virtual ~Form();
};

std::ostream &operator<<(std::ostream &out, Form const &value);

#endif