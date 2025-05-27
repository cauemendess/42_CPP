#include "Array.hpp"

void multiplyByTwo(int &elem);
void rot13(char const &c);


int main()
{
    
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
