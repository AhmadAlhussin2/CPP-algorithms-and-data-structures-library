//
// Created by sarhan on 3/23/25.
//

#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <vector>
#include "sorting_algorithm.h"

class RadixSort : SortingAlgorithm<int> {
public:
    void sort(std::vector<int>& data) override;
};
#endif //RADIX_SORT_H
