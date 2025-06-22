#ifndef DENSE_BIPARTITE_GRAPH_GENERATOR_H
#define DENSE_BIPARTITE_GRAPH_GENERATOR_H
#include "src/graph/Graph.h"

class DenseBipartiteGraphGenerator {
public:
  static Graph generate(int node_count, int _ = 0);
};

#endif // DENSE_BIPARTITE_GRAPH_GENERATOR_H