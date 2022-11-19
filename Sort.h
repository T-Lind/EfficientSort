//
// Created by zenith on 11/18/2022.
//

#ifndef EFFICIENTSORT_SORT_H
#define EFFICIENTSORT_SORT_H

#include <bits/stdc++.h>
#include <ctime>

#include "Sort.h"

class Sort {
public:
    static void quicksort(int nums[]);
    static void sort(int arr[]);

    static long time(int vals[], void (*func)(int nums[]));
private:
    static void inside_quicksort(int nums[], int low, int high);

};

#endif //EFFICIENTSORT_SORT_H
