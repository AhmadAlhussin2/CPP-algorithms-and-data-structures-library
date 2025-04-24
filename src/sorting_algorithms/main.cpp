#include <chrono>
#include <memory>
#include <benchmark/benchmark.h>
#include <vector>
#include <random>

#include "heap_sort.h"
#include "radix_sort.h"
#include "stl_sort.h"
#include "generators/integer_list_generator.h"
#include "generators/random_integer_list_generator.h"
#include "generators/reversed_integer_list_generator.h"
#include "generators/semi_sorted_integer_list_generator.h"



template<class TSortingAlgorithm, class TGenerator>
static void BM_SortingAlgorithms(benchmark::State& state) {
    static_assert(std::is_base_of_v<IntegerListGenerator, TGenerator>, "should be derived from IntegerListGenerator class");
    static_assert(std::is_base_of_v<SortingAlgorithm<int>, TSortingAlgorithm>, "should be derived from SortingAlgorithm base class");

    std::vector<int> vec = TGenerator().generate(state.range(0));
    TSortingAlgorithm sorter;
    for(auto _: state) {
        sorter.sort(vec);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, HeapSort<int>, RandomIntegerListGenerator)
        ->Name("Integer Heap Sort with Random Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, HeapSort<int>, SemiSortedIntegerListGenerator)
        ->Name("Integer Heap Sort with Semi Sorted Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, HeapSort<int>, ReversedIntegerListGenerator)
        ->Name("Integer Heap Sort with Reversed Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, RadixSort, RandomIntegerListGenerator)
        ->Name("Integer Radix Sort with Random Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, RadixSort, SemiSortedIntegerListGenerator)
        ->Name("Integer Radix Sort with Semi Sorted Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, RadixSort, ReversedIntegerListGenerator)
        ->Name("Integer Radix Sort with Reversed Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, STLSort<int>, RandomIntegerListGenerator)
        ->Name("Integer Standard Sort with Random Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, STLSort<int>, SemiSortedIntegerListGenerator)
        ->Name("Integer Standard Sort with Semi Sorted Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_SortingAlgorithms, STLSort<int>, ReversedIntegerListGenerator)
        ->Name("Integer Standard Sort with Reversed Integer List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'000, 10'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_MAIN();