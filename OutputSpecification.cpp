#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <chrono>
#include "func.h" 
#include "DataGenerator.h"

using namespace std;
using namespace std::chrono;

// Biến toàn cục để đếm số lần so sánh
long long comparison_count = 0;

// Lưu mảng vào file
void saveArrayToFile(const string& filename, const vector<int>& arr) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    outFile << arr.size() << endl;
    for (int num : arr) {
        outFile << num << " ";
    }
    outFile.close();
}

// Lấy mảng từ file
void loadArrayFromFile(const string& filename, vector<int>& arr) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    int n, value;
    inFile >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        inFile >> arr[i];
    }
    inFile.close();
}

// Hàm đo thời gian và số lần so sánh
void MeasureSort(void (*sortFunc)(vector<int>&), vector<int>& arr, const string& algorithm_name, const string& outputParam) {
    vector<int> arr_copy = arr;
    comparison_count = 0;

    auto start = high_resolution_clock::now();
    sortFunc(arr_copy);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    if (outputParam == "-time" || outputParam == "-both") {
        cout << "Execution time: " << duration.count() << " microseconds" << endl;
    }
    if (outputParam == "-comp" || outputParam == "-both") {
        cout << "Number of comparisons: " << comparison_count << endl;
    }

    saveArrayToFile("output.txt", arr_copy);
}

// Hàm so sánh 2 thuật toán sắp xếp
void compareSorts(const string& algo1, const string& algo2, vector<int>& arr) {
    cout << "Comparing " << algo1 << " vs " << algo2 << endl;
    executeSort(algo1, arr, "-both");
    executeSort(algo2, arr, "-both");
}

// Hàm thực thi thuật toán sắp xếp dựa vào tên thuật toán
void executeSort(const string& algorithm, vector<int>& arr, const string& outputParam) {
    if (algorithm == "selection-sort") MeasureSort(selectionSort, arr, algorithm, outputParam);
    else if (algorithm == "insertion-sort") MeasureSort(insertionSort, arr, algorithm, outputParam);
    else if (algorithm == "shell-sort") MeasureSort(shellSort, arr, algorithm, outputParam);
    else if (algorithm == "bubble-sort") MeasureSort(bubbleSort, arr, algorithm, outputParam);
    else if (algorithm == "heap-sort") MeasureSort(heapSort, arr, algorithm, outputParam);
    else if (algorithm == "merge-sort") MeasureSort(mergeSort, arr, algorithm, outputParam);
    else if (algorithm == "quick-sort") MeasureSort(quickSort, arr, algorithm, outputParam);
    else if (algorithm == "radix-sort") MeasureSort(radixSort, arr, algorithm, outputParam);
    else if (algorithm == "counting-sort") MeasureSort(countingSort, arr, algorithm, outputParam);
    else {
        cerr << "Unknown sorting algorithm: " << algorithm << endl;
        return;
    }
}