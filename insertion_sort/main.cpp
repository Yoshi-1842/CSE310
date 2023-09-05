int main()
{
// Number of elements in array
int number_of_elements;
cin >> number_of_elements;
// Elements in Array
int arr[ number_of_elements ];
for (int index = 0; index < number_of_elements; index ++)
cin >> arr[ index ];
int* ans = insertion_sort (arr, number_of_elements);
print_array (ans, number_of_elements);
return 0;
}

#include <bits/stdc++.h>
using namespace std;
// insertion sort
int* insertion_sort(int arr[], int number_of_elements)
{
    int* sorted_arr = new int[number_of_elements];
    for (int index = 0; index < number_of_elements; index++) {
        sorted_arr[index] = arr[index];
    }

    for (int index = 1; index < number_of_elements; index++) {
        int value_at_index = sorted_arr[index];
        int second_index = index - 1;

        while (second_index >= 0 && sorted_arr[second_index] > value_at_index) {
            sorted_arr[second_index + 1] = sorted_arr[second_index];
            second_index--;
        }
        sorted_arr[second_index + 1] = value_at_index;
    }
    return sorted_arr;
}

// Function to print array. Array is called by reference
void print_array (int arr[], int number_of_elements)
{
    for (int index = 0; index < number_of_elements; index++)
    cout << arr[ index ] << " ";
    cout << endl;
}