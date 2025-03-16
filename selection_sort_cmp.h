#ifndef SELECTION_SORT_CMP
#define SELECTION_SORT_CMP

#include "utils.h"

void selection_sort_cmp(int*& arr, int n, long long &cmp){
	int i = 0;
	while(++cmp && i < n){
		int k = i;
		int j = i + 1;
		while(++cmp && j < n){
			++cmp;
			if(arr[j] < arr[k])
				k = j;
			++j;
		}
		swap(arr[i], arr[k]);
		++i;
	}
}
#endif