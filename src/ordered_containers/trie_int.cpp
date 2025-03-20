#include "trie_int.h"

TrieInt::TrieInt() { root = new Node(); }

int TrieInt::size() const { return root->sum; }

bool TrieInt::empty() const { return root->sum == 0; }

void TrieInt::clear() {
    delete root;
    root = new Node();
}

bool TrieInt::contains(const int &element) const { return exists(element); }

void TrieInt::insert(const int &key) {
    if (exists(key)) {
        return;
    }

    add_int(key, 1);
}

void TrieInt::remove(int key) {
    if (!exists(key)) {
        return;
    }

    add_int(key, -1);
}

int TrieInt::getTheKthElement(int k) const {
    Node *cur = root;
    int result = 0;
    for (int i = MAX_BITS_SIZE; i >= 0; i--) {
        if (cur->children[0] && cur->children[0]->sum > k) {
            cur = cur->children[0];
        } else {
            k -= (cur->children[0] ? cur->children[0]->sum : 0);
            cur = cur->children[1];
            result += (1 << i);
        }
    }
    return result;
}

void TrieInt::add_int(int x, int val) {
    Node *cur = root;
    cur->sum += val;
    for (int i = MAX_BITS_SIZE; i >= 0; i--) {
        bool b = x & (1 << i);
        if (cur->children[b] == nullptr) {
            cur->children[b] = new Node();
        }
        cur = cur->children[b];
        cur->sum += val;
    }
}

bool TrieInt::exists(int x) const {
    Node *cur = root;
    for (int i = MAX_BITS_SIZE; i >= 0; i--) {
        bool b = x & (1 << i);
        if (cur->children[b] == nullptr) {
            return false;
        }
        cur = cur->children[b];
    }

    return true;
}
