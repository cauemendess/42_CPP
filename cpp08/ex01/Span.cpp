#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &other)
{
    *this = other;
}


Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_n = other._n;
		_v = other._v;
	}
	return (*this);
}

void Span::addNumber(int number)
{
    if(_v.size() >= _n)
        throw fullSpanException();
    _v.push_back(number);
}


int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw notEnoughNumbersException();

	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		int span = std::abs(sorted[i + 1] - sorted[i]);
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);

}


int Span::longestSpan()
{
	if (_v.size() < 2)
		throw notEnoughNumbersException();

	int max = *std::max_element(_v.begin(), _v.end());
	int min = *std::min_element(_v.begin(), _v.end());
	return std::abs(max - min);
}


Span::~Span()
{
}

const char *Span::tooManyNumberSpanException::what() const throw()
{
	return "Too many numbers in the constructor";
}

const char *Span::fullSpanException::what() const throw()
{
	return "The span is full";
}

const char *Span::noSpanException::what() const throw()
{
	return "There is no span to calculate";
}

const char *Span::notEnoughNumbersException::what() const throw()
{
	return "There are not enough numbers to calculate the span";
}

std:: vector<int> Span::getNumbers(void)
{
	return _v;
}