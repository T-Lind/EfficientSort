//
// Created by zenith on 11/18/2022.
//

#ifndef EFFICIENTSORT_SORT_H
#define EFFICIENTSORT_SORT_H

#include <bits/stdc++.h>
#include <ctime>
#include <pthread.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include "Sort.h"
#include <iterator>

#include "Sort.h"
using namespace std;


class Sort {
public:
    static void quicksort(int nums[], int nItems);
    static void sort(int arr[], int nItems);

    static long time(int* values, int nItems, void (*func)(int *, int nItems));
    static long time(void (*func)());
private:
    static void inside_quicksort(int nums[], int low, int high);
};

#endif //EFFICIENTSORT_SORT_H
