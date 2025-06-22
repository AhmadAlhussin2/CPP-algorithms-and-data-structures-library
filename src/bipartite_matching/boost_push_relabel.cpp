#include "boost_push_relabel.h"

BoostPushRelabel::BoostPushRelabel(const Graph &graph) {
  const auto capacity = get(boost::edge_capacity, m_graph);
  const auto reverse_edge = get(boost::edge_reverse, m_graph);

  s = 0;
  t = graph.size() - 1;

  auto addEdge = [&](const Vertex u, const Vertex v) {
    Edge e, rev_e;
    bool inserted;
    tie(e, inserted) = boost::add_edge(u, v, m_graph);
    tie(rev_e, inserted) = boost::add_edge(v, u, m_graph);
    capacity[e] = 1;
    capacity[rev_e] = 0;
    reverse_edge[e] = rev_e;
    reverse_edge[rev_e] = e;
  };

  for (int u = 0; u < static_cast<int>(graph.adjacency_matrix.size()); u++) {
    for (const int v : graph.adjacency_matrix[u]) {
      addEdge(u + 1, v + 1);
    }
    if (!graph.adjacency_matrix[u].empty()) {
      addEdge(s, u + 1);
    } else {
      addEdge(u + 1, t);
    }
  }
}

int BoostPushRelabel::compute_max_bipartite_matching() {
  return push_relabel_max_flow(m_graph, s, t);
}
