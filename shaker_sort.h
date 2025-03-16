#ifndef SHAKER_SORT
#define SHAKER_SORT

#include "utils.h"

void shaker_sort(int*& arr, int n) {
    int left = 0;
    int right = n - 1;
    do {
        for (int j = right - 1; j >= left; j--) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        left++;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
        right--;
    } while (left < right);
}

#endif