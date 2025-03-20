#ifndef STL_SET_H
#define STL_SET_H

#include <set>
#include "ordered_container.h"

template<typename T>
class Set : public OrderedContainer<T> {
private:
    std::set<T> elements;

public:
    int size() const;
    bool empty() const;
    void clear();
    bool contains(const T &element) const;
    void insert(const T &key);
    void remove(int key);
    T getTheKthElement(int index) const;
};

template class Set<int>;
#endif // STL_SET_H
