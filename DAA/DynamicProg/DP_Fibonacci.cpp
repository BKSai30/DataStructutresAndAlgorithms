#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/* int fib(int n)
{
    int result;
    if (n == 1 || n == 2)
        result = 1;
    else
        result = fib(n - 1) + fib(n - 2);
    return result;
} */

int fib(int n, int *memo)
{
    if (memo[n] != -1)
        return memo[n];
    int result;
    if (n == 1 || n == 2)
        result = 1;
    else
        result = fib(n - 1, memo) + fib(n - 2, memo);
    memo[n] = result;
    return result;
}

int main()
{
    int n = 4;
    int memo[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    cout << fib(n, memo);
}