#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

//colors
const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string RESET = "\033[0m";

//macros
const int MAX_CONTACTS = 8;

class Phonebook
{
private:
    Contact _contacts[MAX_CONTACTS];
    int _indexContacts;
    int _size;
public:
    Phonebook();
    ~Phonebook();
    void addContact(void);
    void searchContact(void);
};

#endif