#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
  public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &rhs);
	virtual ~Intern();

	AForm *makeForm(std::string formName, std::string target);
	AForm *createShrubberyCreationForm(std::string target);
	AForm *createRobotomyRequestForm(std::string target);
	AForm *createPresidentialPardonForm(std::string target);
};

#endif 