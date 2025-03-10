#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
using namespace std;

bool binary_search(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return true;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

#endif
