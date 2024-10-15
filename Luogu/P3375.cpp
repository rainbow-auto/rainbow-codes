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

const int maxn = 2000005;

int n;
std::string s;

int pi[maxn];
inline void get_pi() {
	pi[1] = 0;
	rep (i, 2, (int) s.length() - 1) {
		int j = pi[i - 1];
		while (j and s[j + 1] != s[i]) j = pi[j];
		if (s[j + 1] == s[i]) j++;
		pi[i] = j; 
	}
}

void solve() {
	std::string t; std::cin >> t;
	std::cin >> s; n = s.length(); s = " " + s + "#" + t;

	get_pi();

	rep (i, n + 2, (int) s.length() - 1) {
		if (pi[i] == n) std::cout << (i - (n + 1)) - n + 1 << "\n";
	}

	rep (i, 1, n) std::cout << pi[i] << " \n"[i == n];
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
