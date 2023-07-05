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

int to[maxn], pre[maxn], last[maxn];
int cnt;
int w[maxn];
inline void addEdge (int u,int v, int ww)
{
    cnt ++;
    w[cnt] = ww;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int dis[maxn];
int inq[maxn];
int times[maxn];

bool SPFA ()
{
    memset (dis, 0x3f, sizeof (dis));
    dis[1] = 0;
    memset (inq, 0, sizeof (inq));
    memset (times, 0, sizeof (times));

    queue<int> q;
    q.push (1);
    inq[1] = true;

    while (not q.empty())
    {
        int u = q.front(); q.pop();
        inq[u] = false;

        for (int i = last[u]; i; i = pre[i])
        {
            int v = to[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                if (not inq[v])
                {
                    times[v] ++;
                    
                    if (times[v] >= n)
                    {
                        return false;
                    }
                    inq[v] = true;
                    q.push (v);
                }
            }
        }
    }
    return true;
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
        if (u == v) continue;
        
        addEdge(u, v, ww);
    }

    SPFA();
    if (dis[n] == 0x3f3f3f3f)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << dis[n] << endl;
    }

    return 0;
}