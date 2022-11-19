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
//    static void parallelsort(int arr[], int nItems);

    static long time(int* values, int nItems, void (*func)(int *, int nItems));
private:
    const static int NTHREADS = 4;
    static void inside_quicksort(int nums[], int low, int high);
//
//    static void merge(int* a, int low, int mid, int high);
//    static void merge_sort(int* a, int low, int high);
//    static void* mergeSort(int* a, int thread_part, int nItems, void *arg);

};

#endif //EFFICIENTSORT_SORT_H
