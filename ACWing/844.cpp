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

const int maxn = 105;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};

int n, m;
int a[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn];

struct Node{
    int x, y;
};

int bfs ()
{
    memset (vis, 0, sizeof (vis));
    queue<Node> q;
    q.push(Node{1, 1});
    dis[1][1] = 0;
    vis[1][1] = true;

    while (not q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int px = dx[i] + x;
            int py = dy[i] + y;

            if (px < 1 or px > n) continue;
            if (py < 1 or py > m) continue;
            if (a[px][py]) continue;
            if (vis[px][py]) continue;
            
            vis[px][py] = true;
            q.push (Node{px, py});
            dis[px][py] = dis[x][y] + 1;
        }
    }

    return dis[n][m];
}

int main ()
{
    n = Reader::read();
    m = Reader::read();
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    cout << bfs () << endl;

    return 0;
}