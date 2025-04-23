#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_indexContacts = -1;
	this->_size = 0;
}
Phonebook::~Phonebook(void)
{
	return ;
}

std::string formatString(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::displayContact(void)
{
	std::cout << GREEN << "First name: " << RESET << this->f_name << std::endl;
	std::cout << GREEN << "Last name: " << RESET << this->l_name << std::endl;
	std::cout << GREEN << "Nickname: " << RESET << this->nickname << std::endl;
	std::cout << GREEN << "Phone number: " << RESET << this->phone << std::endl;
	std::cout << GREEN << "Darkest secret: " << RESET << this->secret << std::endl;
}

bool	indexIsValid(const std::string &index, int size)
{
	if (index.length() > 1 || !isdigit(index[0]) || index[0] - '0' > size
		|| index[0] - '0' < 1)
	{
		return (false);
	}
	return (true);
}

void Phonebook::searchContact(void)
{
	int	i;

	std::string index;
	if(_size == 0)
	{
		std::cout << RED << "No contact to search" << std::endl;
		return ;
	}
	i = 0;
	std::cout << std::setw(10) << "index"
				<< "|";
	std::cout << std::setw(10) << "First Name"
				<< "|";
	std::cout << std::setw(10) << "Last Name"
				<< "|";
	std::cout << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	while (i < this->_size)
	{
		std::cout << std::setw(10) << std::right << i + 1
					<< "|" << std::setw(10) << std::right << formatString(this->_contacts[i].getFirstName())
					<< "|" << std::setw(10) << std::right << formatString(this->_contacts[i].getLastName())
					<< "|" << std::setw(10) << std::right << formatString(this->_contacts[i].getNickname())
					<< std::endl;
		i++;
	}
	std::cout << CYAN << "Enter index: " << RESET;
	std::getline(std::cin, index);
	while (indexIsValid(index, this->_size) == false)
	{
		std::cout << RED << "Error: Invalid index!" << std::endl;
		std::cout << CYAN << "Enter valid index: " << RESET;
		std::getline(std::cin, index);
		std::cout << std::endl;
	}
	this->_contacts[index[0] - '0' - 1].displayContact();
}

void Phonebook::addContact(void)
{
	std::string name;
	if (_size == 8)
	{
		for (int i = 0; i < 7; i++)
		{
			this->_contacts[i] = this->_contacts[i + 1];
		}
		this->_indexContacts--;
		this->_size--;
	}
	this->_indexContacts++;
	this->_size++;
	std::cout << GREEN << "Enter first name: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_indexContacts].setFirstName(name);
	std::cout << GREEN << "Enter last name: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_indexContacts].setLastName(name);
	std::cout << GREEN << "Enter nickname: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_indexContacts].setNickname(name);
	std::cout << GREEN << "Enter phone number: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_indexContacts].setPhone(name);
	std::cout << GREEN << "Enter your darkest secret: " << RESET;
	std::getline(std::cin, name);
	this->_contacts[this->_indexContacts].setSecret(name);
}


