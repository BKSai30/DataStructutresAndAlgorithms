#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void rabinKarp(const string &T, const string &P, const int d, const int q)
{
    int p = 0;
    int t = 0;
    int s = T.length();
    int m = P.length();
    int h = 1;
    for (int i = 0; i < m; i++)
    {
        p = (d * p + (unsigned char)P[i]) % q;
        t = (d * t + (unsigned char)T[i]) % q;
        if (i != 0)
            h = (d * h) % q;
    }
    for (int i = 0; i < s - m + 1; i++)
    {
        if (t == p)
        {
            int j = 0;
            while (j < m)
            {
                if (T[i + j] == P[j])
                    j++;
                else
                    break;
            }
            if (j == m)
                cout << "found at index: " << i + 1 << endl;
        }
        if (i != s - m)
        {
            t = (d * (t - (h * (unsigned char)T[i])) + (unsigned char)T[i + m]) % q;
        }
    }
}

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);
    rabinKarp(t, p, 26, 13);
}

/* #include <iostream>
#include <string>
#include <cmath>
using namespace std;

void rabinKarp(const string &T, const string &P, int d, int q)
{
    int s = T.length();
    int m = P.length();
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < m; i++)
    {
        if (i != 0)
            h = (d * h) % q;
        p = (d * p + (P[i] - 'a')) % q;
        t = (d * t + (T[i] - 'a')) % q;
    }
    for (int i = 0; i < s - m + 1; i++)
    {
        if (p == t)
        {
            int j = 0;
            while (j < m)
            {
                if (T[i + j] == P[j])
                    j++;
                else
                    break;
            }
            if (j == m)
                cout << "Found at index: " << i + 1 << endl;
        }
        if (i != s - m)
        {
            t = (d * (t - (h * (T[i] - 'a'))) + (T[i + m] - 'a')) % q;
        }
    }
}

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);
    rabinKarp(t, p, 26, 13);
} */