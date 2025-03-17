#include "stl_set.h"
#include <set>
#include <stdexcept>

template<typename T>
int Set<T>::size() const {
  return elements.size();
}

template<typename T>
bool Set<T>::empty() const {
  return elements.empty();
}

template<typename T>
void Set<T>::clear() {
  elements.clear();
}

template<typename T>
bool Set<T>::contains(const T& element) const {
  return elements.find(element) != elements.end();
}

template<typename T>
void Set<T>::insert(const T& key) {
  elements.insert(key);
}

template<typename T>
void Set<T>::remove(int key) {
  elements.erase(key);
}

template<typename T>
T Set<T>::getTheKthElement(int index) const {
  if (index < 0 || index >= elements.size()) {
    throw std::out_of_range("index out of range");
  }

  auto it = elements.begin();
  for (int i = 1; i < index; i++) {
      it++;
  }
  return *it;
}
