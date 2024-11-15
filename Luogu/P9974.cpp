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

const int maxn = 200005;

int n, m;
i64 a[maxn], b[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, m) std::cin >> b[i];

	rep (i, 1, m) {
		i64 ate = 0;
		rep (j, 1, n) {
			if (a[j] >= ate) {
				i64 cur = std::min(a[j], b[i]);
				a[j] += cur - ate;
				ate = cur;
			}
			if (ate >= b[i]) break;
		}
	}

	rep (i, 1, n) std::cout << a[i] << "\n";
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
