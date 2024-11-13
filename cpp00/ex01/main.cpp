#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;

	std::string command;
	std::string name;
	while (true)
	{
		std::cout << MAGENTA << "Enter a command: " << RESET;
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
			phonebook.addContact();
		else if (command == "SEARCH" || command == "search")
			phonebook.searchContact();
		else if (command == "EXIT" || command == "exit")
			break ;
		else
			std::cout << "Unknown command. Please use 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
	}
	std::cout << "Program terminated." << std::endl;
}
