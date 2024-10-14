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

const u64 B = 13331;
const int maxn = 1000005;

int n;
std::string s;
u64 h[maxn];

u64 pw[maxn];
void init() {
	h[0] = 0;
	rep (i, 1, n) h[i] = h[i - 1] * B + s[i] - 'a';
	
	pw[0] = 1;
	rep (i, 1, n) pw[i] = pw[i - 1] * B;
}

inline u64 calc(int l, int r) {
	return h[r] - h[l - 1] * pw[r - l + 1];
}

void solve() {
	std::cin >> s; n = s.length(); s = " " + s;

	init();

	int q; std::cin >> q;
	while (q--) {
		int l1, r1; std::cin >> l1 >> r1;
		int l2, r2; std::cin >> l2 >> r2;

		if (calc(l1, r1) == calc(l2, r2)) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
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
