#ifndef TERNARY_SEARCH_H
#define TERNARY_SEARCH_H

#include <vector>
using namespace std;

int ternary_search(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;
        if (target < arr[mid1]) right = mid1 - 1;
        else if (target > arr[mid2]) left = mid2 + 1;
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}

#endif // TERNARY_SEARCH_H
