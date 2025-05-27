#include "iter.hpp"

void multiplyByTwo(int &elem);
void rot13(char const &c);
    

int main()
{
    int iArray[] = {1, 2, 3, 4, 5};
    char cArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Iter an integer array" << std::endl;
    iter(iArray, 5, multiplyByTwo);
    iter(iArray, 5, printElement);
    std::cout << "=========================" << std::endl;
    std::cout << "Iter a char array" << std::endl;
    iter(cArray, 5, rot13);
}

void multiplyByTwo(int &elem)
{
    elem *= 2;
}

void rot13(char const &c)
{
    char result = c;

    if (result >= 'a' && result <= 'z')
        result = ((result - 'a' + 13) % 26) + 'a';
    else if (result >= 'A' && result <= 'Z')
        result = ((result - 'A' + 13) % 26) + 'A';

    printElement(result);
}
