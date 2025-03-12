#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>
using namespace std;

// Selection Sort Algorithm (O(n^2))
template <typename T>
void selection_sort(vector<T> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}

#endif // SELECTION_SORT_H
