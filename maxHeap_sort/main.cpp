#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap{
private:
    vector<int> heap;
    void heapify(int i){
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if(rightChild < heap.size() && heap[rightChild] > heap[largest]){
            largest = rightChild;
        }
        if(largest != i){
            swap(heap[i],heap[largest]);
            heapify(largest);
        }
    }
public:
/*
To insert a new node on the max heap is necessary to put the new 
element on the right left side and go up from that side
*/
    void insert(int val){ 
        heap.push_back(val);
        int idx = heap.size() - 1;

        while (idx > 0 && heap[idx] > heap[(idx - 1)/2]){
            swap(heap[idx], heap[(idx - 1)/2]);
            idx = (idx-1)/2;
        }
    }

    void deleteMaxHeap(){

        if (heap.empty()){
            return;
        }
        swap(heap[0],heap.back());// It swaps the root (max) with the last element.
        heap.pop_back();
        heapify(0);
    }

    int printMaxHeap(){

         if (heap.empty()) {
            return -1; // Heap is empty
        }
        return heap[0];
    }
};

int main(){
    
    int number_of_queries = 0;
    cin >> number_of_queries;

    MaxHeap max_heap;

    while(number_of_queries--){
        string operation;
        cin >> operation;

        if(operation == "INSERT"){
            int val;
            cin>>val;
            max_heap.insert(val);
        }else if (operation == "DELETE"){
            max_heap.deleteMaxHeap();
        }else if (operation == "PRINT"){
            int max_val = max_heap.printMaxHeap();
            if (max_val == -1){
                cout <<endl;
            }else{
                cout<<max_val <<endl;
            }
        }
    }
}