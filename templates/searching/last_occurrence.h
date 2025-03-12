#ifndef LAST_OCCURRENCE_H
#define LAST_OCCURRENCE_H

#include <vector>
using namespace std;

int last_occurrence(const vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Move right for last occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

#endif // LAST_OCCURRENCE_H
