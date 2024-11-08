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
int n, m;
int to[maxn], pre[maxn], last[maxn], cnt;

inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int dis[maxn];
int bfs ()
{
    memset (dis, -1, sizeof (dis));
    queue<int> q;
    q.push (1);
    dis[1] = 0;
    while (not q.empty ())
    {
        int u = q.front(); q.pop();
        for (int i = last[u]; i; i = pre[i])
        {
            int v = to[i];
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            q.push (v);
        }
    }
    return dis[n];
}

int main ()
{
    n = Reader::read();
    m = Reader::read();

    for (int i = 1; i <= m; i++)
    {
        int u = Reader::read();
        int v = Reader::read();

        addEdge (u, v);
    }

    cout << bfs () << endl;

    return 0;
}