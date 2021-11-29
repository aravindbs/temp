#include"heapsort.h"
#include <stdexcept>

using namespace std;

heapsort::heapsort(int num_edges, edge** array):num_edges(num_edges),heaparray(array){
}


void heapsort::fix_heap_up(int size){
    int i=size,parent;
    if(i%2==0){
        parent = (i-2)/2;
    }
    else{
        parent = (i-1)/2;
    }

    while(i!=0){
        if(heaparray[parent]->bandwidth<heaparray[i]->bandwidth){
            swap(parent, i);
            i=parent;
            parent = (i - 1) / 2;
        }
        else{
            break;
        }
    }

}

void heapsort::fix_heap_down(int size){
    int pos=0;

    int left=2*pos+1, right=2*pos+2;

    while((left<size)||(right<size)){

        int max=-1;
        if(left>=size){
            max=right;
        }
        else if(right >= size){
            max=left;
        }
        else if(heaparray[left]->bandwidth>heaparray[right]->bandwidth){
            max=left;
        }
        else{
            max=right;
        }

        if(heaparray[pos]->bandwidth<heaparray[max]->bandwidth){
            swap(pos,max);
            pos=max;
            left=2*pos+1;
            right=2*pos+2;
        }
        else{
            break;
        }

    } 

}

void heapsort::swap(int i, int j){
    edge *temp=heaparray[i];
    heaparray[i]=heaparray[j];
    heaparray[j]=temp;
}

void heapsort::sort(){

    for(int i=0;i<num_edges;i++){
        fix_heap_up(i);
    }
    for(int i=0;i<num_edges;i++){
        swap(0,num_edges-1-i);
        fix_heap_down(num_edges-1-i);
    }

}