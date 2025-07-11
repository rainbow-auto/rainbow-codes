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

int n;
std::string org;

inline int calc(char c) {
	std::string s = org;

	bool finish = true;
	rep (j, 0, s.size() - 1) finish &= (s[j] == c);
	if (finish) return 0;

	int tot = s.size();
	rep (i, 1, tot - 1) {
		std::string t = "";
		rep (j, 0, s.size() - 2) {
			if (s[j] == c or s[j + 1] == c) t = t + c;
			else t = t + s[j];
		}
		s = t;

		bool finish = true;
		rep (j, 0, s.size() - 1) finish &= (s[j] == c);
		if (finish) return i;
	}

	return 0x3f3f3f3f;
}

void solve() {
	std::cin >> org;

	int ans = 0x3f3f3f3f;

	for (char c = 'a'; c <= 'z'; c++) {
		ans = std::min(ans, calc(c));
	}

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
