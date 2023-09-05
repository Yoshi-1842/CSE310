#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int array[], int n);

int main() {
    int arraySize = 0;
    cin >> arraySize;
    int n[arraySize];
    for (int i = 0; i < arraySize; i++) {
        cin >> n[i];
    }

    bubbleSort(n, arraySize);

    for (int e = 0; e < arraySize; e++) {
        cout << " " << n[e];
    }

    return 0;
}

void bubbleSort(int array[], int n) {
    int i, j;
    bool moved;
    for (i = 0; i < n - 1; i++) {
        moved = false;
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                moved = true;
            }
        }
        if (moved == false)
            break;
    }
}