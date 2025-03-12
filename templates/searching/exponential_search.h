#ifndef EXPONENTIAL_SEARCH_H
#define EXPONENTIAL_SEARCH_H

#include "binary_search.h"
#include <vector>
using namespace std;

int exponential_search(const vector<int>& arr, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < (int)arr.size() && arr[i] <= target) i *= 2;
    return binary_search(vector<int>(arr.begin() + i / 2, arr.begin() + min(i, (int)arr.size())), target);
}

#endif // EXPONENTIAL_SEARCH_H
