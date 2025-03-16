#ifndef BUBBLE_SORT_CMP
#define BUBBLE_SORT_CMP

#include "utils.h"

void bubble_sort_cmp(int*& arr, int n, long long &cmp){
    int i = n;
    int j = 1;
    while(++cmp && i > 1){
    	j = 1;
    	while(++cmp && j < i){
    		++cmp;
    		if(arr[j - 1] > arr[j]){
    			swap(arr[j - 1], arr[j]);
    		}
    		++j;
    	}
    	--i;
    }
}

#endif