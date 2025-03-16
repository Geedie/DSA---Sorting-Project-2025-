#ifndef SHELL_SORT_CMP
#define SHELL_SORT_CMP

int gaps1[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};

void shell_sort_cmp(int*& a, int n, long long &cmp){
	int k = 0;
	while(++cmp && k < 9){
		int i = gaps1[k];
		while(++cmp && i < n){
			int cur = a[i];
			int j = i;
			while(++cmp && j >= gaps1[k] && a[j - gaps1[k]] > cur){
				a[j] = a[j - gaps1[k]];
				j -= gaps1[k];
			}
			a[j] = cur;
			++i;
		}
		++k;
   }   
}

#endif