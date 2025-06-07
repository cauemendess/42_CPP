#include "easyfind.hpp"
#include <iostream>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    
    try
    {
        std::cout << "Found value: " << toString(*easyfind(vec, 3)) << std::endl;
    } 
    catch (const std::runtime_error &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Found value: " << toString(*easyfind(vec, 7)) << std::endl;
    } 
    catch (const std::runtime_error &e) 
    {
        std::cerr << e.what() << std::endl;
    }
}