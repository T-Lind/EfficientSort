//
// Created by zenith on 11/19/2022.
//

#include "ParallelSort.h"
#include <iostream>
#include <pthread.h>

static const int nItems = 100000;
static const int nThreads = 4;
static int* array;
static int part;

void ParallelSort::run() {
    pthread_t threads[nThreads];

    // creating 4 threads
    for (int i = 0; i < nThreads; i++)
        pthread_create(&threads[i], NULL, mergeSort, (void *) NULL);

    // joining all 4 threads
    for (int i = 0; i < 4; i++)
        pthread_join(threads[i], NULL);

    // merging the final 4 parts
    merge(0, (nItems / 2 - 1) / 2, nItems / 2 - 1);
    merge(nItems / 2, nItems / 2 + (nItems - 1 - nItems / 2) / 2, nItems - 1);
    merge(0, (nItems - 1) / 2, nItems - 1);


    delete[] array;
}

void ParallelSort::merge(int low, int mid, int high) {
    int* left = new int[mid - low + 1];
    int* right = new int[high - mid];

    // n1 is size of left part and n2 is size
    // of right part
    int n1 = mid - low + 1, n2 = high - mid, i, j;

    // storing values in left part
    for (i = 0; i < n1; i++)
        left[i] = array[i + low];

    // storing values in right part
    for (i = 0; i < n2; i++)
        right[i] = array[i + mid + 1];

    int k = low;
    i = j = 0;

    // merge left and right in ascending order
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    // insert remaining values from left
    while (i < n1) {
        array[k++] = left[i++];
    }

    // insert remaining values from right
    while (j < n2) {
        array[k++] = right[j++];
    }
}

void ParallelSort::merge_sort(int low, int high) {
    int mid = low + (high - low) / 2;
    if (low < high) {

        // calling first half
        merge_sort(low, mid);

        // calling second half
        merge_sort(mid + 1, high);

        // merging the two halves
        merge(low, mid, high);
    }
}

void *ParallelSort::mergeSort(void *arg) {
    int thread_part = part++;

    // calculating low and high
    int low = thread_part * (nItems / 4);
    int high = (thread_part + 1) * (nItems / 4) - 1;

    // evaluating mid point
    int mid = low + (high - low) / 2;
    if (low < high) {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

void ParallelSort::assignArray(int *arr) {
    array = arr;
}


