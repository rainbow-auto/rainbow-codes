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

const int maxn = 200005;

int n;
int to[maxn], pre[maxn], last[maxn], cnt;
inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

bool vis[maxn];
int siz[maxn];

int mx;

void dfs (int now)
{
    int res = 0;
    siz[now] = 1;
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        if (vis[t]) continue;
        vis[t] = true;
        dfs (t);
        siz[now] += siz[t];
        res = max (res, siz[t]);
    }
    res = max (res, n - siz[now]);
    if (res < mx)
    {
        mx = res;
    }
}

int main ()
{
    n = Reader::read();

    for (int i = 1; i <= n - 1; i++)
    {
        int u = Reader::read();
        int v = Reader::read();
        addEdge (u, v);
        addEdge (v, u);
    }

    memset (vis, 0, sizeof (vis));
    mx = 0x3f3f3f3f;

    dfs (1);

    cout << mx << endl;

    return 0;
}