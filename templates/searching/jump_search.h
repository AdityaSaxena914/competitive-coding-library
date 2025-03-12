#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include <vector>
#include <cmath>
using namespace std;

int jump_search(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n)) return -1;
    }
    return (arr[prev] == target) ? prev : -1;
}

#endif // JUMP_SEARCH_H
