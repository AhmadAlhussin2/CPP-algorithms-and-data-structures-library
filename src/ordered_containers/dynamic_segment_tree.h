#include <limits.h>
#include "ordered_container.h"

class DynamicSegmentTree : OrderedContainer<int> {
private:
    struct Node {
        Node *left_child = nullptr, *right_child = nullptr;
        int left = 0, right = 0;
        int sum = 0;
        Node() = default;

        Node(const int left, const int right) : left(left), right(right) {}

        void extend() {
            if (!left_child && left + 1 <= right) {
                const int mid = (left + right) / 2;
                left_child = new Node(left, mid);
                right_child = new Node(mid + 1, right);
            }
        }

        void add(int pos, int x) {
            extend();
            sum += x;
            if (left_child) {
                if (pos <= left_child->right) {
                    left_child->add(pos, x);
                } else {
                    right_child->add(pos, x);
                }
            }
        }

        int get_sum(int left_query, int right_query) {
            if (left > right_query || right < left_query) {
                return 0;
            }

            if (left >= left_query && right <= right_query) {
                return sum;
            }

            extend();
            return left_child->get_sum(left_query, right_query) + right_child->get_sum(left_query, right_query);
        }

        int getKthElement(int k) {
            extend();
            if (left == right) {
                return left;
            }

            if (k < left_child->sum) {
                return left_child->getKthElement(k);
            }

            return right_child->getKthElement(k - left_child->sum);
        }
    };
    Node *root;

public:
    DynamicSegmentTree();
    int size() const;
    bool empty() const;
    void clear();
    bool contains(const int &element) const;
    void insert(const int &key);
    void remove(int key);
    int getTheKthElement(int index) const;
};
