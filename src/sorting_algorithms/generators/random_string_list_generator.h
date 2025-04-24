#pragma once

#include "string_list_generator.h"
class RandomStringListGenerator : public StringListGenerator {
public:
    std::vector<std::string> generate(int size) override;
    ~RandomStringListGenerator() override = default;
};



