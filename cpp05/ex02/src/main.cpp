#include "./includes/Bureaucrat.hpp"
<<<<<<< HEAD
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
=======
#include "./includes/Form.hpp"
#include <iostream>

>>>>>>> 946ccfbc1774ef307f2642ef362384c61f80cc13

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
<<<<<<< HEAD
    Bureaucrat lowRank("LowRank", 150);
    Bureaucrat highRank("HighRank", 1);

    ShrubberyCreationForm shrubbery("Garden");
    RobotomyRequestForm robotomy("Robot");
    PresidentialPardonForm pardon("Target");

    std::cout << BLUE << "Test 1: LowRank tries to sign all forms" << RESET << std::endl;
    try {
        lowRank.signForm(shrubbery);
        lowRank.signForm(robotomy);
        lowRank.signForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "Test 2: HighRank tries to execute unsigned forms" << RESET << std::endl;
    try {
        highRank.executeForm(shrubbery);
        highRank.executeForm(robotomy);
        highRank.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "Test 3: HighRank signs all forms" << RESET << std::endl;
    highRank.signForm(shrubbery);
    highRank.signForm(robotomy);
    highRank.signForm(pardon);

    std::cout << BLUE << "Test 4: LowRank tries to execute a signed Shrubbery form" << RESET << std::endl;
    try {
        lowRank.executeForm(shrubbery);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "Test 5: HighRank executes all signed forms" << RESET << std::endl;
    try {
        highRank.executeForm(shrubbery);
        highRank.executeForm(robotomy);
        highRank.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
=======
    try {
        std::cout << BLUE << "Test 1: Creating a valid Bureaucrat" << RESET << std::endl;
        Bureaucrat bureaucrat("John Doe", 2);
        std::cout << bureaucrat << std::endl;

        std::cout << BLUE << "Test 2: Creating a valid Form" << RESET << std::endl;
        Form form("Form A", 1, 5);
        std::cout << form << std::endl;

        std::cout << BLUE << "Test 3: Bureaucrat with insufficient grade trying to sign a Form" << RESET << std::endl;
        try {
            Bureaucrat lowRank("Low Rank", 10);
            lowRank.signForm(form);
        } catch (std::exception &e) {
            std::cerr << RED << "Error signing the form: " << e.what() << RESET << std::endl;
        }

        std::cout << BLUE << "Test 4: Creating a Form with an invalid grade (too high)" << RESET << std::endl;
        try {
            Form invalidFormHigh("Invalid Form High", 0, 5);
        } catch (std::exception &e) {
            std::cerr << RED << "Error creating form: " << e.what() << RESET << std::endl;
        }

        std::cout << BLUE << "Test 5: Creating a Form with an invalid grade (too low)" << RESET << std::endl;
        try {
            Form invalidFormLow("Invalid Form Low", 151, 5);
        } catch (std::exception &e) {
            std::cerr << RED << "Error creating form: " << e.what() << RESET << std::endl;
        }

        std::cout << BLUE << "Test 6: Bureaucrat promoted beyond the limit" << RESET << std::endl;
        try {
            Bureaucrat highRank("High Rank", 1);
            highRank.incrementGrade();
        } catch (std::exception &e) {
            std::cerr << RED << "Error promoting Bureaucrat: " << e.what() << RESET << std::endl;
        }

        std::cout << BLUE << "Test 7: Bureaucrat demoted beyond the limit" << RESET << std::endl;
        try {
            Bureaucrat lowRank("Low Rank", 150);
            lowRank.decrementGrade();
        } catch (std::exception &e) {
            std::cerr << RED << "Error demoting Bureaucrat: " << e.what() << RESET << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << RED << "Unexpected error: " << e.what() << RESET << std::endl;
    }

    return 0;
}
>>>>>>> 946ccfbc1774ef307f2642ef362384c61f80cc13
