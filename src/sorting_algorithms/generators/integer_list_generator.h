#pragma once
#include <vector>

class IntegerListGenerator {
public:
    virtual std::vector<int> generate(int size) = 0;
    virtual ~IntegerListGenerator() = default;
};