#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <sstream>


template <typename T>
void printElement(const T &element);

template <typename T>
std::string toString(const T &value);

template <typename T>
class Array {
private:
    T* _array;
    size_t _size;
public:
    Array() : _array(NULL), _size(0) {};
    Array(unsigned int n) : _array(new T[n]), _size(n) {};
    Array(const Array &other) : _array(NULL), _size(other._size) 
    {
        if (_size > 0)
        {
            _array = new T[_size];
            for (size_t i = 0; i < _size; ++i)
                _array[i] = other._array[i];
        }
    };
    Array &operator=(const Array &rightSide) 
    {
        if (this != &rightSide)
        {
            if (_array)
                delete[] _array;
            _size = rightSide._size;
            if (_size > 0)
            {
                _array = new T[_size];
                for (size_t i = 0; i < _size; ++i)
                    _array[i] = rightSide._array[i];
            }
            else
                _array = NULL;
        }
        return *this;
    };

    unsigned int size() const 
    {
        return _size;
    };

    const T &operator[](unsigned int index) const 
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return _array[index];
    };

    T &operator[](unsigned int index) 
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return _array[index];
    };
    ~Array() 
    {
        if (_array)
            delete[] _array;
    };

    class OutOfLimitsException: public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Index out of limits";
            }
    };

};

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