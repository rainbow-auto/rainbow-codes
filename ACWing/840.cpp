#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

namespace Reader{
    int read ()
    {
        char c = getchar (); 
        int x = 0, flag = 1;
        while (not isdigit (c)) { if (c == '-') flag = -1; c = getchar(); }
        while (isdigit (c)) { x = x * 10 + c - '0'; c = getchar(); }
        return x * flag;
    }
}

const int null = 0x3f3f3f3f;
const int maxn = 1000005;
int n;
int h[maxn];

int find(int x)
{
    int t = (x % n + n) % n;
    while (h[t] != null and h[t] != x)
    {
        t++;
        if (t == n)
        {
            t = 0;
        }
    }
    return t;
}

int main ()
{
    memset (h, 0x3f, sizeof (h));
    n = Reader::read();
    for (int i = 1; i <= n; i++)
    {
        string op;
        cin >> op;
        if (op == "Q")
        {
            int x = Reader::read();
            if (h[find(x)] != null)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (op == "I") 
        {
            int x = Reader::read();
            h[find(x)] = x;
        }
    }

    return 0;
}