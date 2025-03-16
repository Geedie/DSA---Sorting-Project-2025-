#ifndef FLASH_SORT
#define FLASH_SORT

void flash_sort(int*& a, int n){
	if(n <= 1)
		return;
	int m = 0.43 * n;

	if(m <= 2)
		m = 2;
	int *L = new int[m];
	
	for(int i = 0; i < m; ++i)
		L[i] = 0;
	int Mx = a[0];
	int mx = a[0];
	
	for(int i = 1; i < n; ++i){
		if(a[i] > Mx)
			Mx = a[i];
		if(a[i] < mx)
			mx = a[i];
	}
	
	if(Mx == mx)
		return;
#define calcK(x) 1ll * (m - 1) * (x - mx) / (Mx - mx)

  	for(int i = 0; i < n; ++i){
  		++L[calcK(a[i])];
  	}
 
  	for(int i = 1; i < m; ++i)
  		L[i] += L[i - 1];
 	int _move = 0;
 	int i = 0;
 	while(_move < n){
 		int k = calcK(a[i]);
 		while(i >= L[k]){
 			k = calcK(a[++i]);
 		}
 		int t = a[i];
 		while(i != L[k]){
 			k = calcK(t);
 			int p = a[L[k]-1];
 			a[--L[k]] = t;
 			t = p;
 			++_move;
 		}
 	}
 	for(int k = 1; k < m; ++k){
 		for(i = L[k] - 2; i >= L[k - 1]; --i){
 			if(a[i] > a[i + 1]){
 				int t = a[i];
 				int j = i;
 				while(t > a[j + 1]){
 					a[j] = a[j + 1];
 					j++;
 				}
 				a[j] = t;
 			}
 		}
 	}
}

#endif