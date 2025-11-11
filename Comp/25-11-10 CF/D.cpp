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

constexpr int maxn = 3000005;

int n, q;
int L[maxn], R[maxn];

void solveL() {
	int ans = 0;
	int r = 0;
	rep (l, 1, (n >> 1) + 1) {
		if (R[l] > r) {
			r = R[l];
			std::cout << "? " << l << " " << r << "\n";
			std::cout.flush();
			int res; std::cin >> res;
			ans = std::max(ans, res);
		}
	}
	
	std::cout << "! " << ans << "\n"; std::cout.flush();
}

void solveR() {
	int ans = 0;
	int l = 0x3f3f3f3f;
	per (r, n, (n >> 1)) {
		if (L[r] < l) {
			l = L[r];
			std::cout << "? " << l << " " << r << "\n";
			std::cout.flush();
			int res; std::cin >> res;
			ans = std::max(ans, res);
		}
	}
	
	std::cout << "! " << ans << "\n"; std::cout.flush();
}

void solve() {
	std::cin >> n >> q;

	rep (i, 1, n) L[i] = 0x3f3f3f3f;
	rep (i, 1, n) R[i] = 0;
	
	rep (t, 1, q) {
	 	int l, r; std::cin >> l >> r;
		R[l] = std::max(R[l], r);
		L[r] = std::min(L[r], l);
	}

	std::cout << "? " << 1 << " " << (n >> 1) << "\n";
	std::cout.flush();
	int res; std::cin >> res;
	if (not res) solveR();
	else solveL();
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
