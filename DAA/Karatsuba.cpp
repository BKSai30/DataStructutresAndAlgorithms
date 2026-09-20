#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getLength(long long n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

long long kar(long long x, long long y)
{
    if (x < 10 || y < 10)
    {
        return x * y;
    }
    int n1 = getLength(x);
    int n2 = getLength(y);
    int n = max(n1, n2) / 2;
    long long  p = pow(10, n);
    long long x1 = x / p;
    long long x2 = x % p;
    long long y1 = y / p;
    long long y2 = y % p;

    long long z0 = kar(x1, y1);
    long long z2 = kar(x2, y2);
    long long z1 = kar(x1 + x2, y1 + y2) - z0 - z2;
    return (z0 * pow(10, 2 * n) + z1 * pow(10, n) + z2);
}

int main()
{
    long long x = 2134;
    long long y = 3456;
    cout << kar(x, y);
}
