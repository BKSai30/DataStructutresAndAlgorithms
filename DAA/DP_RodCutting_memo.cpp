#include <iostream>
#include <algorithm>
#include <cmath>

// top down approach
//  as we first call the top most and then try to complete all the
//  ones below it to reach to the top again
int maxProfit(int *profit, int i, int *memo)
{
    if (i == 0)
        return 0;
    if (memo[i - 1] != -1)
        return memo[i - 1];
    int ans = 0;
    for (int j = 1; j <= i; j++)
    {
        ans = max(ans, profit[j - 1] + maxProfit(profit, i - j, memo));
    }
    memo[i - 1] = ans;
    return memo;
}

int cutRod(int *profit, int n)
{
    int memo[n];
    for (int i = 0; i < n; i++)
    {
        memo[i] = -1;
    }
    return maxProfit(profit, n, memo);
}