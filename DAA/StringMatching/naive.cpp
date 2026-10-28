#include <iostream>
#include <string>
using namespace std;

void naive(const string &t, const string &p)
{
    int s = t.length();
    int m = p.length();
    for (int i = 0; i < s - m + 1; i++)
    {
        int j = 0;
        while (j < m)
        {
            if (t[i + j] == p[j])
                j++;
            else
                break;
        }
        if (j == m)
            cout << "Found at index: " << i + 1;
    }
}

int main()
{
    string t, p;
    getline(cin, t);
    getline(cin, p);
    naive(t, p);
}