#ifndef UPPER_BOUND_H
#define UPPER_BOUND_H

#include <vector>
using namespace std;

int upper_bound_search(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

#endif // UPPER_BOUND_H
