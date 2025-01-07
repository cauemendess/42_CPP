#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>


const std::string RED = "\033[31m";
const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BOLD = "\033[1m";
const std::string BLINK = "\033[5m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";


class Sed
{
private:
    std::string _s1;
    std::string _s2;
    std::string _filename;
public:
    Sed(std::string s1, std::string s2, std::string filename);
    void replace();
};




#endif