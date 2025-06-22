#ifndef RANDOM_BIPARTITE_GRAPH_GENERATOR_H
#define RANDOM_BIPARTITE_GRAPH_GENERATOR_H
#include "src/graph/Graph.h"

class RandomBipartiteGraphGenerator {
public:
    static Graph generate(int node_count, int edge_count);
};

#endif //RANDOM_BIPARTITE_GRAPH_GENERATOR_H