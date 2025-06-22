#include "dinic.h"
#include <queue>

Dinic::Dinic(const int size) : size(size) {
  adj.resize(size);
  levels.resize(size);
  ptr.resize(size);
}

Dinic::Dinic(const Graph &bipartite_graph) : Dinic(bipartite_graph.size() + 2) {
  const int source = 0;
  const int sink = bipartite_graph.size() + 1;
  for (int u = 0; u < bipartite_graph.adjacency_matrix.size(); u++) {
    for (const int v : bipartite_graph.adjacency_matrix[u]) {
      add_edge(u + 1, v + 1);
    }
    if (!bipartite_graph.adjacency_matrix[u]
             .empty()) // nodes with outgoing edges are group A
    {
      add_edge(source, u + 1);
    } else // other nodes are group B
    {
      add_edge(u + 1, sink);
    }
  }
}

void Dinic::add_edge(int from, int to) {
  edges.emplace_back(from, to, 1);
  edges.emplace_back(to, from, 0);
  adj[from].push_back(m);
  adj[to].push_back(m + 1);
  m += 2;
}

bool Dinic::bfs(const int source, const int sink) {
  std::queue<int> q;
  q.push(source);
  fill(levels.begin(), levels.end(), -1);
  levels[source] = 0;
  while (!q.empty()) {
    const int tmp = q.front();
    q.pop();
    for (const int id : adj[tmp]) {
      if (edges[id].capacity - edges[id].flow <= 0) {
        continue;
      }
      if (levels[edges[id].v] != -1) {
        continue;
      }
      levels[edges[id].v] = levels[tmp] + 1;
      q.push(edges[id].v);
    }
  }
  return levels[sink] != -1;
}

int Dinic::dfs(const int u, const int flow, const int source, const int sink) {
  if (flow == 0) {
    return 0;
  }

  if (u == sink) {
    return flow;
  }

  for (int &cid = ptr[u]; cid < adj[u].size(); cid++) {
    const int id = adj[u][cid];
    const int v = edges[id].v;
    if (levels[v] != levels[u] + 1) {
      continue;
    }

    if (edges[id].capacity - edges[id].flow <= 0) {
      continue;
    }

    const int ret = dfs(v, std::min(flow, edges[id].capacity - edges[id].flow),
                        source, sink);
    if (ret == 0) {
      continue;
    }

    edges[id].flow += ret;
    edges[id ^ 1].flow -= ret;
    return ret;
  }
  return 0;
}

int Dinic::compute_max_bipartite_matching() {
  const int source = 0, sink = size - 1;
  int f = 0;
  while (bfs(source, sink)) {
    fill(ptr.begin(), ptr.end(), 0);
    while (const int flow = dfs(source, INF, source, sink)) {
      f += flow;
    }
  }
  return f;
}
