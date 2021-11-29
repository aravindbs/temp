#ifndef DJK_H
#define DJK_H
#include <vector>
#include "graph_generator.h"
#include "heap.h"
extern int unvisited, visited, fringe;



class DijkstraWithoutHeap{
    private: 
    int *status, *cur_bw, *parent;
    int nodes_seen, nodes;
    public:

    DijkstraWithoutHeap(int nodes);
    ~DijkstraWithoutHeap();

    int get_node_fringe_max_bw();
    result find_max_bw_path(graph_node **gh, int s, int t);
};
class DijkstraWithHeap{
    private: 
    int *status, *cur_bw, *parent;
    int nodes_seen, nodes;

    Myheap heap;

    public:
    DijkstraWithHeap(int nodes);
    ~DijkstraWithHeap();

    int get_node_fringe_max_bw();
    result find_max_bw_path(graph_node **gh, int s, int t);
};
#endif