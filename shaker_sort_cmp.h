#ifndef SHAKER_SORT_CMP
#define SHAKER_SORT_CMP

#include "utils.h"

void shaker_sort_cmp(int*& arr, int n, long long &cmp) {
    int left = 0;
    int right = n - 1;
    do {
    	int j = right - 1;
    	while(++cmp && j >= left){
    		++cmp;
    		if(arr[j] > arr[j + 1])
    			swap(arr[j], arr[j + 1]);
    	  	--j;
    	}
      left++;
     	int i = left;
     	while(++cmp && i < right){
     		++cmp;
     		if(arr[i] > arr[i + 1])
     			swap(arr[i], arr[i + 1]);
     		++i;
     	} 
      right--;
    } while (++cmp && left < right);
}

#endif