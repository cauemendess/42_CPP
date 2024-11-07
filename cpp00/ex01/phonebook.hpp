#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

const int MAX_CONTACTS = 8;


class Contact
{
private:
    std::string f_name;
    std::string l_name;
    std::string nickname;
    std::string phone;
    std::string secret

public:
    //getters
    std::string getFirstName(const std::string f_name){
        return f_name;
    }
    std::string getLastName(const std::string l_name){
        return l_name;
    }
    std::string getNickname(const std::string nickname){
        return nickname;
    }
    std::string getPhone(const std::string phone){
        return phone;
    }
    std::string getSecret(const std::string secret){
        return secret;
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
    void displayContact(int index);
};

class Phonebook
{
private:
    Contact _contacts[MAX_CONTACTS];
    int indexContacts = 0;
public:
    void addContact(void) const;
    void searchContact(void) const;
};



#endif