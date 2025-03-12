#include "templates/competitive.h"

int32_t main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 6, 6, 7};
    int target = 2;

    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << "\nTarget: " << target << "\n\n";

    // Linear Search
    cout << "Linear Search Index: " << linear_search(arr, target) << "\n";

    // Binary Search
    cout << "Binary Search Found: " << (binary_search(arr, target) ? "Yes" : "No") << "\n";

    // Lower Bound
    cout << "Lower Bound Index: " << lower_bound(arr, target) << "\n";

    // Upper Bound
    cout << "Upper Bound Index: " << upper_bound(arr, target) << "\n";

    // First Occurrence
    cout << "First Occurrence Index: " << first_occurrence(arr, target) << "\n";

    // Last Occurrence
    cout << "Last Occurrence Index: " << last_occurrence(arr, target) << "\n";

    // Count Occurrences
    cout << "Count Occurrences: " << count_occurrences(arr, target) << "\n";

    // Exponential Search
    cout << "Exponential Search Index: " << exponential_search(arr, target) << "\n";

    // Jump Search
    cout << "Jump Search Index: " << jump_search(arr, target) << "\n";

    // Ternary Search
    cout << "Ternary Search Index: " << ternary_search(arr, target) << "\n";

    // Two Pointer Search for Sum
    int sumTarget = 8;
    cout << "Two Pointer Search for Sum " << sumTarget << ": "
         << (two_pointer_search(arr, sumTarget) ? "Yes" : "No") << "\n";

    return 0;
}
