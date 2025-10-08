#include <bits/stdc++.h>
#pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

int n, m;

constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = {0, 1, 0, -1, -1, 1, 1, -1 };

namespace Task1 {
    constexpr int maxn = 105;
    int a[maxn][maxn];
    bool vis[maxn][maxn];
    bool col[maxn][maxn];

    bool dfs(int nowx, int nowy) {
        if (nowx < 1 or nowx > n) return false;
        if (nowy < 1 or nowy > n) return false;

        bool res = true;
        rep (k, 0, 7) {
            int tx = nowx + dx[k];
            int ty = nowy + dy[k];
            if (not vis[tx][ty] and a[tx][ty] == 0) {
                vis[tx][ty] = true;
                res &= dfs(tx, ty);
            }
        }
        return res;
    }
    
    std::queue<std::pair<int, int>> q;
    bool bfs(int nowx, int nowy) {
        q.push({nowx, nowy});

        bool flg = true;
        while (not q.empty()) {
            auto [nowx, nowy] = q.front(); q.pop();
            if (nowx < 1 or nowx > n or nowy < 1 or nowy > n) {
                flg = false;
                continue;
            }

            rep (k, 0, 7) {
                int tx = nowx + dx[k];
                int ty = nowy + dy[k];
                if (not vis[tx][ty] and a[tx][ty] == 0) {
                    vis[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
        }
        return flg;
    }

    inline int calc() {
        std::memset(vis, 0, sizeof vis);

        int res = 0;
        rep (i, 1, n) {
            rep (j, 1, n) {
                if (not vis[i][j] and not a[i][j]) {
                    res += dfs(i, j);
                }
            }
        }

        return res;
    }

    inline void solve() {
        while (m--) {
            int z; std::cin >> z;
            int x, y; std::cin >> x >> y;
            if (z == 1) a[x][y] = 1;
            if (z == -1) a[x][y] = 0;
            
            std::cout << calc() << "\n";
        }
    }
}

void solve() {
    std::cin >> n >> m;

    Task1::solve();
    lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("well")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
