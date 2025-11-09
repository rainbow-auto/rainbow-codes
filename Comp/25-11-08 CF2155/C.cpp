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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;
constexpr int mod = 676767677;

int n;
int a[maxn];
int b[maxn];

void solve() {
	std::cin >> n;

	rep (i, 1, n) {
		std::cin >> a[i];
		a[i]--;
		b[i] = -1;
	}	

	bool flg = true;

	bool all = true;
	rep (i, 1, n - 1) {
		if (a[i] == a[i + 1]) continue;

		all = false;
		if (a[i] + 1 == a[i + 1]) {
			if (~b[i] and b[i] != 1) {
				flg = false;
				break;
			} 
			b[i] = 1;
			b[i + 1] = 1;
			continue;
		}

		if (a[i] - 1 == a[i + 1]) {
			if (~b[i] and b[i] != 0) {
				flg = false;
				break;
			}
			b[i] = 0;
			b[i + 1] = 0;
			continue;
		}

		flg = false; break;
	}

	if (not flg) return std::cout << "0\n", void(0);

	if (all) {
		if (n & 1) {
			if (a[1] == ((n - 1) >> 1)) std::cout << "2\n";
			else std::cout << "0\n";
		} else {
			if (a[1] == ((n - 1) >> 1) or a[1] == ((n - 1) >> 1) + 1) std::cout << "1\n";
			else std::cout << "0\n";
		}
		return;
	}

	int fst = 0;
	rep (i, 1, n) if (~b[i]) {
		fst = i; break;
	}

	per (i, fst - 1, 1) b[i] = (b[i + 1] ^ 1);
	
	rep (i, fst + 1, n) {
		if (a[i] == a[i - 1]) {
			if (~b[i] and (b[i] != (b[i - 1] ^ 1))) {
				flg = false;
				break;
			}
			b[i] = (b[i - 1] ^ 1);
		}
	}

	if (not flg) return std::cout << "0\n", void(0);

	std::array<int, 2> cnt = {};
	rep (i, 1, n - 1) cnt[b[i]]++;
	if (cnt[1] != a[n]) return std::cout << "0\n", void(0);
	cnt = {};
	rep (i, 2, n) cnt[b[i]]++;
	if (cnt[0] != a[1]) return std::cout << "0\n", void(0);

	std::cout << "1\n";
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
