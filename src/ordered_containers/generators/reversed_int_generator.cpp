#include "reversed_int_generator.h"
#include <vector>

std::vector<int> ReversedIntGenerator::generate(int size) {
    std::vector<int> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = size - i;
    }
    return result;
}
