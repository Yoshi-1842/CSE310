#include <iostream>

using namespace std;

void swap(int & pointer_to_first_element, int& pointer_to_second_elemen ){
    int temporary_storage = pointer_to_first_element;
    pointer_to_first_element = pointer_to_second_elemen;
    pointer_to_second_elemen = temporary_storage;
}

int partion(int arr[], int start,int end){
  int pivot = arr[end];
  int index_smaller = start - 1;
  
  for(int index = start;index <= end - 1; index++){
        if (arr[index] < pivot){
            index_smaller++;
            swap(arr[index_smaller], arr[index]);
        }
  } 

  swap(arr[index_smaller +1], arr[end]);
  return (index_smaller + 1);
}

void quick_sort(int arr[], int low, int high){
    if (low < high){
        int partition_index = partion(arr, low, high);
        quick_sort(arr, low, partition_index -1);
        quick_sort(arr, partition_index + 1, high);
    }
}