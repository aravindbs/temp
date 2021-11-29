#include <bits/stdc++.h>
#include "dijkstra.h"
#include "graph_generator.h"
#include "kruskal.h"

using namespace std;

void printv(vector<int> &v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int unvisited=0, visited=1, fringe=2;
int MAX_NODES=50;

int main(){
    vector<vector<int>> test_graph={
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
        };

    int n = test_graph.size();
    graph_node ** test_graph_final = new graph_node*[test_graph.size()];
    int num_edges = 14;
    edge** edges = new edge*[num_edges];

    unordered_set<string> st;
    int pos=0;
    for(int i=0;i<n;i++){
        test_graph_final[i]=NULL;
    }
    for(int i=0;i<test_graph.size();i++){
        for(int j=0;j<test_graph[i].size();j++){
            if(test_graph[i][j]!=0){
                if(test_graph_final[i]==NULL){
                    test_graph_final[i]=new graph_node(j, test_graph[i][j]);
                }
                else{
                    auto temp = new graph_node(j, test_graph[i][j]);
                    temp->next = test_graph_final[i];
                    test_graph_final[i] = temp;
                }
                string key = to_string(j)+to_string(i);
                cout<<key<<endl;
                if(st.find(key)==st.end()){
                    edges[pos]=new edge(i,j,test_graph[i][j]);
                    st.insert(to_string(i)+to_string(j));
                    pos++;
                }
            }
        }
    }

    vector<vector<int>> test_source_target={{0,8},{0,3}};
    vector<vector<int>> ans_paths={{0,7,8},{0,7,1,2,3}};

    DijkstraWithoutHeap djnoh(test_graph.size());
    DijkstraWithHeap dj(test_graph.size());
    for(int i=0;i<test_source_target.size();i++){
        auto v = test_source_target[i];
        
        // without heap
        result r = djnoh.find_max_bw_path(test_graph_final, v[0], v[1]);
        vector<int> path(r.path, r.path+r.length);
        cout << "ans_paths" << endl;
        printv(ans_paths[i]);
        cout << "actual_paths from running algo (without heap):" << endl;
        printv(path);
        if(!(path==ans_paths[i])){
            free(r.path);
            throw runtime_error("expected ans_path and ans_path from algo not equal!!");
        }
        free(r.path);

        // with heap
        result r1 = dj.find_max_bw_path(test_graph_final, v[0], v[1]);
        vector<int> path1(r1.path, r1.path+r1.length);
        cout << "actual_paths from running algo (with heap):" << endl;
        printv(path1);
        if(!(path1==ans_paths[i])){
            free(r1.path);
            throw runtime_error("expected ans_path and ans_path from with heap not equal!!");
        }
        free(r1.path);

        // with kruskal
        kruskal k;
        r1 = k.find_max_bw_path(edges, num_edges, n, v[0],v[1]);
        vector<int> path2(r1.path, r1.path+r1.length);
        cout << "actual_paths from running algo (with kruskal):" << endl;
        printv(path2);

        if(!(path2==ans_paths[i])){
            free(r1.path);
            throw runtime_error("expected ans_path and ans_path from kruskals not equal!!");
        }
        free(r1.path);
        cout << "Test passed!!" << endl;
    }

    // free(test_graph_final);
}
