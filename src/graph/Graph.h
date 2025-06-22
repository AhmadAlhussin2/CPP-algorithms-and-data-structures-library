#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph {
private:
    int capacity;
public:
    std::vector<std::vector<int>> adjacency_matrix;
    explicit Graph(int capacity);
    void add_direct_edge(const int &from, const int &to);
    void add_undirected_edge(const int &from, const int &to);
    int size() const;
};

#endif //GRAPH_H
