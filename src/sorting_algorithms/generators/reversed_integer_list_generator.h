#pragma once
#include "integer_list_generator.h"

class ReversedIntegerListGenerator : public IntegerListGenerator {
public:
    std::vector<int> generate(int size) override;
    ~ReversedIntegerListGenerator() override = default;
};