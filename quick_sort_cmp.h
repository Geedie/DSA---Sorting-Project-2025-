#ifndef QUICK_SORT_CMP
#define QUICK_SORT_CMP

#include "utils.h"

void quicksort(int*& a, int l, int r, long long &cmp){
	++cmp;
	if(l == r)
		return;
  	int pivot = a[getRandom(l, r)];
  	int left = l, right = r;
  	while(++cmp && left <= right){
  		while(++cmp && a[left] < pivot) ++left;
  		while(++cmp && a[right] > pivot) --right;
  		++cmp;
  		if(left <= right){
  			swap(a[left], a[right]);
  			++left;
  			--right;
  		}
  	}
  	++cmp;
  	if(left < r)
  		quicksort(a, left, r, cmp);
  	++cmp;
  	if(l < right)
  		quicksort(a, l, right, cmp);
}
	
void quick_sort_cmp(int*& arr, int n, long long &cmp){
    quicksort(arr, 0, n - 1, cmp);
}

#endif