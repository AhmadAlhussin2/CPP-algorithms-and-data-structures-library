#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include <vector>
#include <string>

// Abstract base class for sorting algorithms
template <typename T>
class SortingAlgorithm {
public:
    // Pure virtual function to be implemented by derived classes
    virtual void sort(std::vector<T>& data) = 0;

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~SortingAlgorithm() = default;
};


#endif //SORTING_ALGORITHM_H

