// #include <bits/stdc++.h>
#include <ctime>
#include <iostream>
#include "dijkstra.h"
#include "graph_generator.h"
#include "kruskal.h"
#include "common.h"

using namespace std;

int unvisited=0, visited=1, fringe=2;
int MAX_NODES=5000;

void print_info(int s, int t, result r,vector<vector<int>> &adj_matrix){

    cout<<"Source: "<<s<<" Target: "<<t<<endl;
    cout<<"######################"<<endl;
    for(int i=0;i<r.length;i++){
        cout<<r.path[i]<<" ";
    }
    cout<<endl;
    cout<<"Max bw is: "<<r.maximum_bandwidth<<endl;
    cout<<"######################"<<endl<<endl;
}

void run_algos(graph_node **gh, edge** edges, int num_edges){
    srand(time(NULL));
	vector<vector<int>> adj_matrix(MAX_NODES,vector<int>(MAX_NODES,0));
    for(int i=0;i<5;i++){
        cout<<i+1<<"th iteration of source & target"<<endl<<endl;
        int s = rand() % MAX_NODES;
        int t = rand() % MAX_NODES;
        if(s==t){
            t=(s+1)%MAX_NODES;
        }
        // cout<<"source: "<<s<<" target: "<<t<<endl;
        
        clock_t t1;
        result r;
        float time_taken;
        t1 = clock();
        DijkstraWithoutHeap *dj_noh = new DijkstraWithoutHeap(MAX_NODES);
        r = dj_noh->find_max_bw_path(gh, s, t);
        time_taken = float(clock()-t1)/CLOCKS_PER_SEC;
        cout<<"Dijkstra without heap time taken is: "<<time_taken<<endl;
        print_info(s,t,r,adj_matrix);
        free(r.path);
        delete dj_noh;

        result r1;
        t1 = clock();
        DijkstraWithHeap *dj = new DijkstraWithHeap(MAX_NODES);
        r1 = dj->find_max_bw_path(gh, s, t);
        time_taken = float(clock()-t1)/CLOCKS_PER_SEC;
        cout<<"Dijkstra with heap time taken is: "<<time_taken<<endl;
        print_info(s,t,r1,adj_matrix);
        free(r1.path);
        delete dj;


        result r3;
        t1 = clock();
        kruskal *k = new kruskal();
        r3 = k->find_max_bw_path(edges, num_edges, MAX_NODES, s, t);
        time_taken = float(clock()-t1)/CLOCKS_PER_SEC;
        cout<<"kruskal time taken is: "<<time_taken<<endl;
        print_info(s,t,r3,adj_matrix);
        free(r3.path);
        delete k;
        // if(r.maximum_bandwidth!=r1.maximum_bandwidth){
        //     throw runtime_error("not correct!!");
        // }
    }
}

int main(){

    for(int i=0;i<5;i++){
        cout<<"********* "<<i<<"th iteration of graphs******"<<endl;
        graph_generator gh_obj1(6, MAX_NODES);
        graph_node **gh1 = gh_obj1.get_graph();
        edge** edges1 = gh_obj1.get_edges();
        graph_generator gh_obj2(1000,MAX_NODES);
        graph_node **gh2 = gh_obj2.get_graph();
        edge** edges2 = gh_obj2.get_edges();

        // for(int i=0;i<MAX_NODES;i++){
        //     cout<<"i: "<<i<<" ";
        //     for(auto j=gh1[i];j!=NULL;j=j->next){
        //         cout<<j->vertex<<"("<<j->weight<<")"<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;


        cout<<"For sparse graph:"<<endl;
        run_algos(gh1, edges1, gh_obj1.current_edges);
        cout<<"For dense graph:"<<endl;
        run_algos(gh2, edges2, gh_obj2.current_edges);


    }
}
