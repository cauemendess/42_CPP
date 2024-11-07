#include <iostream>
#include <string>
#include "phonebook.hpp"


void searchContact(void)
{
    //...
}

void addContact(void)
{

    std::string name;
    std::cout << "Enter first name: ";
    std::getline(std::cin, name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, name);
}


int main(void)
{
    Phonebook phonebook;
    std::string command;
    std:: string name;
    while(true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if(command == "ADD")
            phonebook.addContact();
        else if(command == "SEARCH")
            phonebook.searchContact();
        else if(command == "EXIT")
            break ;
        else
            std::cout << "Unknown command. Please use 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
    }
    std::cout << "Program terminated." << std::endl;
}
