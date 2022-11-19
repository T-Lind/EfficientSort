//
// Created by zenith on 11/18/2022.
//

#include <bits/stdc++.h>
#include <chrono>
#include "BasicSort.h"

/**
* Sorts the specified values into ascending
numerical order.
*
* @param nums the values to be sorted.
* @param low for explaining the part of
				values working on.
* @param high for explaining the part of
				values working on.
*/
void BasicSort::inside_quicksort(int *nums, int low, int high) {
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
    BasicSort::inside_quicksort(nums, low, end);
    BasicSort::inside_quicksort(nums, start, high);
}

void BasicSort::sort(int *arr, int nItems) {
    std::sort(arr, arr + nItems);
}

void BasicSort::quicksort(int *arr, int nItems) {
    BasicSort::inside_quicksort(arr, 0, nItems - 1);
}

long BasicSort::time(int* values, int nItems, void (*func)(int *, int nItems)) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    func(values, nItems);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return (long) duration.count();
}

long BasicSort::time(void (*func)()) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return (long) duration.count();
}
