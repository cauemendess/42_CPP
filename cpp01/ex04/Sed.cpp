#include "Sed.hpp"


Sed::Sed(std::string s1, std::string s2, std::string filename) : _s1(s1), _s2(s2), _filename(filename)
{
}

void Sed::replace()
{
    std::ifstream inputFile(this->_filename.c_str());
    //verificação do inputfile
    std::string outputFileName = this->_filename + ".replace";
    std::ofstream outputFile(outputFileName.c_str());
    
    std::string line;
    while(std::getline(inputFile, line))
    {
        size_t pos = 0;
        while((pos = line.find(this->_s1, pos)) != std::string::npos)
        {
            std::string newLine = line.substr(0, pos) + this->_s2 + line.substr(pos + this->_s1.length());

            line = newLine;
            pos += this->_s2.length();
        }
        outputFile << line << std::endl;
    }
    outputFile.close();
    inputFile.close();

}