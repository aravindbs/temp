#include <stdlib.h>
#include "common.h"

edge::edge(int u, int v, int bw):u(u),v(v),bandwidth(bw){

}

result::result(int *path, int len, int maximum_bandwidth):path(path),length(len),maximum_bandwidth(maximum_bandwidth){}
result::result(){}

graph_node::graph_node(int v, int w) : vertex(v), weight(w){
    next=NULL;
};