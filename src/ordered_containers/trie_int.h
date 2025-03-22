#ifndef TRIE_INT_H
#define TRIE_INT_H

#include <vector>
#include "ordered_container.h"

class TrieInt : public OrderedContainer<int> {
private:
    struct Node {
        Node *children[2]{};
        int sum;
        Node() {
            children[0] = children[1] = nullptr;
            sum = 0;
        }
    };
    Node *root;
    const int MAX_BITS_SIZE = 30;
    void add_int(int x, int val);
    bool exists(int x) const;

public:
    TrieInt();
    int size() const;
    bool empty() const;
    void clear();
    bool contains(const int &element) const;
    void insert(const int &key);
    void remove(int key);
    int getTheKthElement(int index) const;
};

#endif // TRIE_INT_H
