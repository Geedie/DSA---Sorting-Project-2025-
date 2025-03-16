#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "utils.h"

void bubble_sort(int*& a, int n){
    for(int i = n; i > 1; --i){
    	 for(int j = 1; j < i; ++j){
    		 if(a[j - 1] > a[j])
    			 swap(a[j - 1], a[j]);
    	 } 
    }
}        
#endif