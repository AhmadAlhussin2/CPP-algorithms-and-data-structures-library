#ifndef STL_SORT_H
#define STL_SORT_H

#include "sorting_algorithm.h"

template<typename T>
class STLSort : SortingAlgorithm<T> {
public:
    void sort(std::vector<T> &vec) override;
};

template class STLSort<int>;
template class STLSort<std::string>;
#endif //STL_SORT_H
