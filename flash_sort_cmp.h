#ifndef FLASH_SORT_CMP
#define FLASH_SORT_CMP

void flash_sort_cmp(int*& a, int n, long long &cmp){
	++cmp;
	if(n <= 1)
		return;
	int m = 0.43 * n;
	++cmp;
	if(m <= 2)
		m = 2;
	int *L = new int[m];
	int i = 0;
	while(++cmp && i < m){
		L[i] = 0;
		++i;
	}           
	int Mx = a[0];
	int mx = a[0];
	i = 1;
	while(++cmp && i < n){
		++cmp;
		if(a[i] > Mx)
			Mx = a[i];
		++cmp;
		if(a[i] < mx)
			mx = a[i];
		++i;
	}
	++cmp;
	if(Mx == mx)
		return;
#define calcK(x) 1ll * (m - 1) * (x - mx) / (Mx - mx)
   i = 0;
   while(++cmp && i < n){
   	++L[calcK(a[i])];
   	++i;
   }
  	i = 1;
  	while(++cmp && i < m){
  	 	L[i] += L[i - 1];
  	 	++i;
   }
 	int _move = 0;
 	i = 0;
 	while(++cmp && _move < n){
 		int k = calcK(a[i]);
 		while(++cmp && i >= L[k]){
 			k = calcK(a[++i]);
 		}
 		int t = a[i];
 		while(++cmp && i != L[k]){
 			k = calcK(t);
 			int p = a[L[k]-1];
 			a[--L[k]] = t;
 			t = p;
 			++_move;
 		}
 	}
 	int k = 1;
 	while(++cmp && k < m){
 		i = L[k] - 2;
 		while(++cmp && i >= L[k - 1]){
 			++cmp;
 			if(a[i] > a[i + 1]){
 				int t = a[i];
 				int j = i;
 				while(++cmp && t > a[j + 1]){
 					a[j] = a[j + 1];
 					++j;
 				}
 				a[j] = t;
 			}
 			--i;
 		}
 		++k;
 	}
}

#endif