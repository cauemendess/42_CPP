#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

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

//classes
class Contact
{
private:
    std::string f_name;
    std::string l_name;
    std::string nickname;
    std::string phone;
    std::string secret;

public:
    //getters
    std::string getFirstName(void) const {
        return this->f_name;
    }
    std::string getLastName(void) const {
        return this->l_name;
    }
    std::string getNickname(void) const {
        return this->nickname;
    }
    std::string getPhone(void) const {
        return this->phone;
    }
    std::string getSecret(void) const {
        return this->secret;
    }

    //setter
    void setFirstName(const std::string& f_name) {
        this->f_name = f_name;
    }

    void setLastName(const std::string& l_name) {
        this->l_name = l_name;
    }

    void setNickname(const std::string& nickname) {
        this->nickname = nickname;
    }

    void setPhone(const std::string& phone) {
        this->phone = phone;
    }
    void setSecret(const std::string& secret) {
        this->secret = secret;
    }
    void displayContact(void);
};

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