#include "dense_bipartite_graph_generator.h"

Graph DenseBipartiteGraphGenerator::generate(const int node_count, int _) {
  auto result = Graph(node_count);
  for (int i = 0; i < node_count; i += 2) {
    for (int j = 1; j < node_count; j += 2) {
      result.add_direct_edge(i, j);
    }
  }
  return result;
}