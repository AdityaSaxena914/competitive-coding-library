#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H
#include <vector>
#include <algorithm>
using namespace std;

// Bucket Sort (for floating points in range [0, 1))
void bucket_sort(vector<int>& arr) {
    if (arr.empty()) return;

    int n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    vector<vector<int>> buckets(n);

    // Distribute elements into buckets
    for (int num : arr) {
        int idx = (1LL * n * num) / (max_val + 1);
        buckets[idx].push_back(num);
    }

    // Sort individual buckets and merge
    arr.clear();
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        for (int num : bucket) arr.push_back(num);
    }
}
#endif
