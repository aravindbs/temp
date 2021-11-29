#include<bits/stdc++.h>
#include "common.h"
#include "union_find.h"

using namespace std;

int main(){
    vector<edge> test_edges;
    for(int i=1;i<=4;i++)
    {
        test_edges.push_back(edge(i-1,i,2));
    }

    union_find uf(4);
    for(int i=0;i<=2;i++){
        if(uf.check_cycle(i,i+1)){
            throw runtime_error("got cycle when you should not have");
        }
        uf.custom_union(i,i+1);
    }
    try{
        uf.custom_union(3,4);
        throw runtime_error("did not exception when it was expected");
    }
    catch (const runtime_error &e){
        cout<<"test passed!!"<<endl;
    }
}