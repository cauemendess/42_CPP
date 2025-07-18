#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> const &input) : _vector(input), _deque(input.begin(), input.end()), _size(input.size())
{
}

PmergeMe::~PmergeMe()
{
}


PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
	return (*this);
}

void PmergeMe::runVectorSort()
{
    clock_t start = clock();
    std::vector<int> sorted = vectorSort(_vector);
    clock_t end = clock();

    std::cout << "After:";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << " " << sorted[i];
    std::cout << std::endl;


    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _size << " elements with std::vector : " << duration << " us" << std::endl;
}

void PmergeMe::runDequeSort()
{
    clock_t start = clock();
    std::deque<int> sorted = dequeSort(_deque);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _size << " elements with std::deque : " << duration << " us" << std::endl;
}


std::vector<int> PmergeMe::vectorSort(std::vector<int> input)
{
    if(input.size() <= 1)
        return(input);
    
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> unpaired;

    for(size_t i = 0; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if(a > b) 
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if(input.size() % 2 == 1)
        unpaired.push_back(input[input.size() - 1]);

    std::vector<int> smaller, larger;
    for(size_t i = 0; i < pairs.size(); ++i)
    {
        smaller.push_back(pairs[i].first);
        larger.push_back(pairs[i].second);
    }

    std::vector<int> sorted = vectorSort(larger);
    
    std::vector<size_t> insert_order = getJacobsthalIndices(smaller.size());

    for (size_t i = 0; i < insert_order.size(); ++i) 
    {
        int val = smaller[insert_order[i]];
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
        sorted.insert(pos, val);
    }

    if (!unpaired.empty())
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), unpaired[0]);
        sorted.insert(pos, unpaired[0]);
    }
    return (sorted);
}


std::deque<int> PmergeMe::dequeSort(std::deque<int> input)
{

    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int, int> > pairs;
    std::deque<int> unpaired;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i];
        int b = input[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (input.size() % 2 == 1)
        unpaired.push_back(input[input.size() - 1]);

    std::deque<int> smaller, larger;
    for (size_t i = 0; i < pairs.size(); ++i) {
        smaller.push_back(pairs[i].first);
        larger.push_back(pairs[i].second);
    }

    std::deque<int> sorted = dequeSort(larger);

    std::vector<size_t> insert_order = getJacobsthalIndices(smaller.size());

    for (size_t i = 0; i < insert_order.size(); ++i) 
    {
	    int val = smaller[insert_order[i]];
	    std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
	    sorted.insert(pos, val);
    }

    if (!unpaired.empty()) {
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), unpaired[0]);
        sorted.insert(pos, unpaired[0]);
    }

    return sorted;
}

std::vector<size_t> PmergeMe::getJacobsthalIndices(size_t n)
{
	std::vector<size_t> indices;

	size_t j0 = 0, j1 = 1;
	if (n == 0)
		return indices;
	indices.push_back(1);

	while (true) 
    {
		size_t jn = j1 + 2 * j0;
		if (jn >= n)
			break;
		indices.push_back(jn);
		j0 = j1;
		j1 = jn;
	}

	std::vector<bool> used(n, false);
	for (size_t i = 0; i < indices.size(); ++i)
		used[indices[i]] = true;
	used[0] = true;

	std::vector<size_t> ordered_indices;
    
	for (size_t i = 0; i < n; ++i)
    {
		if (used[i])
			ordered_indices.push_back(i);
	}
	for (size_t i = 0; i < n; ++i)
    {
		if (!used[i])
			ordered_indices.push_back(i);
	}

	return ordered_indices;
}

void PmergeMe::printBefore() const
{
    std::cout << "Before:";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << " " << _vector[i];
    std::cout << std::endl;
}