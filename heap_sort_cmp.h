#ifndef HEAP_SORT_CMP
#define HEAP_SORT_CMP

#include "utils.h"

void Heapify(int*& arr, int n, int i, long long &cmp){
	int largest = i; // khoi tao largest nhu la root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// Neu nut con trai lon hon so voi root
	++cmp;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Neu nut con phai lon hon so voi root
	++cmp;
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Neu root khong phai la lon nhat
	++cmp;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest, cmp);
	}
}
void heap_sort_cmp(int*& arr, int n, long long &cmp){
	int i = n / 2 - 1;
	while(++cmp && i >= 0){
		Heapify(arr, n, i, cmp);
		--i;
	}
	i = n - 1;
	while(++cmp && i >= 0){
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0, cmp);
		--i;
   }               
}
#endif