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

constexpr int maxn = 500005;

int n, q;
int a[maxn];

struct Tree {
    struct Node {
        bool cov;
        bool col;
    
        int mx, mn;
        std::array<int, 2> sum;

        int tg; // subtract
    } tr[maxn << 2];
    
    inline void pushUp(int now) {
        tr[now].sum[0] = tr[now << 1].sum[0] + tr[now << 1 | 1].sum[0];
        tr[now].sum[1] = tr[now << 1].sum[1] + tr[now << 1 | 1].sum[1];
        tr[now].mx = std::max(tr[now << 1].mx, tr[now << 1 | 1].mx);
        tr[now].mn = std::min(tr[now << 1].mn, tr[now << 1 | 1].mn);
        tr[now].cov = (tr[now << 1].cov and tr[now << 1 | 1].cov and tr[now << 1].col == tr[now << 1 | 1].col);
        if (tr[now].cov) tr[now].col = (tr[now].mn & 1);
    }

    inline void apply(int now, int v) {
        if (v & 1) std::swap(tr[now].sum[0], tr[now].sum[1]);
        tr[now].col ^= (v & 1);
        tr[now].mx -= v;
        tr[now].mn -= v;
        tr[now].tg += v;
    }

    inline void pushDown(int now) {
        if (not tr[now].tg) return;
        apply(now << 1, tr[now].tg);
        apply(now << 1 | 1, tr[now].tg);
        tr[now].tg = 0;
    }

    void build(int now, int l, int r) {
        if (l == r) return tr[now] = Node { true, bool(a[l] & 1), a[l], a[l], {(a[l] & 1) ^ 1, (a[l] & 1)} }, void(0);
        int mid = (l + r) >> 1;
        build(now << 1, l, mid);
        build(now << 1 | 1, mid + 1, r);
        pushUp(now);
    }

    void mdf(int now, int l, int r, int L, int R, int op) {
        if (L <= l and r <= R) if (tr[now].cov) {
            if (op == tr[now].col) apply(now, 1);
            return;
        }

        pushDown(now);
        int mid = (l + r) >> 1;
        if (L <= mid) mdf(now << 1, l, mid, L, R, op);
        if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, op);
        pushUp(now);
    }

    int qry(int now, int l, int r, int L, int R, int b) {
        if (L > R) return 0;
        if (L <= l and r <= R) return tr[now].sum[b];

        pushDown(now);
        int mid = (l + r) >> 1;
        if (R <= mid) return qry(now << 1, l, mid, L, R, b);
        if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R, b);
        return qry(now << 1, l, mid, L, R, b) + qry(now << 1 | 1, mid + 1, r, L, R, b);
    }

    int qry(int now, int l, int r, int pos) {
        if (l == r) return tr[now].mn;
        pushDown(now);
        int mid = (l + r) >> 1;
        if (pos <= mid) return qry(now << 1, l, mid, pos);
        else return qry(now << 1 | 1, mid + 1, r, pos);
    }

    int getL(int now, int l, int r, int v) {
        if (l == r) return l;
        pushDown(now);
        int mid = (l + r) >> 1; 
        if (tr[now << 1].mx >= v) return getL(now << 1, l, mid, v);
        else return getL(now << 1 | 1, mid + 1, r, v);
    }

    int getR(int now, int l, int r, int v) {
        if (l == r) return l;
        pushDown(now);
        int mid = (l + r) >> 1;
        if (tr[now << 1 | 1].mn <= v) return getR(now << 1 | 1, mid + 1, r, v);
        else return getR(now << 1, l, mid, v);
    }
} tr;

void solve() {
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> a[i];
    
    std::sort(a + 1, a + n + 1);

    tr.build(1, 1, n);
    
    i64 ans = 0;
    rep (i, 1, n) ans += a[i];

    // auto display = [&]() -> void {
    //     rep (i, 1, n) db << tr.qry(1, 1, n, i) << " "; dbendl;
    // };

    while (q--) {
        int l, r; std::cin >> l >> r;
        int L = tr.getL(1, 1, n, l);
        int R = tr.getR(1, 1, n, r);

        // dbg(L);
        // dbg(R);

        bool op; std::cin >> op;

        // db << l << " " << r << " " << op << "\n";

        ans -= tr.qry(1, 1, n, L, R, op);
        std::cout << ans << "\n";
        // db << ans << "\n";

        tr.mdf(1, 1, n, L, R, op);

        // display();

        // db << "--------\n";
    }
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
