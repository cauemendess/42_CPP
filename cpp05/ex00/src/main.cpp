#include "./includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat *bureaucrat = new Bureaucrat("John", 5);
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;

    try
    {
        bureaucrat->decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;

    try
    {
        bureaucrat->decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat << std::endl;
    
    Bureaucrat *bureaucrat1 = new Bureaucrat("Alphonse", 149);
    std::cout << *bureaucrat1 << std::endl;
    try
    {
        bureaucrat1->decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *bureaucrat1 << std::endl;
    try
    {
        bureaucrat1->decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete bureaucrat;
    delete bureaucrat1;
    return (0);
}