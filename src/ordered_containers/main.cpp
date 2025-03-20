#include <benchmark/benchmark.h>
#include <chrono>
#include <random>
#include <type_traits>
#include <vector>
#include "dynamic_segment_tree.h"
#include "ordered_container.h"
#include "segment_tree.h"
#include "stl_set.h"
#include "trie_int.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
    std::uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

template<class T>
static void BM_OrderedContainer(benchmark::State &state) {
    static_assert(std::is_base_of<OrderedContainer<int>, T>::value, "should be derived from ordered container class");

    std::vector<int> vec(state.range(0));
    for (auto &v: vec) {
        v = getRand(0, (1 << 20));
    }

    for (auto _: state) {
        T ordered_container;
        for (auto &v: vec) {
            if (ordered_container.contains(v)) {
                ordered_container.remove(v);
            } else {
                ordered_container.insert(v);
            }
        }
    }
}

BENCHMARK(BM_OrderedContainer<Set<int>>)
        ->Name("Integers set")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK(BM_OrderedContainer<SegmentTreeSet>)
        ->Name("Segment tree")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK(BM_OrderedContainer<DynamicSegmentTree>)
        ->Name("Dynamic segment tree")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK(BM_OrderedContainer<TrieInt>)
        ->Name("Integers trie")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));


BENCHMARK_MAIN();
