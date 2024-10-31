#ifndef PHONEBOOK
#define PHONEBOOK

const int MAX_CONTACTS = 8;


class Contact
{
public:
    std::string f_name;
    std::string l_name;
    std::string nickname;
    std::string phone;

    Contact() : f_name(""), l_name(""), nickname(""), phone() {}
    Contact(std::string f_name, std::string l_name, std::string nickname, std::string phone) : f_name(f_name), l_name(f_name), nickname(nickname), phone(phone) {}
};

class phonebook
{
private:
    Contact contacts[MAX_CONTACTS];
    int nb_of_contacts = 0;
public:
    phonebook(/* args */);
    ~phonebook();
};

phonebook::phonebook(/* args */)
{
}

phonebook::~phonebook()
{
}


#endif