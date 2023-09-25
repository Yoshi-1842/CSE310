#include <bits/stdc++.h>
#include <cmath>
using namespace std;


//Yosef Pineda 9.21.2023 :)
void merge_two_sorted_arrays(long long int array[], int const left, int const mid, int const right) 
{
    // Sub-array sizes
    int const sub_array_one = mid - left + 1;  // Length of Array[left to mid]
    int const sub_array_two = right - mid;      // Length of Array[mid + 1 to right]

    // Create temp arrays
    long long int *left_array = new long long int[sub_array_one];
    long long int *right_array = new long long int[sub_array_two];

    /* Copy data to temp arrays left_array[] and right_array[] */
    for (int i = 0; i < sub_array_one; i++) {
        left_array[i] = array[left + i];  // Corrected indexing
    }
    for (int j = 0; j < sub_array_two; j++) {
        right_array[j] = array[mid + j + 1];  // Corrected indexing
    }

    /* Indices of the left, right, and merged array */
    int indexSub_Aone = 0;  // i
    int indexSub_Atwo = 0;  // j
    int indexMerge_A = left;  // k

    /* Merge the temp arrays back into array[left..right] */
    while (indexSub_Aone < sub_array_one && indexSub_Atwo < sub_array_two) {
        if (left_array[indexSub_Aone] <= right_array[indexSub_Atwo]) {
            array[indexMerge_A] = left_array[indexSub_Aone];
            indexSub_Aone += 1;
        } else {
            array[indexMerge_A] = right_array[indexSub_Atwo];
            indexSub_Atwo += 1;
        }
        indexMerge_A += 1;
    }

    /* Copy the remaining elements of left[], if there are any */
    while (indexSub_Aone < sub_array_one) {
        array[indexMerge_A] = left_array[indexSub_Aone];
        indexSub_Aone += 1;
        indexMerge_A += 1;
    }

    /* Copy the remaining elements of right[], if there are any */
    while (indexSub_Atwo < sub_array_two) {
        array[indexMerge_A] = right_array[indexSub_Atwo];
        indexSub_Atwo += 1;
        indexMerge_A += 1;
    }

    // Delete left and right sub-arrays
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(long long int array[], int const begin, int const end)
{
    /* Recursive calls of merge_sort and merge_two_sorted_arrays */
        if( begin >= end){
			return;
		}

		int q = floor((begin + end)/2); // midpoint of A[p to r]
		merge_sort(array, begin, q);
		merge_sort(array, q+1, end);

		
		merge_two_sorted_arrays(array, begin, q, end);
 
}
