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
#include "generators/random_string_list_generator.h"
#include "generators/reversed_integer_list_generator.h"
#include "generators/reversed_string_list_generator.h"
#include "generators/semi_sorted_integer_list_generator.h"
#include "generators/semi_sorted_string_list_generator.h"
#include "generators/string_list_generator.h"


template<class TSortingAlgorithm, class TGenerator>
static void BM_IntegerSortingAlgorithms(benchmark::State& state) {
    static_assert(std::is_base_of_v<IntegerListGenerator, TGenerator>, "should be derived from IntegerListGenerator class");
    static_assert(std::is_base_of_v<SortingAlgorithm<int>, TSortingAlgorithm>, "should be derived from SortingAlgorithm base class");

    std::vector<int> vec = TGenerator().generate(state.range(0));
    TSortingAlgorithm sorter;
    for(auto _: state) {
        sorter.sort(vec);
    }

    state.SetComplexityN(state.range(0));
}

// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, HeapSort<int>, RandomIntegerListGenerator)
//         ->Name("Integer Heap Sort with Random Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, HeapSort<int>, SemiSortedIntegerListGenerator)
//         ->Name("Integer Heap Sort with Semi Sorted Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, HeapSort<int>, ReversedIntegerListGenerator)
//         ->Name("Integer Heap Sort with Reversed Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, RadixSort, RandomIntegerListGenerator)
//         ->Name("Integer Radix Sort with Random Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, RadixSort, SemiSortedIntegerListGenerator)
//         ->Name("Integer Radix Sort with Semi Sorted Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, RadixSort, ReversedIntegerListGenerator)
//         ->Name("Integer Radix Sort with Reversed Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, STLSort<int>, RandomIntegerListGenerator)
//         ->Name("Integer Standard Sort with Random Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, STLSort<int>, SemiSortedIntegerListGenerator)
//         ->Name("Integer Standard Sort with Semi Sorted Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);
//
// BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, STLSort<int>, ReversedIntegerListGenerator)
//         ->Name("Integer Standard Sort with Reversed Integer List")
//         ->Unit(benchmark::kMillisecond)
//         ->RangeMultiplier(10)->Range(10'000, 10'000'000)
//         ->Complexity(benchmark::oN);


template<class TSortingAlgorithm, class TGenerator>
static void BM_StringSortingAlgorithms(benchmark::State& state) {
        static_assert(std::is_base_of_v<StringListGenerator, TGenerator>, "should be derived from IntegerListGenerator class");
        static_assert(std::is_base_of_v<SortingAlgorithm<std::string>, TSortingAlgorithm>, "should be derived from SortingAlgorithm base class");

        auto vec = TGenerator().generate(state.range(0));
        TSortingAlgorithm sorter;
        for(auto _: state) {
                sorter.sort(vec);
        }

        state.SetComplexityN(state.range(0));
}

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, STLSort<std::string>, RandomStringListGenerator)
        ->Name("String Standard Sort with Random String List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'0000, 1'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, HeapSort<std::string>, RandomStringListGenerator)
        ->Name("String Heap Sort with Random String List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'0000, 1'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, STLSort<std::string>, SemiSortedStringListGenerator)
        ->Name("String Standard Sort with Semi Sorted String List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'0000, 1'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, HeapSort<std::string>, SemiSortedStringListGenerator)
        ->Name("String Heap Sort with Semi Sorted String List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'0000, 1'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, STLSort<std::string>, ReversedStringListGenerator)
        ->Name("String Standard Sort with Reversed String List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'0000, 1'000'000)
        ->Complexity(benchmark::oN);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, HeapSort<std::string>, ReversedStringListGenerator)
        ->Name("String Heap Sort with Reversed String List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(10)->Range(10'0000, 1'000'000)
        ->Complexity(benchmark::oN);


BENCHMARK_MAIN();