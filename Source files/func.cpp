#include"func.h"

// In mảng
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

// 1. Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// 2. Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 3. Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 4. Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// 5. Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Xây dựng heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Trích xuất từng phần tử từ heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 6. Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Wrapper function for mergeSort
void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

// 7. Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Wrapper function for quickSort
void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// 8. Radix Sort
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

// 9. Counting Sort
void countingSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> count(range), output(n);

    for (int i = 0; i < n; i++) {
        count[arr[i] - min_val]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 10. Binary Insertion Sort
int binarySearch(const vector<int>& arr, int item, int low, int high) {
    if (high <= low) {
        return (item > arr[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == arr[mid]) {
        return mid + 1;
    }

    if (item > arr[mid]) {
        return binarySearch(arr, item, mid + 1, high);
    }

    return binarySearch(arr, item, low, mid - 1);
}

void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        int loc = binarySearch(arr, key, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}



// 11. Shaker Sort (Cocktail Sort)
void shakerSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // Reset biến swapped trong mỗi lần lặp
        swapped = false;

        // Di chuyển từ trái sang phải như Bubble Sort
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Nếu không có phần tử nào được hoán vị, mảng đã được sắp xếp
        if (!swapped) {
            break;
        }

        // Giảm end vì phần tử lớn nhất đã ở cuối mảng
        end--;

        // Reset biến swapped để vòng lặp ngược
        swapped = false;

        // Di chuyển từ phải sang trái
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Tăng start vì phần tử nhỏ nhất đã ở đầu mảng
        start++;
    }
}

// 12. Flash Sort
void flashSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return;
    }

    int m = n * 0.43; 
    if (m <= 2) {
        m = 2;
    }

    vector<int> L(m, 0);

    int min_val = arr[0];
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    if (max_val == min_val) {
        return; 
    }

    for (int i = 0; i < n; i++) {
        int k = ((m - 1) * (arr[i] - min_val)) / (max_val - min_val);
        L[k]++;
    }

    for (int i = 1; i < m; i++) {
        L[i] += L[i - 1];
    }

    int move = 0;
    int j = 0;
    int k = m - 1;
    int flash;

    while (move < n - 1) {
        while (j > L[k] - 1) {
            j++;
            k = ((m - 1) * (arr[j] - min_val)) / (max_val - min_val);
        }

        flash = arr[j];
        while (j != L[k]) {
            k = ((m - 1) * (flash - min_val)) / (max_val - min_val);
            int hold = arr[L[k] - 1];
            arr[L[k] - 1] = flash;
            flash = hold;
            L[k]--;
            move++;
        }
    }

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}