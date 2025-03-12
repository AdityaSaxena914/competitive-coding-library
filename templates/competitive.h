#ifndef COMPETITIVE_H
#define COMPETITIVE_H

#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
// Constants
const int MOD = 1e9 + 7;  // Common large prime modulus

// Macros
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

// Include All Templates
// Searching Algorithms
#include "searching/binary_search.h"
#include "searching/exponential_search.h"
#include "searching/jump_search.h"
#include "searching/lower_bound_search.h"
#include "searching/upper_bound_search.h"
#include "searching/first_occurrence.h"
#include "searching/last_occurrence.h"
#include "searching/count_occurrences.h"
#include "searching/ternary_search.h"
#include "searching/two_pointer_search.h"
#include "searching/linear_search.h"

// Sorting Algorithms
#include "sorting/bubble_sort.h"
#include "sorting/insertion_sort.h"
#include "sorting/selection_sort.h"
#include "sorting/merge_sort.h"
#include "sorting/quick_sort.h"
#include "sorting/heap_sort.h"
#include "sorting/counting_sort.h"
#include "sorting/radix_sort.h"
#include "sorting/bucket_sort.h"
#include "sorting/shell_sort.h"
#include "sorting/tim_sort.h"
#include "sorting/descend_sort.h"

// Number Theory Algorithms
#include "number_theory/number_theory.h"


#endif // COMPETITIVE_H
