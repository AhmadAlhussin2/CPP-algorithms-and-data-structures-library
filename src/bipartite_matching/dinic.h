#ifndef DINIC_H
#define DINIC_H

#include <climits>
#include <vector>

#include "src/graph/Graph.h"

class Dinic {
private:
    struct FlowEdge{
        int u,v,capacity;
        int flow=0;
        FlowEdge(const int u, const int v, const int capacity): u(u), v(v), capacity(capacity) {}
    };
    const int INF=INT_MAX;
    std::vector < FlowEdge > edges;
    std::vector < std::vector < int > > adj;
    std::vector < int > levels,ptr;
    int size,m=0;
    void add_edge(int from, int to);
    bool bfs(int source, int sink);
    int dfs(int u, int flow, int source, int sink);
    explicit Dinic(int size);
public:
    explicit Dinic(const Graph &bipartite_graph);
    int compute_max_bipartite_matching();
};

#endif //DINIC_H
