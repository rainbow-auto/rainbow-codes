#include <bits/stdc++.h>
// #pragma GCC optimize(2)

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

const int maxn = 50005;

int n, q;
int a[maxn];

struct Frac {
	i64 a, b;
	inline void norm() { 
		if (not a) return a = 0, b = 1, void(0); 
		i64 g = std::__gcd(a, b); a /= g; b /= g; 
	}

	inline void out() { norm(); std::cout << a << "/" << b << "\n"; }
} ans[maxn];

int bel[maxn], B;
inline void blocking() {
	B = (int) sqrt(n);
	rep (i, 1, q) bel[i] = i / B + 1;
}

struct Query {
	int l, r;
	int id;

	friend bool operator < (Query a, Query b) {
		if (bel[a.l] != bel[b.l]) return bel[a.l] < bel[b.l];
		return a.r < b.r;
	}
} qs[maxn];

i64 cnt[maxn];

void solve() {
	std::cin >> n >> q;

	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, q) {
		int l, r; std::cin >> l >> r;
		qs[i] = Query { l, r, i };
	}

	blocking();
	std::sort(qs + 1, qs + q + 1);

	int l = 1, r = 0;
	i64 cur = 0;
	auto add = [&](int x) -> void {
		cur -= cnt[a[x]] * cnt[a[x]];
		cnt[a[x]]++;
		cur += cnt[a[x]] * cnt[a[x]];
	};

	auto del = [&](int x) -> void {
		cur -= cnt[a[x]] * cnt[a[x]];
		cnt[a[x]]--;
		cur += cnt[a[x]] * cnt[a[x]];
	};

	rep (qid, 1, q) {
		auto qcur = qs[qid];
		while (r < qcur.r) add(++r);
		while (l > qcur.l) add(--l);
		while (r > qcur.r) del(r--);
		while (l < qcur.l) del(l++);

		i64 len = qcur.r - qcur.l + 1;
		ans[qcur.id].a = cur - len;
		ans[qcur.id].b = len * (len - 1);
	}

	rep (i, 1, q) ans[i].out();
}

bool MemED;
int main() {
	fastread
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
