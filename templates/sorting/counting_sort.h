#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H
#include <vector>
#include <algorithm>
using namespace std;

// Counting Sort (only for non-negative integers)
void counting_sort(vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> count(range, 0);
    for (int num : arr) count[num - min_val]++;  // Count occurrences

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i]-- > 0) arr[index++] = i + min_val;
    }
}
#endif
