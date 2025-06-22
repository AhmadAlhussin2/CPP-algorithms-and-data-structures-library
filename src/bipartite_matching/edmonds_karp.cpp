#include "edmonds_karp.h"
#include <queue>

int EdmondsCarp::bfs(std::vector<int> &parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[0] = -2;
  std::queue<std::pair<int, int>> q;
  q.emplace(0, 1e9);
  while (!q.empty()) {
    const int cur = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int next : adjacency_matrix[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = std::min(flow, capacity[cur][next]);
        if (next == static_cast<int>(adjacency_matrix.size()) - 1) {
          return new_flow;
        }
        q.emplace(next, new_flow);
      }
    }
  }
  return 0;
}

EdmondsCarp::EdmondsCarp(const Graph &graph) {
  capacity.resize(graph.size() + 2);
  adjacency_matrix.resize(graph.size() + 2);
  for (int u = 0; u < graph.size(); u++) {
    for (const int v : graph.adjacency_matrix[u]) {
      capacity[u + 1][v + 1] = 1;
      adjacency_matrix[u + 1].push_back(v + 1);
    }
    if (!graph.adjacency_matrix[u].empty()) {
      capacity[0][u + 1] = 1;
      adjacency_matrix[0].push_back(u + 1);
    } else {
      capacity[u + 1][graph.size() + 1] = 1;
      adjacency_matrix[u + 1].push_back(graph.size() + 1);
    }
  }
}

int EdmondsCarp::compute_max_bipartite_matching() {
  int flow = 0;
  std::vector<int> parent(adjacency_matrix.size() + 2);
  int new_flow;
  const int t = static_cast<int>(adjacency_matrix.size()) - 1;
  while ((new_flow = bfs(parent))) {
    flow += new_flow;
    int cur = t;
    while (cur != 0) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}