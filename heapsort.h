#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "common.h"
#include <iostream>

class heapsort{
    edge **heaparray;
    int num_edges;
    // void insert(edge *e1);
    void fix_heap_up(int size);
    void fix_heap_down(int size);
    void swap(int i, int j);

    public:
    heapsort(int edges, edge** array);
    void sort();
};

#endif