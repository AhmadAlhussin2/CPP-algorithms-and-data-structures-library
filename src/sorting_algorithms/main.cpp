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

const int STR_MIN = (1<<15);
const int STR_MAX = (1<<21);
const int MIN_INT = (1<<14);
const int MAX_INT = (1<<24);

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

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, HeapSort<int>, RandomIntegerListGenerator)
        ->Name("Integer Heap-Sort Random-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, HeapSort<int>, SemiSortedIntegerListGenerator)
        ->Name("Integer Heap-Sort Semi-Sorted-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, HeapSort<int>, ReversedIntegerListGenerator)
        ->Name("Integer Heap-Sort Reversed-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, RadixSort, RandomIntegerListGenerator)
        ->Name("Integer Radix-Sort Random-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, RadixSort, SemiSortedIntegerListGenerator)
        ->Name("Integer Radix-Sort Semi-Sorted-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, RadixSort, ReversedIntegerListGenerator)
        ->Name("Integer Radix-Sort Reversed-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, STLSort<int>, RandomIntegerListGenerator)
        ->Name("Integer Standard-Sort Random-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, STLSort<int>, SemiSortedIntegerListGenerator)
        ->Name("Integer Standard-Sort Semi-Sorted-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);

BENCHMARK_TEMPLATE(BM_IntegerSortingAlgorithms, STLSort<int>, ReversedIntegerListGenerator)
        ->Name("Integer Standard-Sort Reversed-Integer-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(MIN_INT, MAX_INT);


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
        ->Name("String Standard-Sort Random-String-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(STR_MIN, STR_MAX);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, HeapSort<std::string>, RandomStringListGenerator)
        ->Name("String Heap-Sort Random-String-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(STR_MIN, STR_MAX);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, STLSort<std::string>, SemiSortedStringListGenerator)
        ->Name("String Standard-Sort Semi-Sorted-String-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(STR_MIN, STR_MAX);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, HeapSort<std::string>, SemiSortedStringListGenerator)
        ->Name("String Heap-Sort Semi-Sorted-String-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(STR_MIN, STR_MAX);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, STLSort<std::string>, ReversedStringListGenerator)
        ->Name("String Standard-Sort Reversed-String-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(STR_MIN, STR_MAX);

BENCHMARK_TEMPLATE(BM_StringSortingAlgorithms, HeapSort<std::string>, ReversedStringListGenerator)
        ->Name("String Heap-Sort Reversed-String-List")
        ->Unit(benchmark::kMillisecond)
        ->RangeMultiplier(2)->Range(STR_MIN, STR_MAX);


BENCHMARK_MAIN();