#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#pragma once
using namespace std;

void printArray(const vector<int>& arr);

void selectionSort(vector<int>& arr);

void insertionSort(vector<int>& arr);

void shellSort(vector<int>& arr);

void bubbleSort(vector<int>& arr);

void heapify(vector<int>& arr, int n, int i);
void heapSort(vector<int>& arr);

void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);
void mergeSort(vector<int>& arr);

int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr);

void countingSortForRadix(vector<int>& arr, int exp);
void radixSort(vector<int>& arr);

void countingSort(vector<int>& arr);

int binarySearch(const vector<int>& arr, int item, int low, int high);
void binaryInsertionSort(vector<int>& arr);

void shakerSort(vector<int>& arr);

void flashSort(vector<int>& arr);