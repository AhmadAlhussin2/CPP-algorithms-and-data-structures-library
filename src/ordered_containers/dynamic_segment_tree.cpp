#include "dynamic_segment_tree.h"

DynamicSegmentTree::DynamicSegmentTree() { root = new Node(0, 2000); }

int DynamicSegmentTree::size() const { return root->sum; }
bool DynamicSegmentTree::empty() const { return root->sum == 0; }
void DynamicSegmentTree::clear() {
    delete root;
    root = new Node(INT_MIN, INT_MAX);
}
bool DynamicSegmentTree::contains(const int &element) const { return root->get_sum(element, element) > 0; }
void DynamicSegmentTree::insert(const int &key) {
    if (contains(key)) {
        return;
    }

    root->add(key, 1);
}
void DynamicSegmentTree::remove(int key) {
    if (!contains(key)) {
        return;
    }

    root->add(key, -1);
}
int DynamicSegmentTree::getTheKthElement(int index) const { return root->getKthElement(index); }
