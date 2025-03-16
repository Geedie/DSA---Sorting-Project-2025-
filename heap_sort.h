#ifndef HEAP_SORT
#define HEAP_SORT

#include "utils.h"

void Heapify(int*& arr, int n, int i){
	int largest = i; // khoi tao largest nhu la root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// Neu nut con trai lon hon so voi root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Neu nut con phai lon hon so voi root
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Neu root khong phai la lon nhat
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}
void heap_sort(int*& arr, int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}
#endif