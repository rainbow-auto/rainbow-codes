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

using i64 = long long;

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 2005;

int n, m;
char a[maxn][maxn];

struct Node {
    char ch;

    int x, y;

    friend bool operator < (Node a, Node b) {
        return a.ch > b.ch;
    }
};

bool vis[maxn][maxn];
Node pre[maxn][maxn];

int main () {
	fastread

    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);

    std::cin >> n >> m;

    rep (i, 0, n + 1) { rep (j, 0, m + 1) { vis[i][j] = true; } }

    rep (i, 1, n) { rep (j, 1, m) { std::cin >> a[i][j]; vis[i][j] = false; } }

    std::priority_queue <Node> q;
    q.push (Node { a[1][1], 1, 1 });
    
    std::string ans; ans = ans + a[1][1];

    while (true) {
        std::priority_queue <Node> nxt;

        while (not q.empty ()) {
            auto now = q.top (); q.pop ();

            if (not vis[now.x + 1][now.y]) { 
                vis[now.x + 1][now.y] = true;
                pre[now.x + 1][now.y] = now; 
                nxt.push (Node { a[now.x + 1][now.y], now.x + 1, now.y }); 
            }
            if (not vis[now.x][now.y + 1]) { 
                vis[now.x][now.y + 1] = true;
                pre[now.x][now.y + 1] = now; 
                nxt.push (Node { a[now.x][now.y + 1], now.x, now.y + 1 }); 
            }
        }

        if (nxt.empty ()) { break; }

        ans = ans + nxt.top ().ch;

        char ch = nxt.top ().ch;
        while (not nxt.empty ()) {
            if (nxt.top ().ch == ch) { q.push (nxt.top ()); }
            nxt.pop ();
        }
    }

    rep (i, 0, ans.size () - 1) { std::cout << ans[i]; } std::cout << "\n";
    
	return 0;
}
