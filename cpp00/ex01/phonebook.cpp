#include <iostream>
#include <string>
#include "phonebook.hpp"

int main(void)
{
    std::string command;
    std:: string f_name, l_name, nickname, phone;
    while(true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if(command == "ADD")
        {
            std::cout << "Enter first name: ";
            std::getline(std::cin, f_name);
            std::cout << "Enter last name: ";
            std::getline(std::cin, l_name);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phone);
        }
        else if(command == "SEARCH")
        {
            continue ;
        }

        else if(command == "EXIT")
            break ;
        else
            std::cout << "Unknown command. Please use 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
    }
    std::cout << "Program terminated." << std::endl;
}
