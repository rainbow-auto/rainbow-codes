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

constexpr int maxn = 300005;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int n, q;

i64 a[maxn];

struct Node {
    i64 cnt;
    i64 mn;
    i64 tag;
} tr[maxn << 2];

inline void apply(int now, i64 x) {
    tr[now].mn -= x;
    tr[now].tag += x;
}

inline void pushup(int now) {
    tr[now].mn = std::min(tr[now << 1].mn, tr[now << 1 | 1].mn);
    tr[now].cnt = tr[now << 1].cnt + tr[now << 1 | 1].cnt;
}

inline void pushdown(int now) {
    if (not tr[now].tag) return;
    apply(now << 1, tr[now].tag);
    apply(now << 1 | 1, tr[now].tag);
    tr[now].tag = 0;
}

void build(int now, int l, int r) {
    if (l == r) return tr[now] = { 1, a[l], 0 }, void(0);
    int mid = (l + r) >> 1;
    build(now << 1, l, mid);
    build(now << 1 | 1, mid + 1, r);
    pushup(now);
}

i64 qry(int now, int l, int r, int L, int R, i64 x) {
    if (not tr[now].cnt) return 0;
    if (L <= l and r <= R and tr[now].mn > x) {
        apply(now, x);
        return x * tr[now].cnt;
    }
    if (l == r) {
        i64 mn = tr[now].mn;
        tr[now].mn = inf;
        tr[now].cnt = 0;
        return mn;
    }

    int mid = (l + r) >> 1;
    pushdown(now);
    i64 res = 0;
    if (L <= mid) res += qry(now << 1, l, mid, L, R, x);
    if (R > mid) res += qry(now << 1 | 1, mid + 1, r, L, R, x);
    pushup(now);
    return res;
}

void solve() {
	std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];
    build(1, 1, n);

    std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;
        i64 x; std::cin >> x;
        
        std::cout << qry(1, 1, n, l, r, x) << "\n";
    }

	lookTime
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