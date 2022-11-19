//
// Created by zenith on 11/18/2022.
//

#include <cstdint>
#include <cstdlib>
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
void Sort::quicksort(int *nums, int low, int high) {
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
        if (start <= end)
        {
            // Swapping the start and end
            // elements.
            int x = nums[start];
            nums[start] = nums[end];
            nums[end] = x;
            start++;
            end--;
        }
    }
    Sort::quicksort(nums, low, end);
    Sort::quicksort(nums, start, high);
}

