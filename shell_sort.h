#ifndef SHELL_SORT
#define SHELL_SORT

int gaps[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};

void shell_sort(int*& a, int n){
	      
	for(int k = 0; k < 9; ++k){
		for(int i = gaps[k]; i < n; ++i){
			int cur = a[i];
			int j = i;
			for(; j >= gaps[k] && a[j - gaps[k]] > cur; j -= gaps[k])
				a[j] = a[j - gaps[k]];
		  	a[j] = cur;
	  }
	}
}

#endif