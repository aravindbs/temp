#ifndef KRUSKAL_H
#define KRUSKAL_H
#include"heapsort.h"
#include "common.h"

class kruskal{

    public: 
    result find_max_bw_path(edge** edges, int num_edges, int num_nodes, int s, int t);
    bool backtrack(int i, int &t, int *&path, int *&bw, int &pos, int *&visited, graph_node**&gh);
    
};

#endif