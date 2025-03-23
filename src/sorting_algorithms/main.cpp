#include <chrono>
#include <benchmark/benchmark.h>
#include <vector>
#include <random>

#include "heap_sort.h"
#include "radix_sort.h"
#include "stl_sort.h"


std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l,int r){
    std::uniform_int_distribution < int > uid(l,r);
    return uid(rng);
}

static void BM_HeapSort(benchmark::State& state) {
    std::vector<int> vec(state.range(0));
    for(auto &v:vec) v = getRand(0,(1<<20));
    for(auto _: state) {
        auto sorter = HeapSort<int>();
        sorter.sort(vec);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_HeapSort)->Unit(benchmark::kMillisecond)->Arg((1<<5))->Arg((1<<10))->Arg((1<<20));

static void BM_STLSort(benchmark::State& state) {
    std::vector<int> vec(state.range(0));
    for(auto &v:vec) v = getRand(0,(1<<20));
    for(auto _: state) {
        auto sorter = STLSort<int>();
        sorter.sort(vec);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_STLSort)->Unit(benchmark::kMillisecond)->Arg((1<<5))->Arg((1<<10))->Arg((1<<22));


static void BM_RadixSort(benchmark::State& state) {
    std::vector<int> vec(state.range(0));
    for(auto &v:vec) v = getRand(0,(1<<20));
    for(auto _: state) {
        auto sorter = RadixSort();
        sorter.sort(vec);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_RadixSort)->Unit(benchmark::kMillisecond)->Arg((1<<5))->Arg((1<<10))->Arg((1<<22));

BENCHMARK_MAIN();