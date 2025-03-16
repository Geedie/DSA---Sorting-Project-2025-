#ifndef MERGE_SORT_CMP
#define MERGE_SORT_CMP

void merge(int*& a, int start, int mid, int end, long long &cmp){
	int p = start, q = mid + 1;
	int k = 0;
	int *t = new int[end - start + 1];
	for(int i = start;++cmp && i <= end; ++i){
		if(++cmp && p > mid)
			t[k++] = a[q++];
		else if(++cmp && q > end)
			t[k++] = a[p++];
		else if(++cmp && a[p] < a[q])
			t[k++] = a[p++];
		else
		 	t[k++] = a[q++];
	}
	for(p = 0;++cmp && p < k; ++p){
		a[start++] = t[p];
	}
	delete t;
}

void mergesort(int*& a, int start, int end, long long &cmp){
	++cmp;
	if(start < end){
		int mid = (start + end) / 2;
		mergesort(a, start, mid, cmp);
		mergesort(a, mid + 1, end, cmp);
		merge(a, start, mid, end, cmp);
	}
}

void merge_sort_cmp(int*& a, int n, long long &cmp){
	mergesort(a, 0, n - 1, cmp);
}

#endif