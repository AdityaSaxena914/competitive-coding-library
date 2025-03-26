#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <vector>
using namespace std;

int linear_search(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

#endif // LINEAR_SEARCH_H
