#ifndef UNION_H
#define UNION_H

class union_find{
    int *parent;
    int *rank;
    int num_nodes;

    public:
    union_find(int nodes);
    ~union_find();
    void custom_union(int u, int v);
    int find(int u);
    bool check_cycle(int u, int v);
};

#endif