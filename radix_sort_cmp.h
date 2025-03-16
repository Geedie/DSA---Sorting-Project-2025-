#ifndef RADIX_SORT_CMP
#define RADIX_SORT_CMP

int GetMax(int*& arr, int size, long long &cmp)
{
    int max = arr[0];
    int i = 1;
    while(++cmp && i < size){
    		++cmp;
    		if(arr[i] > max)
    			max = arr[i];
    		++i;	
    }                    
    return max;
}
void Counting(int*& arr, int size, int div, long long &cmp)
{
    int* arrl = new int[size];
    int count[10] = { 0 };
    int i = 0;
    while(++cmp && i < size){
    	count[(arr[i] / div) % 10]++;
    	++i;
    }
    i = 1;
    while(++cmp && i < 10){
    	count[i] += count[i - 1];
    	++i;
    }
    i = size - 1;
    while(++cmp && i >= 0){
    		arrl[count[(arr[i] / div) % 10] - 1] = arr[i];
    		count[(arr[i] / div) % 10]--;
    		--i;	
    }
    i = 0;
    while(++cmp && i < size){
    	arr[i] = arrl[i];
    	++i;
    }
    delete[] arrl;
}
void radix_sort_cmp(int*& arr, int size, long long &cmp)
{
    int m = GetMax(arr, size, cmp);
    int div = 1;
    while(++cmp && m / div > 0){
    		Counting(arr, size, div, cmp);
    		div *= 10;		
    }                            
}
#endif