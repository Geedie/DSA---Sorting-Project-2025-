#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <string>
#include"func.h"
using namespace std;

// Biến toàn cục để đếm số lần so sánh
long long comparison_count = 0;

// Hàm đo thời gian và số lần so sánh 
void MeasureSort(void (*sortFunc)(int[], int), int arr[], int n, const string& algorithm_name) {
    //Tạo bản sao của mảng chính
    int* arr_copy = new int[n];
    for (int i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }

    comparison_count = 0;

    auto start = chrono::high_resolution_clock::now();

    sortFunc(arr_copy, n);


    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;

    cout << "Algorithm: " << algorithm_name << endl;
    cout << "Execution time: " << fixed << setprecision(2) << duration.count() << " ms" << endl;
    cout << "Comparisons: " << comparison_count << endl;
    cout << "----------------------------" << endl;

    // Giải phóng bộ nhớ
    delete[] arr_copy;
}

// Hàm đo và xuất kết quả ra file
void MeasureAndExport(void (*sortFunc)(int[], int), int arr[], int n, const string& algorithm_name, ofstream& outFile) {
    // Tạo bản sao của mảng chính
    int* arr_copy = new int[n];
    for (int i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }

    comparison_count = 0;

    auto start = chrono::high_resolution_clock::now();

    sortFunc(arr_copy, n);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;

    outFile << algorithm_name << "," << duration.count() << "," << comparison_count << endl;

    delete[] arr_copy;
}

// Hàm chạy tất cả thuật toán để đo kết quả
void RunAllSorts(int arr[], int n, const string& dataType) {
    //file output
    ofstream outFile;
    string filename = "sort_results_" + dataType + "_" + to_string(n) + ".csv";
    outFile.open(filename);

    outFile << "Algorithm,Time(ms),Comparisons" << endl;

    cout << "\nDATASET TYPE: " << dataType << ", SIZE: " << n << endl;
    cout << "===================================" << endl;

    MeasureSort(SelectionSort, arr, n, "Selection Sort");
    MeasureAndExport(SelectionSort, arr, n, "Selection Sort", outFile);

    MeasureSort(InsertionSort, arr, n, "Insertion Sort");
    MeasureAndExport(InsertionSort, arr, n, "Insertion Sort", outFile);

    MeasureSort(BubbleSort, arr, n, "Bubble Sort");
    MeasureAndExport(BubbleSort, arr, n, "Bubble Sort", outFile);

    MeasureSort(ShakerSort, arr, n, "Shaker Sort");
    MeasureAndExport(ShakerSort, arr, n, "Shaker Sort", outFile);

    MeasureSort(ShellSort, arr, n, "Shell Sort");
    MeasureAndExport(ShellSort, arr, n, "Shell Sort", outFile);

    MeasureSort(HeapSort, arr, n, "Heap Sort");
    MeasureAndExport(HeapSort, arr, n, "Heap Sort", outFile);

    MeasureSort(MergeSort, arr, n, "Merge Sort");
    MeasureAndExport(MergeSort, arr, n, "Merge Sort", outFile);

    MeasureSort(QuickSort, arr, n, "Quick Sort");
    MeasureAndExport(QuickSort, arr, n, "Quick Sort", outFile);

    MeasureSort(RadixSort, arr, n, "Radix Sort");
    MeasureAndExport(RadixSort, arr, n, "Radix Sort", outFile);

    MeasureSort(CountingSort, arr, n, "Counting Sort");
    MeasureAndExport(CountingSort, arr, n, "Counting Sort", outFile);

    MeasureSort(BinaryInsertionSort, arr, n, "Binary Insertion Sort");
    MeasureAndExport(BinaryInsertionSort, arr, n, "Binary Insertion Sort", outFile);

    MeasureSort(FlashSort, arr, n, "Flash Sort");
    MeasureAndExport(FlashSort, arr, n, "Flash Sort", outFile);

    outFile.close();
    cout << "Results exported to " << filename << endl;
}