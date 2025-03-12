#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>
using namespace std;

// Insertion Sort Algorithm (O(n^2))
template <typename T>
void insertion_sort(vector<T> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

#endif // INSERTION_SORT_H
