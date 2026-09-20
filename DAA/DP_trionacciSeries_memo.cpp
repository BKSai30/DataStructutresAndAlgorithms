#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int fib(int i, int *memo)
{
    if (i <= 2)
        return 0;
    if (i == 3)
        return 1;
    if (memo[i] != -1)
        return memo[i];
    memo[i] = fib(i - 1, memo) + fib(i - 2, memo) + fib(i - 3, memo);
    return memo[i];

    int findFib(int n)
    {
        if (n <= 2)
            return 0;
        int memo[n + 1];
        for (int i = 0; i <= n; i++)
        {
            memo[i] = -1;
        }
        return fib(n, memo);
    }