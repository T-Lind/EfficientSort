//
// Created by zenith on 11/19/2022.
//

#ifndef EFFICIENTSORT_PARALLELSORT_H
#define EFFICIENTSORT_PARALLELSORT_H

#include <iostream>
#include <pthread.h>
#include <time.h>


class ParallelSort {
public:
    static void assignArray(int* array);
    static void run();

    static void merge(int low, int mid, int high);
    static void merge_sort(int low, int high);
    static void* mergeSort(void* arg);



};


#endif //EFFICIENTSORT_PARALLELSORT_H
