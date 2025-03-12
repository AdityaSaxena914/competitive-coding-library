#ifndef TWO_POINTER_SEARCH_H
#define TWO_POINTER_SEARCH_H

#include <vector>
using namespace std;

bool two_pointer_search(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        if (sum < target) left++;
        else right--;
    }
    return false;
}

#endif // TWO_POINTER_SEARCH_H
