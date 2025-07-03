#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
    std::cout << "Printing top of stack:" << std::endl;
	std::cout << mstack.top() << std::endl;

	mstack.pop();

    std::cout << "Printing size of stack after pop:" << std::endl;
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

    std::cout << "Iterating through the stack:" << std::endl;
	while (it != ite)
	{
	    std::cout << *it << std::endl;
	    ++it;
	}

	std::stack<int> s(mstack);
	return (0);
}

