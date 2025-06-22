#include "boost_set.h"
#include "dynamic_segment_tree.h"
#include "generators/random_int_generator.h"
#include "generators/reversed_int_generator.h"
#include "ordered_container.h"
#include "sorted_int_generator.h"
#include "stl_set.h"
#include "trie_int.h"
#include <benchmark/benchmark.h>
#include <climits>
#include <type_traits>
#include <vector>

const int MAX_INT = (1 << 21);
const int MIN_INT = (1 << 17);

template <class TContainer, class TGenerator>
static void BM_OrderedContainer(benchmark::State &state) {
  static_assert(std::is_base_of<OrderedContainer<int>, TContainer>::value,
                "should be derived from ordered container class");
  std::vector<int> vec = TGenerator::generate(state.range(0));
  TContainer ordered_container;
  for (auto _ : state) {
    for (auto &v : vec) {
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
    ->Name("Integer Standard-Set Random-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, RandomDataGenerator)
    ->Name("Integer Dynamic-Segment-Tree Random-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, RandomDataGenerator)
    ->Name("Integer Trie Random-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, RandomDataGenerator)
    ->Name("Integer Boost-set Random-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT / (1 << 2), MIN_INT);

// reversed integers data

BENCHMARK_TEMPLATE(BM_OrderedContainer, Set<int>, ReversedIntGenerator)
    ->Name("Integer Standard-Set Reversed-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree,
                   ReversedIntGenerator)
    ->Name("Integer Dynamic-Segment-Tree Reversed-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, ReversedIntGenerator)
    ->Name("Integer Trie Reversed-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, ReversedIntGenerator)
    ->Name("Integer Boost-Set Reversed-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT / (1 << 2), MIN_INT);

// sorted integer lists

BENCHMARK_TEMPLATE(BM_OrderedContainer, Set<int>, SortedIntGenerator)
    ->Name("Integer Standard-Set Sorted-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, DynamicSegmentTree, SortedIntGenerator)
    ->Name("Integer Dynamic-Segment-Tree Sorted-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, TrieInt, SortedIntGenerator)
    ->Name("Integer Trie Sorted-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT, MIN_INT);

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostSet<int>, SortedIntGenerator)
    ->Name("Integer Boost-Set Sorted-Integer-List")
    ->Unit(benchmark::kMillisecond)
    ->DenseRange(MIN_INT, MAX_INT / (1 << 2), MIN_INT);
BENCHMARK_MAIN();
