#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sorting_algorithm.h"
template<typename T>
class HeapSort : SortingAlgorithm<T>{
public:
    void sort(std::vector<T>& data) override;
private:
    void heapify(std::vector<T>& data, int n, int i);

    void heapSort(std::vector<T>& data);
};

template class HeapSort<int>;
template class HeapSort<std::string>;
#endif //HEAP_SORT_H
