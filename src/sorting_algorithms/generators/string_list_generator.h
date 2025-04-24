#pragma once

#include <random>
#include <string>
#include <vector>

class StringListGenerator {
public:
    static std::string random_string(int length, std::mt19937& gen) {
        static const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::uniform_int_distribution<> dist(0, (int)charset.size() - 1);

        std::string result;
        result.reserve(length);
        for (int i = 0; i < length; ++i) {
            result += charset[dist(gen)];
        }
        return result;
    }
    virtual std::vector<std::string> generate(int size) = 0;
    virtual ~StringListGenerator() = default;
};