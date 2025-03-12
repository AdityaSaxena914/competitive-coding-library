#ifndef LOWER_BOUND_H
#define LOWER_BOUND_H

#include <vector>
using namespace std;

int lower_bound(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

#endif // LOWER_BOUND_H
