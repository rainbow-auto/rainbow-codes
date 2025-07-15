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

constexpr int maxn = 30005;
constexpr int maxq = 300005;
constexpr i64 mod = 1e9 + 7;

int n, m, q;
int w[maxn];

namespace Task1 {
    constexpr int maxv = 100;
    using info = std::array<int, maxv + 5>;
    inline info mrg(info a, info b) {
        info c;
        c.fill(0);
        rep (i, 0, m) {
            rep (j, 0, i) (c[i] += 1ll * a[j] * b[i - j] % mod) %= mod;
        }
        c[0] = 1;
        return c;
    }

    info tr[maxn << 2];
    void build(int now, int l, int r) {
        if (l == r) {
            tr[now][0] = 1;
            tr[now][w[l]] = 1;
            return;
        }

        int mid = (l + r) >> 1;
        build(now << 1, l, mid);
        build(now << 1 | 1, mid + 1, r);
        tr[now] = mrg(tr[now << 1], tr[now << 1 | 1]);
    }

    info qry(int now, int l, int r, int L, int R) {
        if (L <= l and r <= R) return tr[now];
        int mid = (l + r) >> 1;
        if (R <= mid) return qry(now << 1, l, mid, L, R);
        if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
        return mrg(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
    }

    inline void solve() {
        build(1, 1, n);

        while (q--) {
            int l, r, x;
            std::cin >> l >> r >> x;
            info rg = qry(1, 1, n, l, r);
            std::cout << rg[x] << "\n";
        }
    }
}

namespace Task2 {
    constexpr int maxv = 500;
    using info = std::array<int, maxv + 5>;
    
    info f;
    inline void add(int x) {
        x = w[x];
        // db << "add " << x << "\n";
        per (i, m - x, 0) {
            (f[i + x] += f[i]) %= mod;
            // (f[i + x] += f[i]) >= mod ? f[i + x] -= mod : 0;
        }
        f[0] = 1;
    }

    inline void del(int x) {
        x = w[x];
        // db << "del " << x << "\n";
        rep (i, 0, m - x) {
            // (f[i + x] -= f[i]) <= 0 ? f[i + x] += mod : 0;
            (((f[i + x] -= f[i]) %= mod) += mod) %= mod;
        }
        f[0] = 1;
    }

    int bel[maxn];
    int ans[maxq];
    struct Query {
        int l, r, x;
        int i;

        friend bool operator < (Query x, Query y) {
            if (bel[x.l] != bel[y.l]) return bel[x.l] < bel[y.l];
            else if (bel[x.l] & 1) return x.r < y.r;
            else return x.r > y.r;
        }
    };

    std::vector<Query> qs;

    inline void solve() {
        int B = sqrt(n);
        rep (i, 1, n) bel[i] = (i - 1) / B + 1;

        rep (t, 1, q) {
            int l, r, x; std::cin >> l >> r >> x;
            qs.push_back(Query{l, r, x, t});
        }

        std::sort(qs.begin(), qs.end());
        
        f.fill(0); f[0] = 1;

        int l = 1, r = 0;
        for (auto qc : qs) {
            // db << qc.l << " " << qc.r << " " << qc.x << "\n";

            while (l > qc.l) add(--l);
            while (r < qc.r) add(++r);
            while (l < qc.l) del(l++);
            while (r > qc.r) del(r--);

            ans[qc.i] = f[qc.x];
        }

        rep (t, 1, q) std::cout << ans[t] << "\n";
    }
}

void solve() {
    std::cin >> n >> m >> q;
    rep (i, 1, n) std::cin >> w[i];

    // Task1::solve();
    Task2::solve();
}

bool MemED;
int main() {
	fastread
	lookMem	

    file("seg")

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
