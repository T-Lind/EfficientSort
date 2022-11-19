//
// Created by zenith on 11/18/2022.
//

#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
#include "Sort.h"


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

void Sort::sort(int *arr) {
    int n = sizeof(*arr) / sizeof(arr[0]);
    std::sort(arr, arr + n);
}

void Sort::quicksort(int *arr) {
    int n = sizeof(*arr) / sizeof(arr[0]);
    Sort::inside_quicksort(arr, 0, n - 1);
}

long Sort::time(int *vals, void (*func)(int nums[])) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    func(vals);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return (long) duration.count();
}

