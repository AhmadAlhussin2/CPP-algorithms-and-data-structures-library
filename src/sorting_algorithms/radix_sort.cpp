#include "radix_sort.h"

void RadixSort::sort(std::vector<int> &data) {
    if (data.empty()) return;

    const int base = 256;  // Using base 256 for efficient byte-wise sorting
    const int max_bits = 32; // Maximum bits in an integer

    std::vector<int> buffer(data.size());
    for (int shift = 0; shift < max_bits; shift += 8) {
        std::vector<int> count(base, 0);

        for (int num : data) {
            int byte = (num >> shift) & (base - 1);
            count[byte]++;
        }

        for (int i = 1; i < base; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = data.size() - 1; i >= 0; --i) {
            int byte = (data[i] >> shift) & (base - 1);
            buffer[--count[byte]] = data[i];
        }

        data.swap(buffer);
    }
}

