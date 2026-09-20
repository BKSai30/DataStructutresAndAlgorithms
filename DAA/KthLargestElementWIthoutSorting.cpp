#include <iostream>

using namespace std;

int findMax(int *arr, int low, int high)
{
    int max = low;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] > arr[max])
            max = i;
    }
    return max;
}
int findMin(int *arr, int low, int high)
{
    int min = low;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] < arr[min])
            min = i;
    }
    return min;
}
void swaping(int *arr, int a, int b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}
int kLargest(int *arr, int k, int n)
{
    if (k == n)
        return arr[findMin(arr, 0, n - 1)];
    if (k == 1)
        return arr[findMax(arr, 0, n - 1)];
    int r = n - k;
    int max = findMax(arr, 0, r);
    int min = findMin(arr, r + 1, n - 1);
    while (arr[max] > arr[min])
    {
        swaping(arr, max, min);
        max = findMax(arr, 0, r);
        min = findMin(arr, r + 1, n - 1);
    }
    return arr[findMax(arr, 0, r)];
}

int main()
{
    int n = 5;
    int arr[] = {4, 3, 76, 32, 1};
    int k = 3;
    cout << kLargest(arr, k, n);
}