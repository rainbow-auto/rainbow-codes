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
const int maxn = 1.5e5;
int n, m;

int to[maxn], pre[maxn], last[maxn];
int w[maxn];
int cnt;

inline void addEdge (int u, int v, int ww)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
    w[cnt] = ww;
}

struct Node{
    int id;
    int dis;
    friend bool operator < (Node a, Node b)
    {
        return a.dis > b.dis; // priority_queue
    }
};

int dis[maxn];
bool vis[maxn];

void dij ()
{
    memset (vis, 0, sizeof(vis));
    memset (dis, 0x3f, sizeof(dis));
    dis[1] = 0;

    priority_queue <Node> q;
    q.push (Node{1, dis[1]});

    while (not q.empty())
    {
        int u = q.top().id; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = last[u]; i; i = pre[i])
        {
            int v = to[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                q.push(Node{v, dis[v]});
            }
        }
    }
}

int main ()
{
    n = Reader::read();
    m = Reader::read();

    for (int i = 1; i <= m; i++)
    {
        int u = Reader::read();
        int v = Reader::read();
        int ww = Reader::read();

        addEdge (u, v, ww);
    }

    dij ();

    if (dis[n] == 0x3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[n] << endl;
    }

    return 0;
}