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

const int maxn = 1005;
int n, m;
int q;
int d[maxn][maxn]; // 差分数组
int s[maxn][maxn]; // 前缀和数组

int a[maxn][maxn]; // 原数组

inline void insert (int x1, int y1, int x2, int y2, int x)
{
    d[x2 + 1][y2 + 1] += x;
    d[x2 + 1][y1] -= x;
    d[x1][y2 + 1] -= x;
    d[x1][y1] += x;
}

void init ()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            insert (i, j, i, j, a[i][j]);
        }
    }
}

void build_sum ()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + d[i][j]; 
        }
    }
}

int main ()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    init ();
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2, x;
        cin >> x1 >> y1 >> x2 >> y2 >> x;
        insert (x1, y1, x2, y2, x);
    }

    build_sum ();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}