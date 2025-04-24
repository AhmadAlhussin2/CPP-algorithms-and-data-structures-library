#pragma once
#include "string_list_generator.h"

class ReversedStringListGenerator : public StringListGenerator {
public:
    std::vector<std::string> generate(int size) override;
    ~ReversedStringListGenerator() override = default;
};