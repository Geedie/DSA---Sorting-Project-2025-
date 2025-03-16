#ifndef INSERTION_SORT
#define INSERTION_SORT

#include "utils.h"

void insertion_sort(int*& arr, int n){

	for (int i = 1; i < n; ++i) {
        int cur = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > cur; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = cur;
    } 
}

#endif