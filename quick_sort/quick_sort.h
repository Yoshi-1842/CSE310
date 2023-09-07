#define QUICK_SORT_H
#define QUICK_SORT_H

using namespace std;

void swap(int* pointer_to_first_element, int* pointer_to_second_element);
int partition (int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);

