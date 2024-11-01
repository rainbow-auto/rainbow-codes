#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

const int maxn = 1000005;

int n;
u64 a[maxn];
u64 b[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) std::cin >> b[i];

	std::sort(a + 1, a + n + 1);
	a[n + 1] = 1e18;

	std::vector<u64> c;
	std::stack<u64> s;
	rep (i, 2, n + 1) {
		if (a[i] == a[i - 1]) s.push(a[i]);
		else {
			int cur = a[i - 1];
			while (not s.empty() and cur + 1 < a[i]) {
				cur++;
				c.push_back(cur - s.top()); s.pop();
			}
		}
	}

	std::sort(c.begin(), c.end()); std::reverse(c.begin(), c.end());
	std::sort(b + 1, b + n + 1);
	int pos = 0;

	u64 ans = 0;
	for (auto x : c) ans += x * b[++pos];
	std::cout << ans << "\n";
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
