#include "semi_sorted_string_list_generator.h"

#include <algorithm>

#include "random_string_list_generator.h"

static std::random_device rd;
static std::mt19937 gen(rd());

std::vector<std::string> SemiSortedStringListGenerator::generate(int size) {
    auto vec = RandomStringListGenerator().generate(size);
    std::sort(vec.begin(),vec.end());

    std::uniform_real_distribution<double> swap_dist(0.1, 0.5);
    const auto swap_fraction = swap_dist(gen);

    const auto num_swaps = static_cast<int>(size * swap_fraction);
    std::uniform_int_distribution<int> index_dist(0, size - 1);
    for (int i = 0; i < num_swaps; ++i) {
        const int a = index_dist(gen);
        const int b = index_dist(gen);
        std::swap(vec[a], vec[b]);
    }

    return vec;
}
