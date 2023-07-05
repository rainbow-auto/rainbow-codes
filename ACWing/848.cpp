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

int in[maxn];

inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;

    in[v] ++;
}

void bfs ()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (not q.empty())
    {
        int u = q.front (); q.pop();
        ans.push_back (u);
        for (int i = last[u]; i; i = pre[i])
        {
            int v = to[i];
            in[v] --;
            if (in[v] == 0)
            {
                q.push(v);
            }
        }
    }   
    if (ans.size() == n)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << -1 << endl;
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

        addEdge (u, v);
    }

    bfs ();

    return 0;
}