#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
#include "AForm.hpp"


class ShrubberyCreationForm: public AForm
{
  public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;

  private:
  	std::string _target;
};

#endif 