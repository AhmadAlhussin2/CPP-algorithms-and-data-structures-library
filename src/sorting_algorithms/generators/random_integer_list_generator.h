#pragma once
#include "integer_list_generator.h"

class RandomIntegerListGenerator : public IntegerListGenerator {
public:
    std::vector<int> generate(int size) override;
    ~RandomIntegerListGenerator() override = default;
};

