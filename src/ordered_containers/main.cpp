#include <chrono>
#include <benchmark/benchmark.h>
#include <vector>
#include <random>
#include "segment_tree.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l,int r){
    std::uniform_int_distribution < int > uid(l,r);
    return uid(rng);
}

static void BM_IntegerSet(benchmark::State& state) {
    std::vector<int> vec(state.range(0));
    for(auto &v:vec) v = getRand(0,(1<<20));

    for (auto _ : state) {
        std::set<int> st;
        for(auto  &v:vec) {
            // st.insert(v);
            if(st.find(v)!=st.end())st.erase(v);
            else st.insert(v);
        }
    }

}
// Register the function as a benchmark
BENCHMARK(BM_IntegerSet)->Unit(benchmark::kMillisecond)->Arg((1<<5))->Arg((1<<10))->Arg((1<<25));


static void BM_IntegerSegmentTree(benchmark::State& state) {
    std::vector<int> vec(state.range(0));
    for(auto &v:vec) v = getRand(0,(1<<20));

    for (auto _ : state) {
        SegTreeSum st((1<<20));
        for(auto  &v:vec) {
            // st.insert(v);
            if(st.contain(v))st.erase(v);
            else st.insert(v);
        }
    }

}
// Register the function as a benchmark
BENCHMARK(BM_IntegerSegmentTree)->Unit(benchmark::kMillisecond)->Arg((1<<5))->Arg((1<<10))->Arg((1<<25));
BENCHMARK_MAIN();