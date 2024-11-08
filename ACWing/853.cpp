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

const int maxn = 100005;
int n, m;
int k;

int from[maxn], to[maxn], pre[maxn], last[maxn];
int w[maxn];
int cnt;
inline void addEdge (int u, int v, int ww)
{
    cnt ++;
    from[cnt] = u;
    to[cnt] = v;
    w[cnt] = ww;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int dis[maxn];
int backup_dis[maxn];

void bellman_ford()
{
    memset (dis, 0x3f, sizeof (dis));
    dis[1] = 0;
    for (int t = 1; t <= k; t++)
    {
        memcpy (backup_dis, dis, sizeof (dis));
        for (int i = 1; i <= cnt; i++)
        {
            int u = from[i];
            int v = to[i];

            dis[v] = min (dis[v], backup_dis[u] + w[i]);
        }
    }
}

int main ()
{
    n = Reader::read();
    m = Reader::read();
    k = Reader::read();

    for (int i = 1; i  <= m; i++)
    {
        int u = Reader::read();
        int v = Reader::read();
        int ww = Reader::read();

        addEdge (u, v, ww);
    }

    bellman_ford () ;
    if (dis[n] > 0x3f3f3f3f / 2)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << dis[n] << endl;
    }

    return 0;
}