#include "boost_set.h"
#include <stdexcept>

template<typename T>
int BoostSet<T>::size() const {
    return elements.size();
}

template<typename T>
bool BoostSet<T>::empty() const {
    return elements.empty();
}

template<typename T>
void BoostSet<T>::clear() {
    elements.clear();
}

template<typename T>
bool BoostSet<T>::contains(const T &element) const {
    return elements.contains(element);
}

template<typename T>
void BoostSet<T>::insert(const T &key) {
    elements.insert(key);
}

template<typename T>
void BoostSet<T>::remove(T key) {
    elements.erase(key);
}

template<typename T>
T BoostSet<T>::getTheKthElement(int index) const {
    if (index < 0 || index >= elements.size()) {
        throw std::out_of_range("index out of range");
    }
    
    auto result = elements.begin() + index;
    return *result;
}
