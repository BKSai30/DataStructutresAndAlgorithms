#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int lcs(const string &a, const string &b, int i, int j, vector<vector<int>> &memo)
{
    if (i == 0 || j == 0)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (a[i - 1] == b[j - 1])
    {
        memo[i][j] = 1 + lcs(a, b, i - 1, j - 1, memo);
    }
    else
    {
        memo[i][j] = max(lcs(a, b, i - 1, j, memo), lcs(a, b, i, j - 1, memo));
    }
    return memo[i][j];
}

int initialise(const string &a, const string &b)
{
    int n1 = a.length();
    int n2 = b.length();
    vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));
    return lcs(a, b, n1, n2, memo);
}