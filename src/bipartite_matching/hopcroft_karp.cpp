#include "hopcroft_karp.h"

bool HopcroftKarp::dfs(const int u) {
  if (u != 0) {
    for (int i = 0; i < adjacency_metrix[u].size(); ++i) {
      if (const int v = adjacency_metrix[u][i]; dist[pairV[v]] == dist[u] + 1) {
        if (dfs(pairV[v]) == true) {
          pairV[v] = u;
          pairU[u] = v;
          return true;
        }
      }
    }
    dist[u] = INF;
    return false;
  }
  return true;
}

bool HopcroftKarp::bfs() {
  std::queue<int> Q;
  for (int u = 1; u <= m; u++) {
    if (pairU[u] == 0) {
      dist[u] = 0;
      Q.push(u);
    } else
      dist[u] = INF;
  }
  dist[0] = INF;
  while (!Q.empty()) {
    const int u = Q.front();
    Q.pop();
    if (dist[u] < dist[0]) {
      for (int i = 0; i < adjacency_metrix[u].size(); ++i) {
        if (const int v = adjacency_metrix[u][i]; dist[pairV[v]] == INF) {
          dist[pairV[v]] = dist[u] + 1;
          Q.push(pairV[v]);
        }
      }
    }
  }
  return (dist[0] != INF);
}

int HopcroftKarp::compute_max_bipartite_matching() {
  for (int u = 0; u < m; u++) {
    pairU[u] = 0;
  }
  for (int v = 0; v < n; v++) {
    pairV[v] = 0;
  }
  int result = 0;
  while (bfs()) {
    for (int u = 1; u <= m; u++)
      if (pairU[u] == 0 && dfs(u)) {
        result++;
      }
  }
  return result;
}

HopcroftKarp::HopcroftKarp(const Graph &graph) {
  n = m = 0;
  adjacency_metrix.resize(graph.size() + 2);
  std ::vector<int> nodes_label;
  nodes_label.resize(graph.size() + 2);
  for (int u = 0; u < graph.size(); u++) {
    if (graph.adjacency_matrix[u].empty()) {
      n++;
      nodes_label[u] = n;
    } else {
      m++;
      nodes_label[u] = m;
    }
  }
  for (int u = 0; u < graph.adjacency_matrix.size(); u++) {
    for (int v : graph.adjacency_matrix[u]) {
      adjacency_metrix[nodes_label[u]].push_back(nodes_label[v]);
    }
  }
  pairU.resize(m + 1);
  pairV.resize(n + 1);
  dist.resize(m + 1);
}
