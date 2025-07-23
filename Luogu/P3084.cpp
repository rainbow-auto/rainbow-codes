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

constexpr int maxn = 200005;

int n, m;
int Lmx[maxn], Lmn[maxn];

int f[maxn];
int tr[maxn << 2];

inline void pushup(int now) {
	tr[now] = std::max(tr[now << 1], tr[now << 1 | 1]);
}

void mdf(int now, int l, int r, int pos, int v) {
	if (l == r) return tr[now] = v, void(0);
	int mid = (l + r) >> 1;
	if (pos <= mid) mdf(now << 1, l, mid, pos, v);
	else mdf(now << 1 | 1, mid + 1, r, pos, v);
	pushup(now);
}

int qry(int now, int l, int r, int L, int R) {
	if (L > R) return -0x3f3f3f3f;
	if (L <= l and r <= R) return tr[now];
	int mid = (l + r) >> 1;
	if (R <= mid) return qry(now << 1, l, mid, L, R);
	if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
	return std::max(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
}

void solve() {
	std::cin >> n >> m;

	std::memset(Lmn, 0x3f, sizeof Lmn);
	rep (i, 1, m) {
		int l, r; std::cin >> l >> r;
		Lmx[r] = std::max(Lmx[r], l);
		Lmn[r] = std::min(Lmn[r], l);
	}

	rep (i, 2, n) Lmx[i] = std::max(Lmx[i - 1], Lmx[i]);
	per (i, n - 1, 1) Lmn[i] = std::min(Lmn[i + 1], Lmn[i]);

	std::memset(tr, -0x3f, sizeof tr);

	mdf(1, 0, n, 0, 0);
	rep (i, 1, n + 1) {
		f[i] = qry(1, 0, n, Lmx[i - 1], Lmn[i] - 1) + (i != n + 1);
		if (f[i] >= 0) mdf(1, 0, n, i, f[i]);
	}

	if (f[n + 1] < 0) std::cout << "-1\n";
	else std::cout << f[n + 1] << "\n";
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
