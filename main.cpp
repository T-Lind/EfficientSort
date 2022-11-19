// C++ program to sort an array in
// ascending order using optimized
// approach using quick sort
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Sort.h"
#include <iterator>

using namespace std;


int main() {
    int nItems = 1000000;

    int values[nItems];
    for (int i = 0; i < nItems; i++) {
        values[i] = rand() % INT32_MAX;
    }

    int valuesCpy[nItems];
    memcpy(valuesCpy, values, nItems * sizeof(int));

    cout << Sort::time(values, Sort::quicksort) << endl;
    cout << Sort::time(values, Sort::sort) << endl;
    return 0;

}