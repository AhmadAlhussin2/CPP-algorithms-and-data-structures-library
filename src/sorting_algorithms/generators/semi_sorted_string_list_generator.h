#pragma once
#include "string_list_generator.h"

class SemiSortedStringListGenerator : public StringListGenerator{
public:
    std::vector<std::string> generate(int size) override;
    ~SemiSortedStringListGenerator() override = default;
};



