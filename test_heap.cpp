#include "heap.h"
#include <iostream>

using namespace std;

int MAX_NODES=50;


void insert_into_heap(Myheap &heapobj, vector<int> &test_heap_bandwidth){
    for(int i=0;i<test_heap_bandwidth.size();i++){
        heapobj.insert(i,test_heap_bandwidth[i]);
    }
}

int main(){
    vector<int> test_heap_bandwidth = {40,16,20,35,15,12,17,30,43};
    vector<int> test_heap_array = {43,40,20,35,15,12,17,16,30};
    int to_delete = 0;

    {
        Myheap heapobj;

        cout<<"****Insert test for heap*******"<<endl;
        cout<<"*****Iter1: Test for heap array"<<endl;

        insert_into_heap(heapobj,test_heap_bandwidth);

        heapobj.verify_heap_array(test_heap_array, test_heap_bandwidth.size());
        cout<<"****Iter2: Test for indx_to_node array*****"<<endl;
        vector<int> test_indx_to_node = {8,0,2,3,4,5,6,1,7};
        heapobj.verify_indx_to_node_array(test_indx_to_node,test_indx_to_node.size());

        cout<<"****Iter3: Test for node_to_indx array*****"<<endl;
        vector<int>test_node_to_indx = {1,7,2,3,4,5,6,8,0};
        heapobj.verify_node_to_indx_array(test_node_to_indx, test_node_to_indx.size());
    }
    {
        cout<<endl;
        Myheap heapobj;
        insert_into_heap(heapobj,test_heap_bandwidth);
        vector<int> test_heap_array_after_delete = {43, 35, 20, 30, 15, 12, 17, 16};

        cout<<"*****Delete test for heap*******"<<endl;
        cout<<"*****Iter1: check heap_array"<<endl;

        heapobj.remove(to_delete);
        heapobj.verify_heap_array(test_heap_array_after_delete, test_heap_array_after_delete.size());

        cout<<"****Iter 2: check indx_to_node array*****"<<endl;
        vector<int> test_indx_to_node = {8,3,2,7,4,5,6,1,-1};
        heapobj.verify_indx_to_node_array(test_indx_to_node, test_indx_to_node.size());

        cout<<"****Iter 3: check node_to_indx array*****"<<endl;
        vector<int> test_node_to_indx = {-1,7,2,1,4,5,6,3,0};
        heapobj.verify_node_to_indx_array(test_node_to_indx, test_node_to_indx.size());

        
        // cout<<"****Iter1: Verify "

    }

    return 0;
}