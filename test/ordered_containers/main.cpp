#include "dynamic_segment_tree.h"
#include "gtest/gtest.h"
#include "ordered_container.h"
#include "stl_set.h"
#include "trie_int.h"

template<typename OrderedContainer>
void test_int_ordered_containers(int count) {
    OrderedContainer container;
    for (int i = 0; i < count; i++) {
        container.insert(i);
    }
    EXPECT_EQ(container.size(), count);
    for (int i = 0; i < count; i++) {
        EXPECT_EQ(i, container.getTheKthElement(i));
    }
}

TEST(OrderedContainersTest, IntegerOrderedContainers) {
    int size_ = 100;
    test_int_ordered_containers<Set<int>>(size_);
    test_int_ordered_containers<DynamicSegmentTree>(size_);
    test_int_ordered_containers<TrieInt>(size_);
}
