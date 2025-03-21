#include <benchmark/benchmark.h>
#include <chrono>
#include <climits>
#include <random>
#include <type_traits>
#include <vector>
#include "dynamic_segment_tree.h"
#include "ordered_container.h"
#include "segment_tree.h"
#include "stl_set.h"
#include "trie_int.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int get_rand(int l, int r) {
    std::uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}


class DataGenerator
{
public:
    static std::vector<int> generate(int size, int min_value = INT_MIN, int max_value = INT_MAX);
};

struct RandomDataGenerator : DataGenerator
{
    static std::vector<int> generate(int size, int min_value = INT_MIN, int max_value = INT_MAX)
    {
        std::vector<int> vec(size);
        for (auto &v:vec){
            v = get_rand(min_value, max_value);
        }
        return vec;
    }
};


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

BENCHMARK_TEMPLATE(BM_OrderedContainer, Set<int>, RandomDataGenerator)
        ->Name("Integers set")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

// BENCHMARK_TEMPLATE(BM_OrderedContainer, SegmentTreeSet, RandomDataGenerator)
//         ->Name("Segment tree")
//         ->Unit(benchmark::kMillisecond)
//         ->Arg((1 << 5))
//         ->Arg((1 << 10))
//         ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, RandomDataGenerator)
        ->Name("Dynamic segment tree")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, RandomDataGenerator)
        ->Name("Integers trie")
        ->Unit(benchmark::kMillisecond)
        ->Arg((1 << 5))
        ->Arg((1 << 10))
        ->Arg((1 << 18));


BENCHMARK_MAIN();
