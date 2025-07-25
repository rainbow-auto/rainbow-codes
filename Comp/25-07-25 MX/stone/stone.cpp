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

constexpr int maxn = 1005;

int n;
int a[maxn], b[maxn];


namespace Solution {
    int f[maxn][maxn], g[maxn][maxn];

    using Line = std::pair<int, int>;
    std::vector<Line> lns; 
 
    inline i64 calc(int id, i64 x) {
        return lns[id].first * x + lns[id].second;
    }

    struct DS {
        int tr[maxn << 1];

        void ins(int now, int l, int r, int f) {
            int mid = (l + r) >> 1;
            int &g = tr[now];
            if (calc(f, mid) > calc(g, mid)) std::swap(f, g);
            if (calc(f, mid))
        }

        inline void addLine(int k, int b) {
            lns.push_back(Line { k, b });
            ins(1, 0, n + 1, lns.size() - 1);
        } 
    } ft[maxn], gt[maxn];

    inline void solve() {
        std::memset(f, 0x3f, sizeof f);
        std::memset(g, 0x3f, sizeof g);

        // std::cerr << "kkkkk\n";

        f[0][0] = 0;
        rep (i, 0, n + 1) {
            rep (j, 0, n + 1) {
                if (i == 0 and j == 0) continue;
                g[i][j] = ft[j].qry(1, 0, n + 1, i) + i * i;
                // rep (k, 0, i - 1) g[i][j] = std::min(g[i][j], f[k][j] + int ((i - k) * (i - k)));

                if (a[i] == b[j]) 
                f[i][j] = gt[i].qry(1, 0, n + 1, j) + j * j;
                // rep (k, 0, j - 1) f[i][j] = std::min(f[i][j], g[i][k] + int ((j - k) * (j - k)));

                gt[i].addLine(-2 * j, g[i][j] + j * j); 
                if (a[i] == b[i])
                ft[j].addLine(-2 * i, f[i][j] + i * i);
            }
        }

        rep (i, 0, n + 1) rep (j, 0, n + 1) db << (g[i][j] == 0x3f3f3f3f ? 0 : g[i][j]) << " \n"[j == n + 1];
            
        std::cout << f[n + 1][n + 1] << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 0, n + 1) std::cin >> a[i];
    rep (i, 0, n + 1) std::cin >> b[i];

    // Task1::solve();
    // Task2::solve();
    Solution::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("stone")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

    lookTime

	return 0;
}
