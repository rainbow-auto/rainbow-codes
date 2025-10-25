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
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 105;

int n, k;
std::string s;

std::set<std::string> ss[maxn];

inline bool chk(int l1, int r1, int l2, int r2) {
	rep (i, l1, r1) if (s[i] != s[i - l1 + l2]) return false;
	return true;
} 

void solve() {
	std::cin >> n >> k;
	std::cin >> s; s = " " + s;

	rep (i, 1, n - k + 1) {
		int res = 0;
		rep (j, 1, n - k + 1) {
			if (chk(i, i + k - 1, j, j + k - 1)) res++;
		}

		std::string t = "";
		rep (j, i, i + k - 1) t += s[j];
		ss[res].insert(t);
	}

	per (res, n, 1) {
		if (ss[res].size()) {
			std::cout << res << "\n";
			for (auto t : ss[res]) std::cout << t << " ";
			std::cout << "\n";
			break;
		}
	}
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
