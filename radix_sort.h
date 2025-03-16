#ifndef RADIX_SORT
#define RADIX_SORT

int GetMax(int*& arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void Counting(int*& arr, int size, int div)
{
    int* arrl = new int[size];
    int count[10] = { 0 };

    for (int i = 0; i < size; i++) {
        count[(arr[i] / div) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        arrl[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = arrl[i];
    }
    delete[] arrl;
}
void radix_sort(int*& arr, int size)
{
    int m = GetMax(arr, size);
    for (int div = 1; m / div > 0; div *= 10)
        Counting(arr, size, div);
}
#endif