#ifndef COUNT_SORT_CMP
#define COUNT_SORT_CMP

void counting_sort_cmp(int*& a, int n, long long &cmp){
	int maxE = a[0];
	int i = 1;
	while(++cmp && i < n){
		++cmp;
		if(a[i] > maxE)
			maxE = a[i];
		++i;
	}             
	int *freq = new int[maxE];
	i = 0;
	while(++cmp && i <= maxE){
		freq[i] = 0;
		++i;
	}              
	i = 0;
	while(++cmp && i < n){
		freq[a[i]]++;
		i++;
	}            
	int j = 0;
	i = 0;
	while(++cmp && i <= maxE){
		int repeat = freq[i];
		while(++cmp && repeat--){
			a[j++] = i;
		}
		++i;
	}
	delete freq;
}

#endif