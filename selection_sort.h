#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "utils.h"

void selection_sort(int*& arr, int n){
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[i], arr[k]);
    }
}
#endif