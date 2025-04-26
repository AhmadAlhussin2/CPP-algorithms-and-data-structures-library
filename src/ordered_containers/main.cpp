#include <benchmark/benchmark.h>
#include <climits>
#include <type_traits>
#include <vector>
#include "dynamic_segment_tree.h"
#include "ordered_container.h"
#include "stl_set.h"
#include "trie_int.h"
#include "generators/random_int_generator.h"
#include "generators/reversed_int_generator.h"
#include "boost_set.h"
#include "sorted_int_generator.h"

template<class TContainer, class TGenerator>
static void BM_OrderedContainer(benchmark::State &state) {
    static_assert(std::is_base_of<OrderedContainer<int>, TContainer>::value, "should be derived from ordered container class");
    std::vector<int> vec = TGenerator::generate(state.range(0));
    TContainer ordered_container;
    for (auto _: state) {
        for (auto &v: vec) {
            if (ordered_container.contains(v)) {
                ordered_container.remove(v);
            } else {
                ordered_container.insert(v);
            }
        }
    }
};

// random integers data

BENCHMARK_TEMPLATE(BM_OrderedContainer, Set<int>, RandomDataGenerator)
        ->Name("Integers set (random)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, RandomDataGenerator)
        ->Name("Dynamic segment tree (random)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, RandomDataGenerator)
        ->Name("Integers trie (random)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, RandomDataGenerator)
        ->Name("boost set (random)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 1'000'000);

// reversed integers data

BENCHMARK_TEMPLATE(BM_OrderedContainer, Set<int>, ReversedIntGenerator)
        ->Name("Integers set (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, ReversedIntGenerator)
        ->Name("Dynamic segment tree (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, ReversedIntGenerator)
        ->Name("Integers trie (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, ReversedIntGenerator)
        ->Name("boost set (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 1'000'000);

// sorted integer lists

BENCHMARK_TEMPLATE(BM_OrderedContainer, Set<int>, SortedIntGenerator)
        ->Name("Integers set (sorted list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, SortedIntGenerator)
        ->Name("Dynamic segment tree (sorted list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, SortedIntGenerator)
        ->Name("Integers trie (sorted list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 10'000'000);

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, SortedIntGenerator)
        ->Name("boost set (sorted list)")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(100'000, 1'000'000);
BENCHMARK_MAIN();
