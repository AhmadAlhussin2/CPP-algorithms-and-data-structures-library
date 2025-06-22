//
// Created by ahmad on 4/20/25.
//

#include "Graph.h"

Graph::Graph(const int capacity) : capacity(capacity) {
    adjacency_matrix.resize(capacity);
}

void Graph::add_direct_edge(const int &from, const int &to) {
    adjacency_matrix[from].push_back(to);
}

void Graph::add_undirected_edge(const int &from, const int &to) {
    add_direct_edge(from, to);
    add_direct_edge(to, from);
}

int Graph::size() const {
    return capacity;
}
