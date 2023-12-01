#include "minheap.h"

MinHeap::MinHeap() {
    // Set pointers to nullptr
    // Set variables to default values
    capacity = 0;
    size = 0;
    keys = nullptr;
    values = nullptr;
}

void MinHeap::init(int newSize) {
    // Set capacity and size
    capacity = newSize +1;
    this->size = 0;

    // Allocate memory for keys (weights) and values (nodes)
    keys = new double[capacity];
    values = new int[capacity];
}

void MinHeap::push(double key, int value) {
    // If the heap is full
    if (size >= capacity) {
        return;
    }
    // Increase size
    size++;

    // Set key and value at the end with the index as size - 1
    int index = size - 1;
    keys[index] = key;
    values[index] = value;

    // Heapify up
    heapifyUp(size - 1);
}


int MinHeap::pop() {
    // If the heap is empty
    if (size == 0) {
        // Return sentinel value (assuming some sentinel value like -1)
        return -1;
    }

    // Get root value
    int rootValue = values[1];
    // Replace root with the last element
    keys[1] = keys[size];
    values[1] = values[size];
    // Decrease size
    size--;
    // Heapify down
    heapifyDown(1);

    return rootValue;
}

bool MinHeap::empty() const {
    // Return true if size is 0, false otherwise
    return size == 0;
}

void MinHeap::heapifyUp(int index) {
    // While index > 1 and the current key is less than the parent key
    while (index > 1 && keys[index] < keys[index / 2]) {
        // Swap index with parent
        swap(index, index / 2);
        // Update index to parent
        index = index / 2;
    }
}

void MinHeap::heapifyDown(int index) {
    // Find the smallest child from left (2*index) or right (2*index+1) child of index
    int smallest = index;
    int leftChild = smallest * 2;
    int rightChild = smallest * 2 + 1;
    int smallestChild = index * 2;

    if (leftChild <= size && keys[rightChild] < keys[leftChild]) {
        smallestChild = rightChild;
    }

    // If the smallest child is smaller than the current key
    if (smallestChild <= size && keys[smallestChild] < keys[index]) {
        // Swap with the smallest child
        swap(index, smallestChild);

        // Update index
        index = smallestChild;

        // Heapify down
        heapifyDown(index);
    }
}


void MinHeap::swap(int i, int j) {
    // Swap keys and values at positions i and j
    double tempKey = keys[i];
    int tempValue = values[i];

    keys[i] = keys[j];
    values[i] = values[j];

    keys[j] = tempKey;
    values[j] = tempValue;
}
