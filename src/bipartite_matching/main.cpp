#include "boost_edmonds_karp.h"
#include "boost_push_relabel.h"

#include <benchmark/benchmark.h>

#include "dinic.h"
#include "edmonds_karp.h"
#include "generators/dense_bipartite_graph_generator.h"
#include "generators/random_bipartite_graph_generator.h"
#include "hopcroft_karp.h"
#include "src/graph/Graph.h"

template <typename TAlgorithm, typename TGenerator>
static void BM_OrderedContainer(benchmark::State &state) {
  auto node_count = state.range(0);
  auto edge_count = state.range(1);

  for (auto _ : state) {
    state.PauseTiming();
    Graph graph = TGenerator::generate(node_count, edge_count);
    state.ResumeTiming();
    TAlgorithm bipartite_algorithm(graph);
    bipartite_algorithm.compute_max_bipartite_matching();
  }
};

// BENCHMARK_TEMPLATE(BM_OrderedContainer, Dinic, RandomBipartiteGraphGenerator)
//     ->Name("Dinic (random bipartite graph)")
//     ->Unit(benchmark::kMillisecond)
//     ->Args({1 << 5, 1 << 5})
//     ->Args({1 << 8, 1 << 8})
//     ->Args({1 << 10, 1 << 10})
//     ->Args({1 << 12, 1 << 12})
//     ->Args({1 << 13, 1 << 13})
//     ->Args({1 << 15, 1 << 15})
//     ->Args({1 << 18, 1 << 18});
//
// BENCHMARK_TEMPLATE(BM_OrderedContainer, EdmondsCarp,
//                    RandomBipartiteGraphGenerator)
//     ->Name("EdmondsCarp (random bipartite graph)")
//     ->Unit(benchmark::kMillisecond)
//     ->Args({1 << 5, 1 << 5})
//     ->Args({1 << 8, 1 << 8})
//     ->Args({1 << 10, 1 << 10})
//     ->Args({1 << 12, 1 << 12})
//     ->Args({1 << 13, 1 << 13});
//
// BENCHMARK_TEMPLATE(BM_OrderedContainer, HopcroftKarp,
//                    RandomBipartiteGraphGenerator)
//     ->Name("Hopcroft (random bipartite graph)")
//     ->Unit(benchmark::kMillisecond)
//     ->Args({1 << 5, 1 << 5})
//     ->Args({1 << 8, 1 << 8})
//     ->Args({1 << 10, 1 << 10})
//     ->Args({1 << 12, 1 << 12})
//     ->Args({1 << 13, 1 << 13})
//     ->Args({1 << 15, 1 << 15})
//     ->Args({1 << 18, 1 << 18});
//
// BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostEdmondsKarp,
//                    RandomBipartiteGraphGenerator)
//     ->Name("Boost Edmonds Karp (random bipartite graph)")
//     ->Unit(benchmark::kMillisecond)
//     ->Args({1 << 5, 1 << 5})
//     ->Args({1 << 8, 1 << 8})
//     ->Args({1 << 10, 1 << 10})
//     ->Args({1 << 12, 1 << 12})
//     ->Args({1 << 13, 1 << 13})
//     ->Args({1 << 15, 1 << 15});
//
// BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostPushRelabel,
//                    RandomBipartiteGraphGenerator)
//     ->Name("Boost Push Relabel (random bipartite graph)")
//     ->Unit(benchmark::kMillisecond)
//     ->Args({1 << 5, 1 << 5})
//     ->Args({1 << 8, 1 << 8})
//     ->Args({1 << 10, 1 << 10})
//     ->Args({1 << 12, 1 << 12})
//     ->Args({1 << 13, 1 << 13})
//     ->Args({1 << 15, 1 << 15})
//     ->Args({1 << 18, 1 << 18});

BENCHMARK_TEMPLATE(BM_OrderedContainer, Dinic, DenseBipartiteGraphGenerator)
    ->Name("Dinic (dense bipartite graph)")
    ->Unit(benchmark::kMillisecond)
    ->Args({1 << 5, 1 << 5})
    ->Args({1 << 6, 1 << 6})
    ->Args({1 << 7, 1 << 7})
    ->Args({1 << 8, 1 << 8})
    ->Args({1 << 9, 1 << 9})
    ->Args({1 << 10, 1 << 10})
    ->Args({1 << 11, 1 << 11})
    ->Args({1 << 12, 1 << 12})
    ->Args({1 << 13, 1 << 13});

BENCHMARK_TEMPLATE(BM_OrderedContainer, EdmondsCarp,
                   DenseBipartiteGraphGenerator)
    ->Name("Edmonds Carp (dense bipartite graph)")
    ->Unit(benchmark::kMillisecond)
    ->Args({1 << 5, 1 << 5})
    ->Args({1 << 6, 1 << 6})
    ->Args({1 << 7, 1 << 7})
    ->Args({1 << 8, 1 << 8})
    ->Args({1 << 9, 1 << 9})
    ->Args({1 << 10, 1 << 10})
    ->Args({1 << 11, 1 << 11});

BENCHMARK_TEMPLATE(BM_OrderedContainer, HopcroftKarp,
                   DenseBipartiteGraphGenerator)
    ->Name("Hopcroft (dense bipartite graph)")
    ->Unit(benchmark::kMillisecond)
    ->Args({1 << 5, 1 << 5})
    ->Args({1 << 6, 1 << 6})
    ->Args({1 << 7, 1 << 7})
    ->Args({1 << 8, 1 << 8})
    ->Args({1 << 9, 1 << 9})
    ->Args({1 << 10, 1 << 10})
    ->Args({1 << 11, 1 << 11})
    ->Args({1 << 12, 1 << 12})
    ->Args({1 << 13, 1 << 13})
    ->Args({1 << 14, 1 << 14});

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostEdmondsKarp,
                   DenseBipartiteGraphGenerator)
    ->Name("Boost Edmonds Carp (dense bipartite graph)")
    ->Unit(benchmark::kMillisecond)
    ->Args({1 << 5, 1 << 5})
    ->Args({1 << 6, 1 << 6})
    ->Args({1 << 7, 1 << 7})
    ->Args({1 << 8, 1 << 8})
    ->Args({1 << 9, 1 << 9})
    ->Args({1 << 10, 1 << 10});

BENCHMARK_TEMPLATE(BM_OrderedContainer, BoostPushRelabel,
                   DenseBipartiteGraphGenerator)
    ->Name("Boost Push Relabel (dense bipartite graph)")
    ->Unit(benchmark::kMillisecond)
    ->Args({1 << 5, 1 << 5})
    ->Args({1 << 6, 1 << 6})
    ->Args({1 << 7, 1 << 7})
    ->Args({1 << 8, 1 << 8})
    ->Args({1 << 9, 1 << 9})
    ->Args({1 << 10, 1 << 10})
    ->Args({1 << 11, 1 << 11})
    ->Args({1 << 12, 1 << 12});

BENCHMARK_MAIN();