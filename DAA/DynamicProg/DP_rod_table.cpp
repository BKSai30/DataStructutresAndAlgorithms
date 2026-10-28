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
            dp[i] = max(dp[i], profit[j - 1] + dp[i - j]); // dp[i]=max profit obtained from rod of length i
            // we are trying to first find for length 1, then using that
            // find for length 2 , we keep doing and finally find for length n
            // so for i=1, we can do max(1+max(0)) only ; for i=2 we can divide rod into max(1+max(1)), max(2+max(0));
            // for i=3 we can divide rod into max(1+max(2)),max(2+max(1)),max(3+max(0)) like this we do
            // and finally we can find for n .
        }
    }
    return dp[n];
}