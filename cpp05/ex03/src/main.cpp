#include "./includes/Intern.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
    Intern someRandomIntern;
    AForm* form = NULL;

    std::cout << BLUE << "Test 1: Intern creates a ShrubberyCreationForm" << RESET << std::endl;
    try {
        form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        std::cout << GREEN << *form << RESET << std::endl;
        delete form;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "Test 2: Intern creates a RobotomyRequestForm" << RESET << std::endl;
    try {
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << GREEN << *form << RESET << std::endl;
        delete form;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "Test 3: Intern creates a PresidentialPardonForm" << RESET << std::endl;
    try {
        form = someRandomIntern.makeForm("presidential pardon", "Zoidberg");
        std::cout << GREEN << *form << RESET << std::endl;
        delete form;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "Test 4: Intern tries to create an unknown form" << RESET << std::endl;
    try {
        form = someRandomIntern.makeForm("invalid form", "Target");
        delete form;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
