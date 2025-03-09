#include <bits/stdc++.h>
using namespace std;

// Standard Binary Search Function
int binarySearch(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;  // Target found
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Target not found
}

int main() {
    int n, target;
    cout << "Enter array size: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter sorted array elements: ";
    for (int &x : arr) cin >> x;
    
    cout << "Enter target element: ";
    cin >> target;

    int result = binarySearch(arr, target);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found.\n";

    return 0;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)