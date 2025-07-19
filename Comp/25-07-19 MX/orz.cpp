#include <bits/stdc++.h>
// #pragma GCC optimize(2)

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

constexpr int maxn = 100005;
constexpr int maxm = 6;

int n, m;
int p[maxm][maxn];
int pos[maxm][maxn];

namespace Task1 {
    struct Query {
        int T;
        int id;
    };
    std::vector<Query> qs[maxn];

    std::vector<int> g[maxn];

    int dis[maxn];
    void bfs(int S) {
        std::queue<int> q;
        q.push(S);
        rep (i, 1, n) dis[i] = 0x3f3f3f3f;
        dis[S] = 0;

        while (not q.empty()) {
            int now = q.front(); q.pop();
         
            for (auto j : g[now]) {
                if (dis[j] != 0x3f3f3f3f) continue;
                q.push(j);
                dis[j] = dis[now] + 1;
            }
        }
    }

    int ans[maxn];
    inline void solve() {
        rep (i, 1, m) {
            rep (j, 1, n) pos[i][p[i][j]] = j;
        }

        rep (i, 1, n) {
            rep (j, 1, n) {
                bool flg = 0;
                rep (k, 1, m) {
                    if (pos[k][i] < pos[k][j]) flg = 1;
                }
                if (flg) g[i].push_back(j);
            }
        }
    
        int q;
        std::cin >> q;
        rep (t, 1, q) {
            int S, T; std::cin >> S >> T;
            qs[S].push_back(Query { T, t });
        }

        rep (i, 1, n) {
            bfs(i);
            for (auto qcur : qs[i]) {
                if (dis[qcur.T] == 0x3f3f3f3f) ans[qcur.id] = -1;
                else ans[qcur.id] = dis[qcur.T];
            }
        }

        rep (t, 1, q) std::cout << ans[t] << "\n";
    }
}   

void solve() {
	std::cin >> n >> m;
    rep (i, 1, m) {
        rep (j, 1, n) {
            std::cin >> p[i][j];
        }
    }

    Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("orz")

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
