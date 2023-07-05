#include <iostream>
#include <algorithm>
#include <queue>
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

namespace Reader
{
    int read()
    {
        char c = getchar();
        int x = 0, flag = 1;
        while (not isdigit(c))
        {
            if (c == '-')
                flag = -1;
            c = getchar();
        }
        while (isdigit(c))
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return x * flag;
    }
}

const int maxn = 1000010;
int n, m;

int to[maxn], pre[maxn], last[maxn];
int cnt;
int w[maxn];

inline void addEdge (int u, int v, int ww)
{
    cnt ++;
    to[cnt] = v;
    w[cnt] = ww;
    pre[cnt] = last[u];
    last[u] = cnt;
}

struct Node{
    int id;
    int dis;
    friend bool operator < (Node a, Node b)
    {
        return a.dis > b.dis; // priority_queue
    }
};

bool inq[maxn];
int dis[maxn];
int times[maxn];

bool SPFA (int s)
{
    memset (inq, 0, sizeof (inq));
    memset (dis, 0x3f, sizeof (dis));
    dis[s] = 0;
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push (i);
        inq[i] = true;
    }

    while (not q.empty())
    {
        int u = q.front (); q.pop();
        inq[u] = false;

        for (int i = last[u]; i; i = pre[i])
        {
            int v = to[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                times[v] = times[u] + 1;
                if (times[v] >= n)
                {
                    return true; // 产生负环
                }

                if (not inq[v])
                {
                    q.push (v);
                    inq[v] = true;
                }
            }    
        }
    }
    return false; // 没有负环
}


int main()
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

    if (SPFA (1))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}