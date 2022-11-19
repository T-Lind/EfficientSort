//
// Created by zenith on 11/18/2022.
//

#include <bits/stdc++.h>
#include <ctime>
#include <time.h>
#include <iostream>
#include <pthread.h>
#include <chrono>
#include <cstdlib>
#include "Sort.h"
#include <iterator>

/**
* Sorts the specified array into ascending
numerical order.
*
* @param nums the array to be sorted.
* @param low for explaining the part of
				array working on.
* @param high for explaining the part of
				array working on.
*/
void Sort::inside_quicksort(int *nums, int low, int high) {
    // Base Condition
    if (low >= high)
        return;

    // These are just for swapping
    // the elements.
    int start = low, end = high;
    int mid = start + ((end - start) / 2);
    int pivot = nums[mid];

    while (start <= end) {
        while (nums[start] < nums[end])
            start++;
        while (nums[end] > pivot)
            end--;
        if (start <= end) {
            // Swapping the start and end
            // elements.
            int x = nums[start];
            nums[start] = nums[end];
            nums[end] = x;
            start++;
            end--;
        }
    }
    Sort::inside_quicksort(nums, low, end);
    Sort::inside_quicksort(nums, start, high);
}

void Sort::sort(int *arr, int nItems) {
    std::sort(arr, arr + nItems);
}

void Sort::quicksort(int *arr, int nItems) {
    Sort::inside_quicksort(arr, 0, nItems - 1);
}

long Sort::time(int* values, int nItems, void (*func)(int *, int nItems)) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    func(values, nItems);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return (long) duration.count();
}

//void Sort::merge(int* a, int low, int mid, int high)
//{
//    int* left = new int[mid - low + 1];
//    int* right = new int[high - mid];
//
//    // n1 is size of left part and n2 is size
//    // of right part
//    int n1 = mid - low + 1, n2 = high - mid, i, j;
//
//    // storing values in left part
//    for (i = 0; i < n1; i++)
//        left[i] = a[i + low];
//
//    // storing values in right part
//    for (i = 0; i < n2; i++)
//        right[i] = a[i + mid + 1];
//
//    int k = low;
//    i = j = 0;
//
//    // merge left and right in ascending order
//    while (i < n1 && j < n2) {
//        if (left[i] <= right[j])
//            a[k++] = left[i++];
//        else
//            a[k++] = right[j++];
//    }
//
//    // insert remaining values from left
//    while (i < n1) {
//        a[k++] = left[i++];
//    }
//
//    // insert remaining values from right
//    while (j < n2) {
//        a[k++] = right[j++];
//    }
//}
//
//void Sort::merge_sort(int* a, int low, int high) {
//    // calculating mid point of array
//    int mid = low + (high - low) / 2;
//    if (low < high) {
//
//        // calling first half
//        merge_sort(a, low, mid);
//
//        // calling second half
//        merge_sort(a, mid + 1, high);
//
//        // merging the two halves
//        merge(a, low, mid, high);
//    }
//}
//
//void *Sort::mergeSort(int* a, int thread_part, int nItems, void *arg) {
//    // which part out of 4 parts
//
//    // calculating low and high
//    int low = thread_part * (nItems / 4);
//    int high = (thread_part + 1) * (nItems / 4) - 1;
//
//    // evaluating mid point
//    int mid = low + (high - low) / 2;
//    if (low < high) {
//        merge_sort(a, low, mid);
//        merge_sort(a, mid + 1, high);
//        merge(a, low, mid, high);
//    }
//    return nullptr;
//}
//
//void Sort::parallelsort(int *arr, int nItems) {
//    pthread_t threads[NTHREADS];
//    for (unsigned long long & thread : threads)
//        pthread_create(&thread, NULL, reinterpret_cast<void *(*)(void *)>(mergeSort), (void*)NULL);
//    for (unsigned long long thread : threads)
//        pthread_join(thread, NULL);
//    merge(arr, 0, (nItems / 2 - 1) / 2, nItems / 2 - 1);
//    merge(arr, nItems / 2, nItems/2 + (nItems-1-nItems/2)/2, nItems - 1);
//    merge(arr, 0, (nItems - 1)/2, nItems - 1);
//}
