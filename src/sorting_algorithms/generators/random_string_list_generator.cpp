#include "random_string_list_generator.h"

static std::random_device rd;
static std::mt19937 gen(rd());

std::vector<std::string> RandomStringListGenerator::generate(int size) {
    const int total_chars = 100 * size;
    std::vector<std::string> result;
    result.reserve(size);

    std::uniform_int_distribution<> length_dist(50, 1000);  // Random lengths around 100

    int chars_left = total_chars;

    for (int i = 0; i < size; ++i) {
        const int remaining_strings = size - i;
        const int max_len = chars_left - (remaining_strings - 1) * 80;
        const int len = std::min(length_dist(gen), max_len);
        result.push_back(random_string(len, gen));
        chars_left -= len;
    }
    return result;
}
