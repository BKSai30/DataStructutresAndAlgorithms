#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix(const string &p)
{
    int m = p.length();
    vector<int> arr(m, -1);
    int k = -1;
    for (int i = 1; i < m; i++)
    {
        while (k >= 0 && p[k + 1] != p[i])
        {
            k = arr[k];
        }
        if (p[k + 1] == p[i])
        {
            k++;
        }
        arr[i] = k;
    }
    return arr;
}
void kmp(const string &t, const string &p)
{
    int s = t.length();
    int m = p.length();
    vector<int> arr = prefix(p);
    int k = -1;
    for (int i = 0; i < s; i++)
    {
        while (k >= 0 && p[k + 1] != t[i])
        {
            k = arr[k];
        }
        if (p[k + 1] == t[i])
        {
            k++;
        }
        if (k == m - 1)
        {
            cout << "Found at index: " << i - m + 1 << endl;
            k = arr[k];
        }
    }
}

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);
    kmp(t, p);
}

/* #include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix(const string &p)
{
    int k = -1;
    int m = p.length();
    vector<int> arr(m, -1);
    for (int i = 1; i < m; i++)
    {
        while (k >= 0 && p[k + 1] != p[i])
        {
            k = arr[k];
        }
        if (p[k + 1] == p[i])
        {
            k++;
        }
        arr[i] = k;
    }
    return arr;
}

void kmp(const string &T, const string &P)
{
    int m = P.length();
    int s = T.length();
    vector<int> arr = prefix(P);
    int k = -1;
    for (int i = 0; i < s; i++)
    {
        while (k >= 0 && P[k + 1] != T[i])
        {
            k = arr[k];
        }
        if (P[k + 1] == T[i])
            k++;
        if (k == m - 1)
        {
            cout << "Found at index: " << i - m + 1 << endl;
            k = arr[k];
        }
    }
}

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);
    kmp(t, p);
} */