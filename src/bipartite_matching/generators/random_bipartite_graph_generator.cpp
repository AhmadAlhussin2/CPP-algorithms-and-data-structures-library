#include <chrono>
#include <random>
#include "src/graph/Graph.h"
#include "random_bipartite_graph_generator.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int get_rand(const int l, const int r) {
    std::uniform_int_distribution uid(l, r);
    return uid(rng);
}

Graph RandomBipartiteGraphGenerator::generate(const int node_count, const int edge_count) {
    Graph result(node_count);
    for (int i = 0; i < edge_count; i++) {
        int from_node = get_rand(0, node_count - 2);
        from_node = from_node + (from_node % 2 == 0); // odd node

        int to_node = get_rand(1, node_count - 1);
        to_node = to_node - (to_node % 2 == 1); // even node

        result.add_direct_edge(from_node, to_node);
    }
    return result;
}
