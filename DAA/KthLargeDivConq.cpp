#include <iostream>
using namespace std;

void swaping(int *arr, int a, int b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}
int findMax(int *arr, int low, int high)
{
    int max = low;
    for (int i = low; i < high + 1; i++)
    {
        if (arr[i] > arr[max])
            max = i;
    }
    return max;
}
int findMin(int *arr, int low, int high)
{
    int min = low;
    for (int i = low; i < high + 1; i++)
    {
        if (arr[i] < arr[min])
            min = i;
    }
    return min;
}
int partition(int *arr, int low, int high)
{
    int pivot = (low + high) / 2;
    swaping(arr, pivot, high);
    pivot = high;
    int i = low, j = high - 1;
    while (i <= j)
    {
        if (arr[i] < arr[pivot])
            i++;
        else if (arr[j] > arr[pivot])
            j--;
        else if (i <= j)
            swaping(arr, i++, j--);
    }
    swaping(arr, i, pivot);
    return i;
}
void kLargest(int *arr, int low, int high, int index)
{
    if (low <= high)
    {
        int mid = partition(arr, low, high);
        if (mid == index)
            cout << arr[mid];
        else if (mid < index)
        {
            kLargest(arr, mid + 1, high, index);
        }
        else if (mid > index)
        {
            kLargest(arr, low, mid - 1, index);
        }
    }
}

int main()
{
    int n = 5;
    int k = 3;
    int arr[] = {4, 3, 76, 32, 1};
    kLargest(arr, 0, 4, n - k);
}