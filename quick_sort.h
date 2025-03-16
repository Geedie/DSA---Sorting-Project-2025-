#ifndef QUICK_SORT
#define QUICK_SORT

#include "utils.h"

void quicksort(int*& a, int l, int r){
	if(l == r)
		return;
  	int pivot = a[getRandom(l, r)];
  	int left = l, right = r;
  	while(left <= right){
  		while(a[left] < pivot) ++left;
  		while(a[right] > pivot) --right;
  		if(left <= right){
  			swap(a[left], a[right]);
  			++left;
  			--right;
  		}
  	}
  	if(left < r)
  		quicksort(a, left, r);
  	if(l < right)
  		quicksort(a, l, right);
}
	
void quick_sort(int*& arr, int n){
    quicksort(arr, 0, n - 1);
}

#endif