#include <iostream>
using namespace std;
#include "templates/searching/binary_search.h"

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 5;
    cout << (binary_search(arr, x) ? "Found" : "Not Found") << endl;
    return 0;
}

