#include <bits/stdc++.h>
// #pragma GCC optimize(3)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

inline i64 read() {
	i64 res = 0;
	char ch = getchar();
	while (not isdigit(ch)) ch = getchar();
	while (isdigit(ch)) res = res * 10ll + ch - '0', ch = getchar();
	return res;
}

const int maxn = 200005;

int n, q;
i64 a[maxn];
i64 W;

i64 pw2[maxn];

std::pair<int, i64> getbig(i64 sum) {
	if (W <= sum) return std::make_pair(0, 0ll);

	i64 cur = sum;
	int ans = 1;
	while (cur + sum * 2ll <= W) {
		cur += sum * 2ll;	
		sum *= 2ll;
		ans ++;
	}

	return std::make_pair(ans, cur);
}

struct Tree {
	struct Node {
		i64 tag;
		i64 sum;
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
	}

	inline void apply(int now, int l, int r, i64 val) {
		tr[now].sum += val * (r - l + 1);
		tr[now].tag += val;
	}	

	inline void pushDown(int now, int l, int r) {
		if (not tr[now].tag) return;
		int mid = (l + r) >> 1;
		apply(now << 1, l, mid, tr[now].tag);
		apply(now << 1 | 1, mid + 1, r, tr[now].tag);
		tr[now].tag = 0;
	}

	void build(int now, int l, int r) {
		if (l == r) return tr[now].sum = a[l], void(0);
		int mid = (l + r) >> 1;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
		pushUp(now);
	}

	void add(int now, int l, int r, int L, int R, i64 val) {
		if (L <= l and r <= R) return apply(now, l, r, val), void(0);
		pushDown(now, l, r);
		int mid = (l + r) >> 1;
		if (L <= mid) add(now << 1, l, mid, L, R, val);
		if (R > mid) add(now << 1 | 1, mid + 1, r, L, R, val);
		pushUp(now);
	}

	int qry(int now, int l, int r, i64 rst, i64 c) {
		if (l == r) return l;
		int mid = (l + r) >> 1;
		pushDown(now, l, r);
		if (rst - tr[now << 1].sum * c <= 0) return qry(now << 1, l, mid, rst, c);
		else return qry(now << 1 | 1, mid + 1, r, rst - tr[now << 1].sum * c, c);
	}
} tr;

void solve() {
	n = read();
	q = read();
	W = read();
	// std::cin >> n >> q >> W;
	// rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) a[i] = read();

	i64 sum = 0;
	rep (i, 1, n) sum += a[i];

	pw2[0] = 1;
	rep (i, 1, 63) pw2[i] = (pw2[i - 1] << 1);

	tr.build(1, 0, n);

	while (q--) {
		// int l, r; std::cin >> l >> r;
		// i64 val; std::cin >> val;

		int l = read(); int r = read();
		i64 val = read();

		tr.add(1, 0, n, l, r, val);
		sum += val * (r - l + 1);

		auto _ = getbig(sum);
		int big = _.first;
		i64 rst = W - _.second;

		int small = tr.qry(1, 0, n, rst, pw2[big]);

		i64 ans = n * big + small;

		std::cout << ans - 1 << "\n";
	}
}

bool MemED;
int main() {
	// fastread
	// lookMem	
	// TimeST = clock ();

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
