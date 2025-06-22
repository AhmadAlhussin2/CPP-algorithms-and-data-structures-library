#ifndef BOOST_EDMONDS_KARP
#define BOOST_EDMONDS_KARP

#include "src/graph/Graph.h"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>

class BoostEdmondsKarp {
private:
  typedef boost::adjacency_list_traits<>::vertex_descriptor Vertex;
  typedef boost::adjacency_list_traits<>::edge_descriptor Edge;
  typedef boost::adjacency_list<
      boost::vecS, boost::vecS, boost::directedS, boost::no_property,
      boost::property<
          boost::edge_capacity_t, int,
          boost::property<boost::edge_residual_capacity_t, int,
                          boost::property<boost::edge_reverse_t, Edge>>>>
      BoostGraph;
  BoostGraph m_graph;
  int s, t;

public:
  explicit BoostEdmondsKarp(const Graph &graph);
  int compute_max_bipartite_matching();
};

#endif // BOOST_EDMONDS_KARP