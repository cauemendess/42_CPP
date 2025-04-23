#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
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
