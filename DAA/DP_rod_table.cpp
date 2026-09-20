#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int maxProfit(int *profit, int n)
{
    int dp[n + 1];
    // even here dp[0] is just for initialisation and is useless in other aspects
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], profit[j - 1] + dp[i - j]);
        }
    }
    return dp[n];
}