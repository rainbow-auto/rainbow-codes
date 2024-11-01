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

const int maxn = 2000005;

int n, k, q;
int a[maxn];

i64 sum;

std::bitset<maxn> s;

i64 f_pre[maxn];
inline void init_pre() {
	std::deque<int> q; q.push_back(0);
	f_pre[0] = 0;
	rep (i, 1, n + 1) {
		while (not q.empty() and q.front() < i - k) q.pop_front();
		f_pre[i] = f_pre[q.front()] + i64{!s[i]} * a[i];
		while (not q.empty() and f_pre[q.back()] > f_pre[i]) q.pop_back();
		q.push_back(i);
	}
}

i64 f_suf[maxn];
inline void init_suf() {
	std::deque<int> q; q.push_back(n + 1);
	f_suf[n + 1] = 0;
	per (i, n, 0) {
		while (not q.empty() and q.front() > i + k) q.pop_front();
		f_suf[i] = f_suf[q.front()] + i64{!s[i]} * a[i];
		while (not q.empty() and f_suf[q.back()] > f_suf[i]) q.pop_back();
		q.push_back(i);
	}
}

inline i64 qry(int p, i64 v) {
	i64 res; std::memset(&res, 0x3f, sizeof res);
	std::deque<int> q;

	i64 pre_mn; std::memset(&pre_mn, 0x3f, sizeof pre_mn);
	rep (i, std::max(0, p - k), p - 1) {
		pre_mn = std::min(pre_mn, f_pre[i]);

		while (not q.empty() and f_pre[q.back()] > f_pre[i]) q.pop_back();
		q.push_back(i); 
	}

	i64 suf_mn; std::memset(&suf_mn, 0x3f, sizeof suf_mn);
	rep (i, p + 1, std::min(p + k, n + 1)) {
		suf_mn = std::min(suf_mn, f_suf[i]);

		while (not q.empty() and q.front() < i - k) q.pop_front();
		if (q.empty()) continue;
		res = std::min(res, f_pre[q.front()] + f_suf[i]);
	}

	res = std::min(res, pre_mn + i64{!s[p]} * v + suf_mn);

	return res;
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n) {
		char ch; std::cin >> ch;
		if (ch - '0') s.set(i);
	}

	sum = 0;
	rep (i, 1, n) sum += 1ll * s[i] * a[i];

	init_pre();
	init_suf();

	std::cin >> q;
	while (q--) {
		int p; std::cin >> p;
		i64 v; std::cin >> v;
		std::cout << sum + i64{s[p]} * (-a[p] + v) + qry(p, v) << "\n";
	}	
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::freopen("cablecar.in", "r", stdin);
	std::freopen("cablecar.out", "w", stdout);

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
