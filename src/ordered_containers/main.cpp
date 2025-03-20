#include <benchmark/benchmark.h>
#include <chrono>
#include <random>
#include <vector>
#include "dynamic_segment_tree.h"
#include "segment_tree.h"
#include "stl_set.h"
#include "trie_int.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
    std::uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

static void BM_IntegerSet(benchmark::State &state) {
    std::vector<int> vec(state.range(0));
    for (auto &v: vec)
        v = getRand(0, (1 << 20));

    for (auto _: state) {
        Set<int> st;
        for (auto &v: vec) {
            if (st.contains(v))
                st.remove(v);
            else
                st.insert(v);
        }
    }
}
// Register the function as a benchmark
BENCHMARK(BM_IntegerSet)->Unit(benchmark::kMillisecond)->Arg((1 << 5))->Arg((1 << 10))->Arg((1 << 18));


static void BM_IntegerSegmentTree(benchmark::State &state) {
    std::vector<int> vec(state.range(0));
    for (auto &v: vec)
        v = getRand(0, (1 << 20));

    for (auto _: state) {
        SegmentTreeSet st((1 << 20));
        for (auto &v: vec) {
            if (st.contains(v))
                st.remove(v);
            else
                st.insert(v);
        }
    }
}

BENCHMARK(BM_IntegerSegmentTree)->Unit(benchmark::kMillisecond)->Arg((1 << 5))->Arg((1 << 10))->Arg((1 << 18));

static void BM_IntegerTrie(benchmark::State &state) {
    std::vector<int> vec(state.range(0));
    for (auto &v: vec)
        v = getRand(0, (1 << 20));

    for (auto _: state) {
        TrieInt st;
        for (auto &v: vec) {
            if (st.contains(v))
                st.remove(v);
            else
                st.insert(v);
        }
    }
}
// Register the function as a benchmark
BENCHMARK(BM_IntegerTrie)->Unit(benchmark::kMillisecond)->Arg((1 << 5))->Arg((1 << 10))->Arg((1 << 18));

static void BM_DynamicSegmentTree(benchmark::State &state) {
    std::vector<int> vec(state.range(0));
    for (auto &v: vec)
        v = getRand(0, (1 << 20));

    for (auto _: state) {
        DynamicSegmentTree st;
        for (auto &v: vec) {
            if (st.contains(v))
                st.remove(v);
            else
                st.insert(v);
        }
    }
}
// Register the function as a benchmark
BENCHMARK(BM_DynamicSegmentTree)->Unit(benchmark::kMillisecond)->Arg((1 << 5))->Arg((1 << 10))->Arg((1 << 18));


BENCHMARK_MAIN();
