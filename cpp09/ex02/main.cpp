#include "PmergeMe.hpp"

bool validNumber(const std::string &expression)
{
    std::istringstream iss(expression);
    long long l;
    iss >> std::noskipws >> l;
    if (iss.eof() && !iss.fail())
    {
        return l > 0;
    }
    return false;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
		std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
		return 1;
	}

	std::vector<int> input;
	for (int i = 1; i < argc; ++i)
    {
        if(!validNumber(argv[i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int n = std::atoi(argv[i]);
		input.push_back(n);

    }

	PmergeMe sorter(input);
	sorter.printBefore();
	sorter.runVectorSort();
	sorter.runDequeSort();

	return 0;
}