#include <algorithm>

#include "reversed_string_list_generator.h"
#include "random_string_list_generator.h"

std::vector<std::string> ReversedStringListGenerator::generate(int size) {
    auto vec = RandomStringListGenerator().generate(size);
    std::sort(vec.begin(),vec.end());
    std::reverse(vec.begin(),vec.end());
    return vec;
}
