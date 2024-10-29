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

const int maxn = 2005;

int n, m, k, l, D;
int a[maxn], b[maxn];

void solve() {
	std::cin >> n >> m >> k >> l >> D;

	rep (i, 1, D) {
		int x, y, p, q; std::cin >> x >> y >> p >> q;
		
		if (x - p) {
			a[std::min(x, p)]++;
		} else {
			b[std::min(y, q)]++;
		}
	}

	std::vector<std::pair<int, int>> va;
	rep (i, 1, n) va.push_back(std::make_pair(a[i], (int) i));

	std::sort(va.begin(), va.end()); std::reverse(va.begin(), va.end());
	std::vector<int> ans_a;
	rep (i, 0, k - 1) ans_a.push_back(va[i].second);
	std::sort(ans_a.begin(), ans_a.end());
	rep (i, 0, k - 1) std::cout << ans_a[i] << " \n"[i == k - 1];

	///////////////////////////////////////////////////////////////////

	std::vector<std::pair<int, int>> vb;
	rep (i, 1, m) vb.push_back(std::make_pair(b[i], (int) i));
	
	std::sort(vb.begin(), vb.end()); std::reverse(vb.begin(), vb.end());
	std::vector<int> ans_b;
	rep (i, 0, l - 1) ans_b.push_back(vb[i].second);
	std::sort(ans_b.begin(), ans_b.end());
	rep (i, 0, l - 1) std::cout << ans_b[i] << " \n"[i == l - 1];
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
