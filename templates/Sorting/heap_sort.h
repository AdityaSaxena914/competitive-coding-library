#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heap_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)  // Build max heap
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Swap max element with the last element
        heapify(arr, i, 0);  // Heapify reduced heap
    }
}
#endif
