#include <malloc.h>
#include "common.h"

edge::edge(int u, int v, int bw):u(u),v(v),bandwidth(bw){

}

result::result(int *path, int len):path(path),length(len){}
result::result(){}

graph_node::graph_node(int v, int w) : vertex(v), weight(w){
    next=NULL;
};