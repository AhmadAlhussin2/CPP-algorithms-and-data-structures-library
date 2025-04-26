//
// Created by sarhan on 4/25/25.
//

#include "sorted_int_generator.h"

std::vector<int> SortedIntGenerator::generate(int size) {
    std::vector<int> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = i;
    }
    return result;
}
