#include "quick_sort.h";
#include <iostream>

void print_array(int arr[], int number_of_elements){
    for(int index = 0; index < number_of_elements; index++){
        cout <<arr[index] << "";
        cout <<endl;
    }
}

int main(){
    int number_of_elements;
    cin >> number_of_elements;
// Elements in Array
    int arr[ number_of_elements ];
    for (int index = 0; index < number_of_elements; index ++)
    cin >> arr[ index ];
    quick_sort (arr, 0, number_of_elements - 1);
    print_array (arr, number_of_elements);
    return 0;

}