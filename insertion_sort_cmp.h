#ifndef INSERTION_SORT_CMP
#define INSERTION_SORT_CMP

#include "utils.h"

void insertion_sort_cmp(int*& a, int n, long long &cmp){
	int i = 1;
	while(++cmp && i < n){
		int cur = a[i];
		int j = i - 1;
		while(++cmp && j >= 0 && a[j] > cur){
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = cur;
		++i;
	}
}
#endif