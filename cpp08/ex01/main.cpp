#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Uncommenting the next line will throw an exception
        // sp.addNumber(12); // This will throw fullSpanException

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Span sp2 = Span(0); // This will throw tooManyNumberSpanException
        sp2.addNumber(1);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Span sp3 = Span(1);
        sp3.addNumber(5);
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl; // This will throw notEnoughNumbersException
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}