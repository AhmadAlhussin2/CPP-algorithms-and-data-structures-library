#pragma once

#include "integer_list_generator.h"

class SemiSortedIntegerListGenerator : public IntegerListGenerator {
public:
    std::vector<int> generate(int size) override;
    ~SemiSortedIntegerListGenerator() override = default;
};
