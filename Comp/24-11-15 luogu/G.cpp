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

int a[10];
int pw10[9];
inline bool chk(int x) {
	rep (i, 1, 6) a[i] = (x / pw10[i - 1]) % 10;
	rep (i, 1, 6) if (a[i] == 0) return false;

	rep (i, 1, 6) {
		rep (j, i + 1, 6) {
			rep (k, j + 1, 6) {
				if (a[i] + a[j] > a[k] and a[i] + a[k] > a[j] and a[j] + a[k] > a[i]) {
					std::vector<int> w;
					rep (id, 1, 6) if (id != i and id != j and id != k) w.push_back(a[id]);
					if (w[0] + w[1] > w[2] and w[0] + w[2] > w[1] and w[1] + w[2] > w[0]) return true;
				}
			}
		}
	} 	

	return false;
}

void solve() {
	pw10[0] = 1;
	rep (i, 1, 10) pw10[i] = pw10[i - 1] * 10ll;

	int l, r; std::cin >> l >> r;
	int ans = 0;
	rep (i, l, r) ans += chk(i);
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
