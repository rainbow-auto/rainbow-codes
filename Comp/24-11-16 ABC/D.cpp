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

i64 n;

i64 get(i64 pos) {
	return (pos - 1) % n + 1;
}

char chg(char c) {
	if (c >= 'a' and c <= 'z') return c - 'a' + 'A';
	else return c - 'A' + 'a';
}

bool c(i64 i) {
	if (i == 1) return 0;
	i64 k = 0;
	while (i > (1ll << k)) k++;
	return c(i - (1ll << (k - 1))) ^ 1;
}

void solve() {
	std::string s; std::cin >> s;
	n = s.length();
	s = " " + s;

	int q; std::cin >> q;
	while (q--) {
		i64 x; std::cin >> x;

		char t = s[get(x)];
		// dbg(x);
		i64 r = (x - 1) / n + 1;
		// dbg(r);
		// int k = 0;
		// while ((1ll << k) < r) k++;
		// dbg(k);
		// dbg(c(k, r));
		if (c(r)) std::cout << chg(t) << " ";
		else std::cout << t << " ";

		// dbendl;
	}
	std::cout << "\n";
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
