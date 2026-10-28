#include <iostream>
using namespace std;
const int MAX = 100;

void multiply(int a[][MAX], int b[][MAX], int c[][MAX], int r1, int c1, int r2, int c2)
{
    if (c1 != r2)
    {
        cout << "error";
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int r1 = 2, c1 = 2;
    int r2 = 2, c2 = 2;
    int A[r1][MAX] = {{1, 2}, {3, 4}};
    int B[r2][MAX] = {{5, 6}, {7, 8}};
    int c[MAX][MAX];
    multiply(A, B, c, r1, c1, r2, c2);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}