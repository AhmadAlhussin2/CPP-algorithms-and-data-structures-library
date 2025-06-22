#ifndef HOPCROFT_KARP_H
#define HOPCROFT_KARP_H

#include "src/graph/Graph.h"
#include <climits>
#include <queue>
#include <vector>

class HopcroftKarp {
private:
  std::vector<std::vector<int>> adjacency_metrix;
  std::vector<int> pairU, pairV, dist;
  const int INF = INT_MAX;
  int n, m;
  bool dfs(int u);
  bool bfs();

public:
  explicit HopcroftKarp(const Graph &graph);
  int compute_max_bipartite_matching();
};

#endif // HOPCROFT_KARP_H