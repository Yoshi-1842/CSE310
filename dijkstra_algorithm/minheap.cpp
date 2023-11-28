#include "minheap.h"

MinHeap::MinHeap() {
    //set pointers to nullptr
    //set variables to default values
}

void MinHeap::init(int size) {
    //set capacity and size
    //allocate memory for keys(weights) and values(nodes)
}

void MinHeap::push(double key, int value) {
    /*
    if heap is full
        return

    increase size
    set key and value at the end with index as size
    heapify up
    */
}

int MinHeap::pop() {
    /*
    if heap is empty
        return sentinel value

    get root value
    replace root with the last element
    decrease size
    heapify down

    return root value
    */
}

bool MinHeap::empty() const {
    //return true if size is 0, false otherwise
}

void MinHeap::heapifyUp(int index) {
    /*
    while index > 1 and current key is less than parent key (parent key is index / 2)
        swap index with parent
        update index to parent
    */
}

void MinHeap::heapifyDown(int index) {
    /*
    find the smallest child from left(2*index) or right(2*index+1) child of index
    if smallest child is smaller than current key
        swap with smallest child with index
        update index
        heapify down
    */
}

void MinHeap::swap(int i, int j) {
    //swap keys and values at positions i and j
}
