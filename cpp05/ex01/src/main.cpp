#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"
#include <iostream>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
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
            std::cerr << RED << e.what() << RESET << std::endl;
        }

        std::cout << BLUE << "Test 4: Creating a Form with an invalid grade (too high)" << RESET << std::endl;
        try {
            Form invalidFormHigh("Invalid Form High", 0, 5);
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }

        std::cout << BLUE << "Test 5: Creating a Form with an invalid grade (too low)" << RESET << std::endl;
        try {
            Form invalidFormLow("Invalid Form Low", 151, 5);
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }

        std::cout << BLUE << "Test 6: Bureaucrat promoted beyond the limit" << RESET << std::endl;
        try {
            Bureaucrat highRank("High Rank", 1);
            highRank.incrementGrade();
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }

        std::cout << "Test 7: Bureaucrat demoted beyond the limit" << std::endl;
        try {
            Bureaucrat lowRank("Low Rank", 150);
            lowRank.decrementGrade();
        } catch (std::exception &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}