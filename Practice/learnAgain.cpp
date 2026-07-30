#include <iostream>
using namespace std;

/* void bubble(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                swap = 1;
            }
        }
        if (!swap)
            break;
    }
} */

void selection(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }
}

int main()
{
    int n = 5;
    int arr[] = {5, 2, 3, 1, 4};
    selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}