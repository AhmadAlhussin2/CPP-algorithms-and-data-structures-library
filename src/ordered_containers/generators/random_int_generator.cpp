#include <random>
#include <chrono>
#include "random_int_generator.h"


std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int get_rand(int l, int r) {
    std::uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}


std::vector<int> RandomDataGenerator::generate(int size, int min_value, int max_value)
{
    std::vector<int> vec(size);
    for (auto &v:vec){
        v = get_rand(min_value, max_value);
    }
    return vec;
}
