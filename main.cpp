// C++ program to sort an array in
// ascending order using optimized
// approach using quick sort
#include <bits/stdc++.h>
#include <cstdlib>
#include "Sort.h"
#include <iterator>

using namespace std;


int main() {
    int nItems = 10000000;

    int* values = new int[nItems];
    int* valuesCpy = new int[nItems];
    for (int i = 0; i < nItems; i++) {
        int val = rand() % INT32_MAX;
        values[i] = val;
        valuesCpy[i] = val;
    }

    cout << "Quicksort: " << Sort::time(values, nItems, Sort::quicksort) << endl;
    cout << "STD Sort: " << Sort::time(valuesCpy, nItems, Sort::sort) << endl;
    cout << "Parallel Sort: " << Sort::time(valuesCpy, nItems, Sort::parallelsort) << endl;



    delete[] values;
    delete[] valuesCpy;
    return 0;

}

