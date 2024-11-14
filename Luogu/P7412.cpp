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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 100005;

int n, k;
i64 a[maxn];

void solve() {
	std::cin >> n >> k; k--;
	rep (i, 1, n) std::cin >> a[i];

	std::sort(a + 1, a + n + 1);

	i64 R = a[n] / 12 + 1;
	i64 ans = R * 12;

	std::priority_queue<int> q;
	a[0] = 0;

	rep (i, 1, n) db << a[i] << " "; dbendl;

	q.push(a[1] / 12 * 12);
	rep (i, 2, n) if (a[i] / 12 != a[i - 1] / 12) q.push((a[i] / 12) * 12 - (a[i - 1] / 12 + 1) * 12);

	while (k--) { ans -= q.top(); q.pop(); }

	std::cout << ans << "\n";
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
