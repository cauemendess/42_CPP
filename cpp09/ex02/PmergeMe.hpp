#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

class PmergeMe {

private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    size_t _size;

    std::vector<int> vectorSort(std::vector<int> input);
    std::deque<int> dequeSort(std::deque<int> input);

    std::vector<size_t> getJacobsthalIndices(size_t n);


public:
    PmergeMe(std::vector<int> const &input);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void runVectorSort();
    void runDequeSort();
    void printBefore() const;
    
};

#endif