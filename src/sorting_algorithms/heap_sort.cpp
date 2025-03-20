#include "heap_sort.h"

template<typename T>
void HeapSort<T>::sort(std::vector<T> &data) {
    heapSort(data);
}


template<typename T>
void HeapSort<T>::heapSort(std::vector<T> &data) {
    const int n = data.size();

    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(data, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 1; --i) {
        std::swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

template<typename T>
void HeapSort<T>::heapify(std::vector<T> &data, const int n, const int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;

    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}


