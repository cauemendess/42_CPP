#include <iostream>
#include <string>


int main(int argc, char **argv)
{

    if(!argv[1])
    {
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
      return 1;
    }
    std::string text;
    for (int i = 1; i < argc; i++)
    {
        text = argv[i];
        for(char& c : text)
        {
          c = std::toupper(c);
        }
        std::cout << text;
    }
    std::cout << std::endl;
    return 0;
}

