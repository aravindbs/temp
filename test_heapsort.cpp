#include"heapsort.h"
#include<bits/stdc++.h>
#include"common.h"

using namespace std;

int main(){

    edge** test_edges=(edge**)malloc(sizeof(edge*)*15);
    int num_edges=6;
    for(int i=1;i<=6;i++)
    {
        edge *temp=(edge *)malloc(sizeof(edge));
        temp->u=i-1;
        temp->v=i;
        temp->bandwidth=rand()%15;
        test_edges[i-1]=temp;
    }

    heapsort hs(6, test_edges);
    hs.sort();
    for(int i=0;i<6;i++)
    {
        cout<<test_edges[i]->bandwidth<<" "<<endl;
    }

}