#include "segment_tree.h"
#include <stdexcept>

SegmentTreeSet::SegmentTreeSet(int size)
{
    tree = std::vector<int>(4 * (size+1), 0);
    _capacity = size;
}

int SegmentTreeSet::size() const
{
    return _size;
}

bool SegmentTreeSet::empty() const
{
    return _size == 0;
}

void SegmentTreeSet::clear()
{
    _size = 0;
    tree = std::vector<int>(4 * _size, 0);
}

void SegmentTreeSet::update(int v,int tl,int tr, int pos, int val)
{
    if (tl == tr)
    {
      tree[v] = val;
      return;
    }

    int mid = (tl + tr) / 2;
    if (pos <= mid)
    {
        update(v << 1, tl, mid, pos, val);
    }
    else
    {
        update(v << 1 | 1, mid + 1, tr, pos, val);
    }
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
}

int SegmentTreeSet::query(int v, int tl, int tr, int l, int r) const
{
    if (tl > r or tr < l)
    {
        return 0;
    }
    if (tl >= l and tr <= r)
    {
        return tree[v];
    }

    int mid = (tl + tr) / 2;
    return query(v << 1, tl, mid, l, r) + query(v << 1 | 1, mid + 1, tr, l, r);
}

bool SegmentTreeSet::contains(const int& element) const
{
    return SegmentTreeSet::query(1, 0, _capacity-1, element, element) != 0;
}

void SegmentTreeSet::insert(const int& element)
{
    SegmentTreeSet::update(1, 0, _capacity-1, element, 1);
}

void SegmentTreeSet::remove(int key)
{
    SegmentTreeSet::update(1, 0, _capacity-1, key, 0);
}


int SegmentTreeSet::getTheKthElement(int v, int tl, int tr, int k) const
{
    if (tl == tr)
    {
        return tl;
    }

    int mid = (tl + tr) / 2;
    if (tree[v << 1] <= k)
    {
        return getTheKthElement(v << 1, tl, mid, k);
    }

    return getTheKthElement(v << 1 | 1, mid + 1, tr, k - tree[v<<1]);
}

int SegmentTreeSet::getTheKthElement(int index) const
{
    if (tree[1] <= index)
    {
        throw std::out_of_range("index out of range");
    }

    return getTheKthElement(1, 0, _capacity-1, index);
}
