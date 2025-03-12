#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
using namespace std;

// Partition function to place pivot in the correct position
template <typename T>
int partition(vector<T> &arr, int low, int high) {
    T pivot = arr[high];  // Pivot is the last element
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort Algorithm (O(n log n) average, O(n^2) worst)
template <typename T>
void quick_sort(vector<T> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

#endif // QUICK_SORT_H
