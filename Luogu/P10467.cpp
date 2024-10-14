#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;

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

const u64 B = 13331;

int n;

std::set<u64> s;
inline u64 H(const std::array<int, 6>& a) {
	u64 res = 0;
	for (auto x : a) (res *= B) += x;
	return res;
}

bool chk(const std::array<int, 6>& a) {
	rep (i, 0, 5) {
		std::array<int, 6> b;
		rep (j, 0, 5) b[(j + i) % 6] = a[j]; 
		if (s.count(H(b))) return true;
	}

	rep (i, 0, 5) {
		std::array<int, 6> b;
		rep (j, 0, 5) b[(i - j + 6) % 6] = a[j];
		if (s.count(H(b))) return true;
	}

	return false;
}

void solve() {
	std::cin >> n;

	bool flg = false;
	rep (_, 1, n) {
		std::array<int, 6> a; a.fill(0);
		for (auto& x : a) std::cin >> x;

		u64 h = H(a);
		if (chk(a)) flg |= 1;
		s.insert(h);
	}

	if (flg) std::cout << "Twin snowflakes found.";
	else std::cout << "No two snowflakes are alike.";
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
