#ifndef COUNT_SORT
#define COUNT_SORT

void counting_sort(int*& a, int n){
	int maxE = a[0];
	for(int i = 1; i < n; ++i)
		if(a[i] > maxE)
			maxE = a[i];
	int *freq = new int[maxE];
	for(int i = 0; i <= maxE; ++i)
		freq[i] = 0;
	for(int i = 0; i < n; ++i)
		freq[a[i]]++;
	int j = 0;
	for(int i = 0; i <= maxE; ++i){
		int repeat = freq[i];
		while(repeat--){
			a[j++] = i;
		}		
	}
	delete freq;
}

#endif