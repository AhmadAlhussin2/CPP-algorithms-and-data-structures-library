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

template<class T, class TGenerator>
static void BM_OrderedContainer(benchmark::State &state) {
    static_assert(std::is_base_of<OrderedContainer<int>, T>::value, "should be derived from ordered container class");

    for (auto _: state) {
        state.PauseTiming();
        std::vector<int> vec = TGenerator::generate(state.range(0));
        state.ResumeTiming();
        T ordered_container;
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
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, RandomDataGenerator)
        ->Name("Dynamic segment tree (random)")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, RandomDataGenerator)
        ->Name("Integers trie (random)")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, RandomDataGenerator)
        ->Name("boost set (random)")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

// reversed integers data

BENCHMARK_TEMPLATE(BM_OrderedContainer, Set<int>, ReversedIntGenerator)
        ->Name("Integers set (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, ReversedIntGenerator)
        ->Name("Dynamic segment tree (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, ReversedIntGenerator)
        ->Name("Integers trie (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, ReversedIntGenerator)
        ->Name("boost set (reversed list)")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));


BENCHMARK_MAIN();
