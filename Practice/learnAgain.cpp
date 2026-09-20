#include <iostream>

using namespace std;

int findMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int findMin(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < max)
            max = arr[i];
    }
    return max;
}
int kLargest(int *arr, k, n)
{
    r = n - k;
    max =
}