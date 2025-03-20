#include "stl_sort.h"
#include <algorithm>

template<typename T>
void STLSort<T>::sort(std::vector<T> &data) {
    std::sort(data.begin(), data.end());
}

