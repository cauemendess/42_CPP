#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Phonebook.hpp"

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
    void setFirstName(std::string f_name);
    void setLastName(std::string l_name);
    void setNickname(std::string nickname);
    void setPhone(std::string phone);
    void setSecret(std::string secret);
    void displayContact(void);
};

#endif