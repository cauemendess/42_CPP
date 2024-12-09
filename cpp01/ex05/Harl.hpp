#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

const std::string RED = "\033[31m";
const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BOLD = "\033[1m";
const std::string RESET = "\033[0m";

class Harl
{
private:
    void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	~Harl();
    Harl();
	void complain(std::string level);
};

#endif