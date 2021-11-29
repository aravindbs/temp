#ifndef GRAPHG_H
#define GRAPHG_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "common.h"

using namespace std;

class graph_generator{
    private: 
    int avg_degree, num_nodes; 
    vector<vector<int>> unique_edges;
    graph_node **final_graph;

    public:
    int current_edges=0;
    edge** edges;

    graph_generator(int avg_degree, int num_nodes);  
    ~graph_generator();
    float get_avg_degree();
    void add_edge(int n1, int n2);
    graph_node** get_graph();
    edge** get_edges();
};


graph_node** get_graph(int degree, int num_nodes);


#endif