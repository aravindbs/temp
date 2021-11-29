#ifndef COMMON_H
#define COMMON_H

#include<iostream>

class edge{
    public:
    int u,v;
    int bandwidth;
    edge(int u, int v, int bw);
};


class result{
    public:
    int *path;
    int length;
    int maximum_bandwidth;
    result(int *path, int len, int maximum_bandwidth);
    result();
};


class graph_node{
    public:
    int vertex;
    int weight;
    graph_node *next;
    graph_node(int v, int w);
};

#endif