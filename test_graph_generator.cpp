#include <bits/stdc++.h>
#include "graph_generator.h"
#include "common.h"

using namespace std;

int main(){
    int degree=6, num_nodes=10;
    graph_generator gh_obj(degree, num_nodes);
    graph_node** gh=gh_obj.get_graph(); 


    int total_deg=0;
    vector<int> degrees(num_nodes);

    for(int i=0;i<num_nodes;i++){
        cout<<i<<":: ";
        degrees[i]=0;
        for(auto j=gh[i];j!=NULL;j=j->next){
            degrees[i]++;
            cout<<"v: "<<j->vertex<<":w"<<j->weight<<" ";
        }
        total_deg+=degrees[i];
        cout<<" degree: "<<degrees[i];
        cout<<endl;
    }
    cout<<"Avg degree: "<<total_deg/num_nodes<<endl;
    cout<<"***** Edges test******"<<endl;
    edge **edges = gh_obj.get_edges();
    total_deg=0;
    for(int i=0;i<num_nodes;i++){
        degrees[i]=0;
    }

    for(int i=0;i<gh_obj.current_edges;i++){
        degrees[edges[i]->v]++;
        degrees[edges[i]->u]++;
    }

    for(int i=0;i<num_nodes;i++){
        total_deg+=degrees[i];
    }
    cout<<"Avg degree: "<<total_deg/num_nodes<<endl;
}

