#include "Phonebook.hpp"

bool	isDigits(std::string str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}
void Contact::setFirstName(std::string f_name)
{
	while(f_name.empty())
	{
		std::cout << RED << "Error: The first name field cannot be empty." << RESET << std::endl;
		std::cout << GREEN << "Please insert the contact first name: " << RESET;
		std::getline(std::cin, f_name);
	}
	this->f_name = f_name;
}

void Contact::setLastName(std::string l_name)
{
	while(l_name.empty())
	{
		std::cout << RED << "Error: The last name field cannot be empty." << RESET << std::endl;
		std::cout << GREEN << "Please insert the contact last name: " << RESET;
		std::getline(std::cin, l_name);
	}
	this->l_name = l_name;
}

void Contact::setNickname(std::string nickname)
{
	while(nickname.empty())
	{
		std::cout << RED << "Error: The nickname field cannot be empty." << RESET << std::endl;
		std::cout << GREEN << "Please insert the contact nickname: " << RESET;
		std::getline(std::cin, nickname);
	}
	this->nickname = nickname;
}

void Contact::setPhone(std::string phone)
{
	while(phone.empty() || !isDigits(phone))
	{
		std::cout << RED << "Error: The phone field cannot be empty." << RESET << std::endl;
		std::cout << GREEN << "Please insert the contact phone number: " << RESET;
		std::getline(std::cin, phone);
	}
	this->phone = phone;
}

void Contact::setSecret(std::string secret)
{
	while(secret.empty())
	{
		std::cout << RED << "Error: The darkest secret field cannot be empty." << RESET << std::endl;
		std::cout << GREEN << "Please insert the darkest secret name: " << RESET;
		std::getline(std::cin, secret);
	}
	this->secret = secret;
}



