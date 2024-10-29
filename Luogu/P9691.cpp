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
#define MultiTask lovely_fairytale

const int maxn = 500005;

int n, m;
i64 a[maxn];

int pre[maxn];
i64 f[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i]; a[n + 1] = 0;
	rep (i, 1, n + 1) pre[i] = 0;

	std::cin >> m;
	rep (i, 1, m) {
		int l, r; std::cin >> l >> r;
		pre[r + 1] = std::max(pre[r + 1], l);
	}

	rep (i, 2, n + 1) pre[i] = std::max(pre[i], pre[i - 1]);

	std::deque<int> q; q.push_back(0);
	rep (i, 1, n + 1) {
		while (not q.empty() and q.front() < pre[i]) q.pop_front();
		f[i] = f[q.front()] + a[i];
		while (not q.empty() and f[q.back()] >= f[i]) q.pop_back();
		q.push_back(i);
	}

	std::cout << f[n + 1] << "\n";
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
