// C++ program to sort values in
// ascending order using optimized
// approach using quick sort
#include <cstdlib>
#include "BasicSort.h"
#include <iterator>

using namespace std;


const int N_ITEMS = 10000000;
const int N_THREADS = 4;
int workingThread = 0;

int* values = new int[N_ITEMS];
int* valuesCpy = new int[N_ITEMS];
int* values2Cpy = new int[N_ITEMS];

void merge(int low, int mid, int high) {
    int* left = new int[mid - low + 1];
    int* right = new int[high - mid];

    int n1 = mid - low + 1, n2 = high - mid, i, j;

    for (i = 0; i < n1; i++)
        left[i] = values[i + low];

    for (i = 0; i < n2; i++)
        right[i] = values[i + mid + 1];

    int k = low;
    i = j = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            values[k++] = left[i++];
        else
            values[k++] = right[j++];
    }

    while (i < n1)
        values[k++] = left[i++];


    while (j < n2)
        values[k++] = right[j++];

}

void merge_sort(int low, int high) {
    int mid = low + (high - low) / 2;
    if (low < high) {

        merge_sort(low, mid);

        merge_sort(mid + 1, high);

        merge(low, mid, high);
    }
}

void* mergeSort(void* arg) {
    // Start working on the next thread
    int thread_part = workingThread++;

    // Perform merging behavior
    int low = thread_part * (N_ITEMS / 4);
    int high = (thread_part + 1) * (N_ITEMS / 4) - 1;
    int mid = low + (high - low) / 2;
    if (low < high) {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
    return nullptr;
}

int runSort() {
    using namespace std::chrono;
    pthread_t threads[N_THREADS];


    // Fill threads with merge sort function, starts after all are filled
    for (unsigned long long & thread : threads)
        pthread_create(&thread, nullptr, mergeSort, (void *) nullptr);
    auto start = high_resolution_clock::now();

    // Join threads when completed
    for (unsigned long long thread : threads)
        pthread_join(thread, nullptr);

    // Merge four remaining pieces
    merge(0, (N_ITEMS / 2 - 1) / 2, N_ITEMS / 2 - 1);
    merge(N_ITEMS / 2, N_ITEMS / 2 + (N_ITEMS - 1 - N_ITEMS / 2) / 2, N_ITEMS - 1);
    merge(0, (N_ITEMS - 1) / 2, N_ITEMS - 1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Exit
    return (int)duration.count();
}

int main() {
    for (int i = 0; i < N_ITEMS; i++) {
        int val = rand() % INT32_MAX;
        values[i] = val;
        valuesCpy[i] = val;
        values2Cpy[i] = val;
    }

    cout << "Sorting:" << endl;
    cout << "---------" << endl;
    cout << "Quicksort: " << BasicSort::time(values, N_ITEMS, BasicSort::quicksort) << endl;
    cout << "STD BasicSort: " << BasicSort::time(valuesCpy, N_ITEMS, BasicSort::sort) << endl;
    cout << "Parallel Mergesort: " << runSort()  << endl;

    delete[] values;
    delete[] valuesCpy;
    delete[] values2Cpy;

    return 0;

}

