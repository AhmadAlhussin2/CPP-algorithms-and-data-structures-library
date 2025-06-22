#ifndef BOOST_PUSH_RELABEL_H
#define BOOST_PUSH_RELABEL_H

#include "src/graph/Graph.h"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

class BoostPushRelabel {
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
  explicit BoostPushRelabel(const Graph &graph);
  int compute_max_bipartite_matching();
};

#endif // BOOST_PUSH_RELABEL_H