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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
// #define MultiTask lovely_fairytale

constexpr int maxn = 100005;

struct Number {
    int val;
    std::map<int, int> ps;
    void init(int x) {
        val = x;
        for (int d = 2; d * d <= val; d++) {
            while (x % d == 0) {
                x /= d;
                ps[d]++;
            }
        }
        if (x > 1) ps[x]++;
    }
};

int n, q;
Number a[maxn];

int gcd(int a, int b) {
    if (not b) return a;
    return gcd(b, a % b);
}

namespace Task0 {
    inline void solve() {
        while (q--) {
            int l, r; std::cin >> l >> r;
            // db << l << " " << r << "\n";

            int gv = a[l].val;
            rep (i, l + 1, r) gv = gcd(gv, a[i].val);
            // Number g;
            // g.init(gv);

            // db << gv << " : ";
            // for (auto p : g.ps) db << "(" << p.first << ", " << p.second << ") "; dbendl;

            int ans = 0;
            // std::set<int> vis;
            // rep (i, l, r) {
            //     dbg(a[i].val);
            //     for (auto p : a[i].ps) {
            //         if (not g.ps.count(p.first)) continue;
            //         db << "(" << p.first << ", " << p.second << ") ";
            //         if (p.second == g.ps[p.first]) vis.insert(p.first);
            //         if (p.second == g.ps[p.first]) db << "ok\n";
            //         else db << "\n";
            //     }

            //     db << "vis: "; for (auto p : vis) db << p << " "; dbendl
            //     dbg(g.ps.size());

            //     if (vis.size() == g.ps.size()) {
            //         db << "okk\n";
            //         ans++;
            //         vis.clear();
            //     }
            // }

            int gcur = 0;
            rep (i, l, r) {
                gcur = gcd(gcur, a[i].val);
                if (gcur == gv) {
                    ans++;
                    gcur = 0;
                }
            }

            std::cout << (r - l + 1) - ans << "\n";
        }
    }
}

namespace Task1 {
    int b[maxn];

    using info = std::pair<int, int>;

    inline info mrg(info a, info b) {
        if (a.first == b.first) return info {a.first, a.second + b.second};
        return std::min(a, b);
    }

    info tr[maxn];
    void build(int now, int l, int r) {
        if (l == r) {
            tr[now] = info {b[l], 1};
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
        rep (i, 1, n) b[i] = a[i].ps[2];
     
        build(1, 1, n);

        while (q--) {
            int l, r; std::cin >> l >> r;
            info x = qry(1, 1, n, l, r);

            std::cout << (r - l + 1) - x.second << "\n";
        }
    }
}

void solve() {
    std::cin >> n >> q;
    rep (i, 1, n) {
        int x; std::cin >> x;
        a[i].init(x);
    }

    bool flg1 = true;
    rep (i, 1, n) flg1 &= (a[i].ps.size() <= 1);

    if (flg1) return Task1::solve(), void(0);
    Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("gcd")

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
