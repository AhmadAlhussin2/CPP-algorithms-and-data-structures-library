#ifndef RANDOM_INT_GENERATOR
#define RANDOM_INT_GENERATOR

#include <vector>
#include <limits.h>

struct RandomDataGenerator
{
    static std::vector<int> generate(int size, int min_value = INT_MIN, int max_value = INT_MAX);
};

template<typename TResult>
class DataGenerator 
{
public:
    static std::vector<TResult> generate(int count);
};

#endif