#ifndef MERGE_SORT
#define MERGE_SORT
void merge(int*& a, int start, int mid, int end){
	int p = start, q = mid + 1;
	int k = 0;
	int *t = new int[end - start + 1];
	for(int i = start; i <= end; ++i){
		if(p > mid)
			t[k++] = a[q++];
		else if(q > end)
			t[k++] = a[p++];
		else if(a[p] < a[q])
			t[k++] = a[p++];
		else
		 	t[k++] = a[q++];
	}
	for(p = 0; p < k; ++p){
		a[start++] = t[p];
	}
	delete t;
}

void mergesort(int*& a, int start, int end){
	if(start < end){
		int mid = (start + end) / 2;
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

void merge_sort(int*& a, int n){
	mergesort(a, 0, n - 1);
}

#endif