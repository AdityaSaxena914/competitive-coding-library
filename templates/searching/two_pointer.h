#ifndef TWO_POINTER_H
#define TWO_POINTER_H

#include <bits/stdc++.h>
using namespace std;

// Function to find if there exists a pair with sum X in a sorted array
bool twoPointerSum(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

#endif // TWO_POINTER_H