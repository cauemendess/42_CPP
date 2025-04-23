#include <iostream>
#include <string>

const std::string RED = "\033[31m";
const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BOLD = "\033[1m";
const std::string RESET = "\033[0m";


int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << BOLD << CYAN << "Original string:" << RESET << std::endl;
	std::cout << GREEN << str << RESET << std::endl << std::endl;

	std::cout << BOLD << CYAN << "Adress of string:" << RESET << std::endl;
	std::cout << YELLOW << strPtr << RESET << std::endl << std::endl;
	
	std::cout << BOLD << CYAN << "Value of reference string:" << RESET << std::endl;
	std::cout << RED << strRef<< RESET << std::endl;
}
