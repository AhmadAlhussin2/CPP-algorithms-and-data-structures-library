#ifndef BOOST_SET_H
#define BOOST_SET_H

#include <boost/container/flat_set.hpp>
#include "ordered_container.h"

template<typename T>
class BoostSet : public OrderedContainer<T> {
private:
    boost::container::flat_set<T> elements;

public:
    int size() const;
    bool empty() const;
    void clear();
    bool contains(const T &element) const;
    void insert(const T &key);
    void remove(T key);
    T getTheKthElement(int index) const;
};

template class BoostSet<int>;

#endif