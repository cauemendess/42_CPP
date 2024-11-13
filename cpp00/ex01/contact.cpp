#include "phonebook.hpp"

bool	isDigits(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

void Contact::setFirstName(const std::string &f_name)
{
	while (f_name.empty())
	{
		std::cout << CYAN << "First name cannot be empty. Please enter a valid first name: " << RESET;
		std::string input;
		std::getline(std::cin, input);
		if (!input.empty())
		{
			this->f_name = input;
			break ;
		}
	}
	this->f_name = f_name;
}

void Contact::setLastName(const std::string &l_name)
{
	while (l_name.empty())
	{
		std::cout << CYAN << "Last name cannot be empty. Please enter a valid last name: " << RESET;
		std::string input;
		std::getline(std::cin, input);
		if (!input.empty())
		{
			this->l_name = input;
			break ;
		}
	}
	this->l_name = l_name;
}

void Contact::setNickname(const std::string &nickname)
{
	while (nickname.empty())
	{
		std::cout << CYAN << "Nickname cannot be empty. Please enter a valid nickname: " << RESET;
		std::string input;
		std::getline(std::cin, input);
		if (!input.empty())
		{
			this->nickname = input;
			break ;
		}
	}
	this->nickname = nickname;
}

void Contact::setPhone(const std::string &phone)
{
	while (phone.empty() || !isDigits(phone))
	{
		std::cout << CYAN << "Phone must contain only digits and cannot be empty. Please enter a valid phone number: " << RESET;
		std::string input;
		std::getline(std::cin, input);
		if (!input.empty() && isDigits(input))
		{
			this->phone = input;
			break ;
		}
	}
	this->phone = phone;
}

void Contact::setSecret(const std::string &secret)
{
	while (secret.empty())
	{
		std::cout << CYAN << "Secret cannot be empty. Please enter a valid secret: " << RESET;
		std::string input;
		std::getline(std::cin, input);
		if (!input.empty())
		{
			this->secret = input;
			break ;
		}
	}
	this->secret = secret;
}
