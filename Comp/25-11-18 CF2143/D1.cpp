#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 2005;
constexpr int inf = 0x3f3f3f3f;
constexpr int mod = int(1e9) + 7;

int n;
int a[maxn];

struct Tree {
    int tr[maxn];
    inline int lowbit(int x) {
        return x & (-x);
    }

    inline int qry(int pos) {
        pos++;
        int res = 0;
        for (int i = pos; i; i -= lowbit(i)) (res += tr[i]) %= mod;
        return res;
    }

    inline void mdf(int pos, int v) {
        pos++;
        for (int i = pos; i <= n + 1; i += lowbit(i)) (tr[i] += v) %= mod;
    }

    inline int qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }

    inline void clr() {
        rep (i, 0, n + 1) tr[i] = 0;
    }
} row[maxn], col[maxn];

inline void clr() {
    rep (i, 0, n) row[i].clr();
    rep (i, 0, n) col[i].clr();
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> a[i];
	}	

    col[0].mdf(0, 1);
    row[0].mdf(0, 1);
    rep (i, 1, n) {
        std::vector<std::pair<std::pair<int, int>, int>> adds;
        // rep (e1, 0, a[i]) rep (e2, 0, e1) {
        rep (e2, 0, a[i]) {
            adds.push_back({{a[i], e2}, col[e2].qry(e2, a[i])});
        }
        //rep (e1, e2, a[i]) {
            // (f[i & 1][a[i]][e2] += f[(i - 1) & 1][e1][e2]) %= mod;
        // }

        // e1 >= e2
        rep (e1, a[i] + 1, n) { // rep (e2, 0, a[i]) {
            adds.push_back({{e1, a[i]}, row[e1].qry(0, a[i])});
            // (f[i & 1][e1][a[i]] += f[(i - 1) & 1][e1][e2]) %= mod;
        }

        for (auto [pos, v] : adds) {
            row[pos.first].mdf(pos.second, v);
            col[pos.second].mdf(pos.first, v);
        }
    }


	int ans = 0;
	rep (e1, 0, n) (ans += row[e1].qry(0, n)) %= mod;
	std::cout << ans << "\n";

	clr();
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
