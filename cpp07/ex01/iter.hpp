#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T> 
void iter(T *a, size_t len, void (*func)(T const &))
{
    for(int i = 0; i < len; i++)
        func(array[i]);
}

template <typename T> 
void iter(T *a, size_t len, void (*func)(T &))
{
    for(int i = 0; i < len; i++)
        func(array[i]);
}


#endif