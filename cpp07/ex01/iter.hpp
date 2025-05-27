#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>
#include <sstream>

template <typename T> 
void iter(T *array, size_t len, void (*func)(T const &))
{
    for(size_t i = 0; i < len; i++)
        func(array[i]);
}

template <typename T> 
void iter(T *array, size_t len, void (*func)(T &))
{
    for(size_t i = 0; i < len; i++)
        func(array[i]);
}

template <typename T>
std::string toString(const T &value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
void printElement(const T &element)
{
    std::cout << toString(element) << std::endl;
}




#endif