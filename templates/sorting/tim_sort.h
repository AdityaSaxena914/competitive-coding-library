#ifndef TIM_SORT_H
#define TIM_SORT_H

#include <vector>
using namespace std;

const int RUN = 32;

void insertion_sort_timsort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i], j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge_timsort(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void tim_sort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i += RUN)
        insertion_sort_timsort(arr, i, min(i + RUN - 1, n - 1));
    
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            merge_timsort(arr, left, mid, right);
        }
    }
}

#endif // TIM_SORT_H
