#ifndef DESCEND_SORT_H
#define DESCEND_SORT_H

#include <bits/stdc++.h>
using namespace std;

// Bubble Sort (Descending)
void bubble_sort_desc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection Sort (Descending)
void selection_sort_desc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) max_idx = j;
        }
        swap(arr[i], arr[max_idx]);
    }
}

// Insertion Sort (Descending)
void insertion_sort_desc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort (Descending)
void merge_desc(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort_desc(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_desc(arr, left, mid);
        merge_sort_desc(arr, mid + 1, right);
        merge_desc(arr, left, mid, right);
    }
}

// Quick Sort (Descending)
int partition_desc(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_desc(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition_desc(arr, low, high);
        quick_sort_desc(arr, low, pi - 1);
        quick_sort_desc(arr, pi + 1, high);
    }
}

// Heap Sort (Descending)
void heapify_desc(vector<int>& arr, int n, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_desc(arr, n, smallest);
    }
}

void heap_sort_desc(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify_desc(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify_desc(arr, i, 0);
    }
}

// Counting Sort (Descending)
void counting_sort_desc(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0), output(arr.size());
    for (int x : arr) count[x]++;
    int index = 0;
    for (int i = max_val; i >= 0; i--) {
        while (count[i]--) output[index++] = i;
    }
    arr = output;
}

// Radix Sort (Descending)
void counting_sort_radix_desc(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};
    for (int x : arr) count[(x / exp) % 10]++;
    for (int i = 8; i >= 0; i--) count[i] += count[i + 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = output;
}

void radix_sort_desc(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_radix_desc(arr, exp);
    }
}

// Bucket Sort (Descending)
void bucket_sort_desc(vector<int>& arr) {
    int n = arr.size();
    vector<int> bucket[10];
    int max_val = *max_element(arr.begin(), arr.end()) + 1;
    for (int x : arr) bucket[x * 10 / max_val].push_back(x);
    for (int i = 0; i < 10; i++) sort(bucket[i].begin(), bucket[i].end(), greater<int>());
    arr.clear();
    for (int i = 9; i >= 0; i--) arr.insert(arr.end(), bucket[i].begin(), bucket[i].end());
}

// Shell Sort (Descending)
void shell_sort_desc(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Tim Sort (Descending)
void tim_sort_desc(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
}

#endif // DESCEND_SORT_H
