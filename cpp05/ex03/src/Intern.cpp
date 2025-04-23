#include "./includes/Intern.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;

    std::string Forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (Intern::*formCreators[3])(std::string) = {
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createShrubberyCreationForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == Forms[i])
        {
            form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return form;
        }
    }

    std::cout << "Intern cannot create form: " << formName << std::endl;
    return NULL;
}
