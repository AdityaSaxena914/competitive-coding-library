#ifndef RADIX_SORT_H
#define RADIX_SORT_H
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for counting sort in radix sort
void counting_sort_radix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int num : arr) count[(num / exp) % 10]++;

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

// Radix Sort (only for non-negative integers)
void radix_sort(vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_radix(arr, exp);
    }
}
#endif
