// C++ program to sort an array in
// ascending order using optimized
// approach using quick sort
#include <bits/stdc++.h>
#include <cstdlib>
#include "Sort.h"
#include <iterator>
#include "ParallelSort.h"

using namespace std;


int main() {
    int nItems = 10000000;

    int* values = new int[nItems];
    int* valuesCpy = new int[nItems];
    int* values2Cpy = new int[nItems];
    for (int i = 0; i < nItems; i++) {
        int val = rand() % INT32_MAX;
        values[i] = val;
        valuesCpy[i] = val;
        values2Cpy[i] = val;
    }

    ParallelSort::assignArray(values2Cpy);

    cout << "Quicksort: " << Sort::time(values, nItems, Sort::quicksort) << endl;
    cout << "STD Sort: " << Sort::time(valuesCpy, nItems, Sort::sort) << endl;

    delete[] values;
    delete[] valuesCpy;
    delete[] values2Cpy;
    return 0;

}

