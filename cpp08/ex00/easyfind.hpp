#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <sstream>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in the container");
    }
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in the container");
    }
    return it;
}

template <typename T> std::string toString(const T &value)
{
	std::stringstream ss;
	ss << value;
	return (ss.str());
}


#endif