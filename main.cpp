// C++ program to sort an array in
// ascending order using optimized
// approach using quick sort
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Sort.h"
#include <climits>
#include <algorithm>
#include <iterator>

using namespace std;


int main()
{
    int nItems = 10;

    int values[nItems];
    for(int i=0;i<nItems;i++){
        values[i] = rand() % INT32_MAX;
    }

    int dest[nItems];


    Sort::quicksort(values, 0, nItems - 1);

    return 0;
}

