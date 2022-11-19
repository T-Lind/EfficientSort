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

long Sort::time(void (*func)()) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return (long) duration.count();
}
