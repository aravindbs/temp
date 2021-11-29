#include "kruskal.h"
#include "common.h"
#include "union_find.h"
#include "graph_generator.h"

using namespace std;

bool kruskal::backtrack(int i, int &t, int *&path, int *&bw, int &pos, int *&visited, graph_node**&gh)
{
    visited[i]=1;
    if(i==t){
        return true;
    }

    for(auto j=gh[i];j!=NULL;j=j->next){
            int v=j->vertex;
            if(visited[v]==0){
                path[pos]=v;
                bw[pos]=j->weight;
                pos++;
                
                if(backtrack(v,t,path,bw,pos,visited, gh))
                {
                    return true;
                }
                pos--;
            }
    }

    return false;

}

result kruskal::find_max_bw_path(edge** edges, int num_edges, int num_nodes, int s, int t)
{
    class heapsort hs(num_edges, edges);
    union_find uf(num_nodes);
    hs.sort();
    graph_node **gh = new graph_node*[num_nodes];
    int *visited = new int[num_nodes];
    for(int i=0;i<num_nodes;i++){
        visited[i]=0;
        gh[i]=NULL;
    }

    for(int i=num_edges-1;i>=0;i--){
        edge *cur_edge = edges[i];
        int u=cur_edge->u;
        int v=cur_edge->v;
        int bw=cur_edge->bandwidth;
        if(!uf.check_cycle(u,v)){
            uf.custom_union(u,v);
            if(gh[u]==NULL){
                gh[u]=new graph_node(v, bw);
            }
            else{
                auto temp=new graph_node(v,bw);
                temp->next=gh[u];
                gh[u]=temp;
            }

            if(gh[v]==NULL){
                gh[v]=new graph_node(u,bw);
            }
            else{
                auto temp=new graph_node(u,bw);
                temp->next=gh[v];
                gh[v]=temp;
            }
            
        }
    }    


    int *path = (int *)malloc(sizeof(int)*num_nodes);
    int *bw = new int[num_nodes];
    int pos=1;

    backtrack(s, t, path, bw, pos, visited, gh);

    path[0]=s;

    for(int i=0;i<num_nodes;i++){
        auto j=gh[i];
        for(j=gh[i];j!=NULL;)
        {
            auto temp=j->next;
            delete j;
            j=temp;
        }
    }

    
    if(pos==1){
        throw runtime_error("could not find a path from s to t using kruskal!!");
    }

    int min_bw=num_nodes+1;
    for(int i=pos-1;i>=1;i--){
        min_bw=min(bw[i],min_bw);
    }

    delete[] gh;
    delete[] visited;
    delete[] bw;


    return result(path, pos, min_bw);
}
