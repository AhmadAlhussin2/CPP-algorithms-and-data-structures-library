#include "random_integer_list_generator.h"

#include <chrono>
#include <climits>
#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());
std::vector<int> RandomIntegerListGenerator::generate(int size) {
    std::vector<int> data(size);

    std::uniform_int_distribution<int> value_dist(INT_MIN, INT_MAX);

    for(auto &v:data) {
        v = (int)value_dist(gen);
    }
    return data;
}


