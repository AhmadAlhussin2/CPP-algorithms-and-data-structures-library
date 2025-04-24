#include "reversed_integer_list_generator.h"

#include <algorithm>
#include <numeric>

std::vector<int> ReversedIntegerListGenerator::generate(int size) {
    std::vector<int> vec(size);
    std::iota(vec.begin(),vec.end(),0);
    std::reverse(vec.begin(),vec.end());
    return vec;
}
