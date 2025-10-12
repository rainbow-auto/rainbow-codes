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

constexpr int maxn = 20005;
constexpr int maxq = 200005;

int n, m, q;
int w[maxn], v[maxn];

constexpr int maxv = 505;

using info = std::array<i64, maxv + 5>;

inline info add(info f, int x, i64 v) {
    info g = f;
    per (i, m - x, 0) g[i + x] = std::max(g[i + x], f[i] + v);
    return g;
}

inline void init(info &f) {
    f.fill(0);
}

i64 ans[maxq];
struct Query {
    int l, r, x;
    int i;
};

info f[maxn], g[maxn];
void calc(int l, int r, const std::vector<Query> &qs) {
    if (qs.empty()) return;

    if (l == r) {
        for (auto q : qs) {
            if (q.x >= w[l]) ans[q.i] = v[l];
            else ans[q.i] = 0;
        }
        return;
    }

    int mid = (l + r) >> 1;

    std::vector<Query> lqs, rqs, mqs;
    for (auto q : qs) {
        if (q.r <= mid) lqs.push_back(q);
        else if (q.l > mid) rqs.push_back(q);
        else mqs.push_back(q);
    }

    init(f[mid + 1]);
    per (i, mid, l) f[i] = add(f[i + 1], w[i], v[i]);

    init(g[mid]);
    rep (i, mid + 1, r) g[i] = add(g[i - 1], w[i], v[i]);

    for (auto q : mqs) {
        ans[q.i] = 0;
        rep (k, 0, q.x) {
            ans[q.i] = std::max(ans[q.i], f[q.l][k] + g[q.r][q.x - k]);
        }
    }

    calc(l, mid, lqs);
    calc(mid + 1, r, rqs);
}

void solve() {
    std::cin >> n;

    m = 500;
    rep (i, 1, n) std::cin >> w[i] >> v[i];
    
    std::cin >> q;
    
    // while (q--) {
    //     int l, r, x; std::cin >> l >> r >> x;
    
    //     info f; init(f);
    //     rep (i, l, r) {
    //         f = add(f, w[i], v[i]);
    //     }
    
    //     std::cout << f[x] << "\n";
    // }

    std::vector<Query> qs;
    rep (t, 1, q) {
        int l, r, x; std::cin >> l >> r >> x;
        qs.push_back(Query{l, r, x, t});
    }
    
    calc(1, n, qs);
    
    rep (t, 1, q) std::cout << ans[t] << "\n";
}

bool MemED;
int main() {
	fastread
	lookMem	

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
