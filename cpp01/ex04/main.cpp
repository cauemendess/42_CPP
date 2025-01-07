#include "Sed.hpp"

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return(1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    Sed action(s1, s2, filename);
    return(action.replace());


}