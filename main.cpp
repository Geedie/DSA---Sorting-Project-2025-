#include <stdio.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#include "all_sort.h"
#include "all_sort_cmp.h"
#include "std_timer.h"
#include "DataGenerator.cpp"
using namespace std;

typedef void (*sort_ptr)(int*&, int);
sort_ptr sort_methods[] = {
	selection_sort, insertion_sort,
   bubble_sort, shaker_sort, shell_sort,
   heap_sort, merge_sort, quick_sort,
   counting_sort, radix_sort, flash_sort
};
typedef void (*sort_ptr_cmp)(int*&, int, long long &);
sort_ptr_cmp sort_cmp_methods[] = {
	selection_sort_cmp, insertion_sort_cmp,
   bubble_sort_cmp, shaker_sort_cmp, shell_sort_cmp,
   heap_sort_cmp, merge_sort_cmp, quick_sort_cmp,
   counting_sort_cmp, radix_sort_cmp, flash_sort_cmp	
};
string sort_name[] = {
	"selection-sort", "insertion-sort", "bubble-sort",
	"shaker-sort", "shell-sort", "heap-sort",
	"merge-sort", "quick-sort", "counting-sort",
	"radix-sort", "flash-sort"
};
const char* order_input[] = {
	"-rand", "-sorted", "-rev", "-nsorted"
};
const char* order_name[] = {
	"Randomize", "Sorted", "Reversed", "Sorted"
};
const char* output_para[] = {
	"-both", "-time", "-comp"
};
string get_data_type(int datatype){
	if(datatype == RANDOM)
		return "Randomize";
	else if(datatype == SORTED)
		return "Sorted";
	else if(datatype == NEARLY_SORTED)
		return "Nearly Sorted";
	return "Reversed";	
}
bool isNum(char* s){
	for(int i = 0; s[i]; ++i)
		if(!isdigit(s[i]))
			return 0;
	return 1;
}
int main(int argc, char *argv[]){
	
	if(argv[1][1] == 'a'){
		if(argc == 6){//COMMAND 2
			string name1 = argv[2];
			int n = stoi(string(argv[3]));
			int sort1 = 0;
			long long cmp = 0;
			int* a = new int[n];
			int* b = new int[n];
			int t = -1;
			for(int i = 0; i < 4; ++i)
				if(strcmp(argv[4], order_input[i]) == 0){
					GenerateData(a, n, i);
					t = i;
				}
			ofstream fo("input.txt");
			fo << n << '\n';
			for(int i = 0; i < n; ++i)
				fo << a[i] << ' ';
			fo.close();
			for(int i = 0; i < 11; ++i){
	 			if(name1 == sort_name[i])
	 				sort1 = i;
		  	}
			cout << "ALGORITHM MODE\n";
			cout << "Algorithm: " << sort_name[sort1] << '\n';
			cout << "Input size: " << n << '\n';
			cout << "Input order: " << get_data_type(t) << '\n';
			cout << "-------------------------------\n";
			int o = 0;
			for(int i = 0; i < 3; ++i){
				if(strcmp(output_para[i],argv[5]) == 0)
					o = i;
			}
			if(o == 0){
				Timer timer;
				timer.start();
				sort_methods[sort1](a, n);
				int64_t runningtime = timer.getRunningTime();
				sort_cmp_methods[sort1](b, n, cmp);
				cout << "Runing time: " << runningtime / 1000000000.0 << "secs\n";
				cout << "Comparisions: " << cmp << '\n'; 
			}
			else if(o == 1){
				Timer timer;
				timer.start();
				sort_methods[sort1](a, n);
				int64_t runningtime = timer.getRunningTime();
				cout << "Runing time: " << runningtime / 1000000000.0 << "secs\n";	
			}
			else{
	 			sort_cmp_methods[sort1](b, n, cmp);
				cout << "Comparisions: " << cmp << '\n';
			}
			ofstream fout("output.txt");
			fout << n << '\n';
			for(int i = 0; i < n; ++i)
				fout << a[i] << ' ';
			fout.close();
			delete a;
			delete b;                         
		}
		if(argc == 5){
			string name1 = argv[2];
			int n = 0;
			int sort1 = 0;
			int *a, *b;
			long long cmp = 0;
			int64_t runningtime = 0;
			for(int i = 0; i < 11; ++i){
				if(name1 == sort_name[i])
					sort1 = i;
			}
			if(isNum(argv[3])){//COMMAND 3
				cout << "ALGORITHM MODE\n";
				cout << "Algorithm: " << sort_name[sort1] << '\n';
				cout << "Input size: " << argv[3] << '\n';
				n = stoi(string(argv[3]));
				a = new int[n];
				b = new int[n];
				int o = 0;
				for(int i = 0; i < 3; ++i){
					if(strcmp(output_para[i], argv[4]) == 0)
						o = i;
				}
				for(int i = 0; i < 4; ++i){
					cmp = 0;
					GenerateData(a, n, i);
					copy_array(a, b, n);
					if(i == 0){
						ofstream f("input_1.txt");
						f << n << '\n';
						for(int z = 0; z < n; ++z)
							f << a[z] << ' ';
						f.close();
					}
					else if(i == 1){
						ofstream f("input_3.txt");
						f << n << '\n';
						for(int z = 0; z < n; ++z)
							f << a[z] << ' ';
						f.close();
					}
					else if(i == 2){
						ofstream f("input_4.txt");
						f << n << '\n';
						for(int z = 0; z < n; ++z)
							f << a[z] << ' ';
						f.close();
					}
					else{
						ofstream f("input_2.txt");
						f << n << '\n';
						for(int z = 0; z < n; ++z)
							f << a[z] << ' ';
						f.close();	
					}
					cout << "Input order: " << get_data_type(i) << '\n';
					cout << "-------------------------------\n";
					if(o == 0){
						Timer timer;
						timer.start();
						sort_methods[sort1](a, n);
						runningtime = timer.getRunningTime();
						sort_cmp_methods[sort1](b, n, cmp);
						cout << "Runing time: " << runningtime / 1000000000.0 << "secs\n";
						cout << "Comparisions: " << cmp << '\n'; 
					}
					else if(o == 1){
						Timer timer;
						timer.start();
						sort_methods[sort1](a, n);
						runningtime = timer.getRunningTime();
						cout << "Runing time: " << runningtime / 1000000000.0 << "secs\n";	
					}
					else{
						sort_cmp_methods[sort1](b, n, cmp);
						cout << "Comparisions: " << cmp << '\n';
					}
					cout << '\n';	
				}
				delete a;
				delete b;
			}
			else{//COMMAND 1
				freopen(argv[3], "r", stdin);
				cin >> n;
				a = new int[n];
				b = new int[n];
				for(int i = 0; i < n; ++i)
					cin >> a[i];
				copy_array(a, b, n);
				cout << "ALGORITHM MODE\n";
				cout << "Algorithm: " << sort_name[sort1] << '\n';
				cout << "Input file: " << argv[3] << '\n';
				cout << "Input size: " << n << '\n';
				cout << "-------------------------------\n";
				int o = 0;
				for(int i = 0; i < 3; ++i){
					if(strcmp(output_para[i], argv[4]) == 0)
						o = i;
				}
				if(o == 0){
					Timer timer;
					timer.start();
					sort_methods[sort1](a, n);
					runningtime = timer.getRunningTime();
					sort_cmp_methods[sort1](b, n, cmp);
					cout << "Runing time: " << runningtime / 1000000000.0 << "secs\n";
					cout << "Comparisions: " << cmp << '\n'; 
				}
				else if(o == 1){
					Timer timer;
					timer.start();
					sort_methods[sort1](a, n);
					runningtime = timer.getRunningTime();
					cout << "Runing time: " << runningtime / 1000000000.0 << "secs\n";	
				}
				else{
					sort_cmp_methods[sort1](b, n, cmp);
					cout << "Comparisions: " << cmp << '\n';
				}
				ofstream f("output.txt");
				f << n << '\n';
				for(int i = 0; i < n; ++i)
					f << a[i] << ' ' ;
				f.close();
				delete a;
				delete b;
			}	
		}
	}
	else if(argv[1][1] == 'c'){
		if(argc == 5){//COMMAND 4
			freopen(argv[4], "r", stdin);
			string name1 = argv[2];
			string name2 = argv[3];
			int n;
			cin >> n;
			int *a = new int[n];
			int *b = new int[n];
			int *c = new int[n];
			int *d = new int[n];
			long long cmp1 = 0, cmp2 = 0;
			for(int i = 0; i < n; ++i){
				cin >> a[i];
				b[i] = a[i];
			}
			copy_array(a, c, n);
			copy_array(b, d, n);	             
			int sort1 = -1, sort2 = -1;
			for(int i = 0; i < 11; ++i){
				if(name1 == sort_name[i])
					sort1 = i;
				if(name2 == sort_name[i])
					sort2 = i;
			}
			Timer timer1, timer2;
			timer1.start();
			sort_methods[sort1](a, n);
			int64_t running_time1 = timer1.getRunningTime();
			timer2.start();
			sort_methods[sort2](b, n);
			int64_t running_time2 = timer2.getRunningTime();
			sort_cmp_methods[sort1](c, n, cmp1);
			sort_cmp_methods[sort2](d, n, cmp2);
			cout << "COMPAREMODE\n";
			cout << "Algorithm: " << sort_name[sort1] << " | " << sort_name[sort2] << '\n';
			cout << "Input file: " << argv[4] << '\n';
			cout << "Input size: " << n << '\n';
			cout << "-------------------------------\n";
			cout << "Runing time: " << running_time1 / 1000000000.0 << "secs | " << running_time2 / 1000000000.0 <<"secs\n";
			cout << "Comparisions: " << cmp1 << " | " << cmp2 << '\n';
			delete a;
			delete b;
			delete c;
			delete d;
		}
		else{//COMMAND 5
			string name1 = argv[2];
			string name2 = argv[3];
			int n = stoi(string(argv[4]));
			int *a = new int[n];
			int *b = new int[n];
			int *c = new int[n];
			int *d = new int[n];
			int t = -1;
			long long cmp1 = 0, cmp2 = 0;
			for(int i = 0; i < 4; ++i)
				if(strcmp(argv[5], order_input[i]) == 0){
					GenerateData(a, n, i);
					t = i;
				}
			ofstream f("input.txt");
			f << n << '\n';
			for(int z = 0; z < n; ++z)
			f << a[z] << ' ';
			f.close();
			copy_array(a, b, n);
			copy_array(a, c, n);
			copy_array(a, d, n);
			int sort1 = -1, sort2 = -1;
			for(int i = 0; i < 11; ++i){
				if(name1 == sort_name[i])
					sort1 = i;
				if(name2 == sort_name[i])
					sort2 = i;
			}
			cout << "COMPAREMODE\n";
			cout << "Algorithm: " << sort_name[sort1] << " | " << sort_name[sort2] << '\n';
			cout << "Input size: " << n << '\n';
			cout << "Input order: " << get_data_type(t) << '\n';
			cout << "-------------------------------\n";	
			Timer timer1, timer2;
			timer1.start();
			sort_methods[sort1](a, n);
			int64_t running_time1 = timer1.getRunningTime();
			timer2.start();
			sort_methods[sort2](b, n);
			int64_t running_time2 = timer2.getRunningTime();
			sort_cmp_methods[sort1](c, n, cmp1);
			sort_cmp_methods[sort2](d, n, cmp2);
			cout << "Runing time: " << running_time1 / 1000000000.0 << "secs | " << running_time2 / 1000000000.0 <<"secs\n";
			cout << "Comparisions: " << cmp1 << " | " << cmp2 << '\n';
			delete a;
			delete b;
			delete c;
			delete d; 			
		}                                        	
	}
	
	return 0;
}