#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>
using namespace std;

// Bubble Sort Algorithm (O(n^2))
template <typename T>
void bubble_sort(vector<T> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Optimization: Stop if no swaps occurred in the inner loop
    }
}

#endif // BUBBLE_SORT_H
