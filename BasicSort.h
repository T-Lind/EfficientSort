//
// Created by zenith on 11/18/2022.
//

#ifndef EFFICIENTSORT_BASICSORT_H
#define EFFICIENTSORT_BASICSORT_H

#include <bits/stdc++.h>
#include <ctime>
#include <pthread.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include "BasicSort.h"
#include <iterator>

#include "BasicSort.h"
using namespace std;


class BasicSort {
public:
    static void quicksort(int nums[], int nItems);
    static void sort(int arr[], int nItems);

    static long time(int* values, int nItems, void (*func)(int *, int nItems));
    static long time(void (*func)());
private:
    static void inside_quicksort(int nums[], int low, int high);
};

#endif //EFFICIENTSORT_BASICSORT_H
