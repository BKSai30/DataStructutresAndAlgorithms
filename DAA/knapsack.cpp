#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(const vector<int> &wt, const vector<int> &val, int i, int w, vector<vector<int>> &memo)
{
    if (i < 0 || w == 0)
        return 0;
    if (memo[i][w] != -1)
        return memo[i][w];
    if (wt[i] > w)
    {
        return memo[i][w] = knapsack(wt, val, i - 1, w, memo);
    }
    int include = val[i] + knapsack(wt, val, i - 1, w - wt[i], memo);
    int exclude = knapsack(wt, val, i - 1, w, memo);
    return memo[i][w] = max(include, exclude);
}