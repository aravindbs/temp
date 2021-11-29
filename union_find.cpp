#include"union_find.h"
#include <malloc.h>

union_find::union_find(int nodes):num_nodes(nodes){
    parent=(int *)malloc(sizeof(int)*nodes);
    rank=(int *)malloc(sizeof(int)*nodes);
    for(int i=0;i<num_nodes;i++){
        parent[i]=-1;
        rank[i]=0;
    }
}

int union_find::find(int u){
    if(parent[u]==-1){
        return u;
    }
    parent[u]=find(parent[u]);
    return parent[u];
}

void union_find::custom_union(int u, int v){
    int p1=find(u);
    int p2=find(v);

    if(rank[p1]==rank[p2]){
        rank[p1]++;
        parent[p2]=p1;
    }
    else if(rank[p1]<rank[p2]){
        parent[p1]=p2;
    }
    else{
        parent[p2]=p1;
    }
}

bool union_find::check_cycle(int u, int v){
    
    int p1=find(u);
    int p2=find(v);

    if(p1==p2){
        return true;
    }

    return false;
}

union_find::~union_find(){
    free(rank);
    free(parent);
}
