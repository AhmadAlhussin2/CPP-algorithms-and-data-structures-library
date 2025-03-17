#include <vector>
#include "ordered_container.h"

class SegmentTreeSet : OrderedContainer<int>
{
private:
    std::vector < int > tree;
    int _size, _capacity;
    void update(int v, int tl, int tr, int pos, int val);
    int query(int v, int tl, int tr, int l, int r) const;
    int getTheKthElement(int v, int tl, int tr, int k) const;
public:
    SegmentTreeSet(int size);
    int size() const;
    bool empty() const;
    void clear();
    bool contains(const int& element) const;
    void insert(const int& key);
    void remove(int key);
    int getTheKthElement(int index) const;
};
