#ifndef SPAN_HPP
#define SPAN_HPP


# include <cmath>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <string>
# include <unistd.h>
# include <vector>
# include <algorithm>


class Span
{
private:
    unsigned int _n;
    std::vector<int> _v;

public:
    Span(unsigned int n);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    std::vector<int> getNumbers();
    class tooManyNumberSpanException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class fullSpanException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class noSpanException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class notEnoughNumbersException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

};



#endif