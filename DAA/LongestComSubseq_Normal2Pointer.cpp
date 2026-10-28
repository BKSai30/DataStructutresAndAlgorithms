#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int lcs(string a, string b, int i, int j)
{
    if (i == a.length() || j == b.length())
        return 0;
    if (a[i] == b[j])
    {
        i++;
        j++;
        return 1 + lcs(a, b, i, j);
    }
    return max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
}
int main()
{
    string a = "ADFGBC";
    string b = "LPOAMBICOD";
    cout << lcs(a, b, 0, 0);
}