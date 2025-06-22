#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#include "src/graph/Graph.h"
#include <map>
#include <vector>

class EdmondsCarp {
private:
  std::vector<std::vector<int>> adjacency_matrix;
  std::vector<std::map<int, int>> capacity;
  int bfs(std::vector<int> &parent);

public:
  explicit EdmondsCarp(const Graph &graph);
  int compute_max_bipartite_matching();
};

#endif // EDMONDS_KARP_H
