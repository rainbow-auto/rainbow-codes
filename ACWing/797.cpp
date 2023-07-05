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

const int maxn = 100005;
int n, m;

int a[maxn];
int b[maxn];

void insert (int l, int r, int x)
{
    a[l] += x;
    a[r + 1] -= x;
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        insert (i, i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        insert (l, r, x);
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}