#ifndef COUNT_OCCURRENCES_H
#define COUNT_OCCURRENCES_H

#include "first_occurrence.h"
#include "last_occurrence.h"
#include <vector>
using namespace std;

int count_occurrences(const vector<int>& arr, int target) {
    int first = first_occurrence(arr, target);
    if (first == -1) return 0;
    int last = last_occurrence(arr, target);
    return last - first + 1;
}

#endif // COUNT_OCCURRENCES_H
