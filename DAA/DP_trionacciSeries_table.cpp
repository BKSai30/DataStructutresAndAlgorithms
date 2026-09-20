#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int fin(int n)
{
    if (n <= 2)
        return 0;
    if (n == 3)
        return 1;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}