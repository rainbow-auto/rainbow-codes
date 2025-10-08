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

constexpr int maxn = 1000005;

int n, m;
std::string s, t;

int f[maxn];

int pi[maxn];
inline void get_pi() {
	pi[1] = 0; 
	rep (i, 2, n) {
		int j = pi[i - 1];
		while (j and s[j + 1] != s[i]) j = pi[j];
		if (s[j + 1] == s[i]) j++;
		pi[i] = j;
	}
}

void solve() {
	std::cin >> t; m = t.size(); t = " " + t;
	std::cin >> s; n = s.size(); s = " " + s;

	get_pi();

	std::stack<int> stk;
	stk.push(0);

	std::bitset<maxn> rmv;
	rep (i, 1, m) {
		stk.push(i);

		f[i] = f[i - 1];
		while (f[i] and s[f[i] + 1] != t[i]) f[i] = pi[f[i]];
		if (s[f[i] + 1] == t[i]) f[i]++;

		if (f[i] == n) {
			rep (t, 1, n) {
				rmv[stk.top()] = true;
				stk.pop();
			}
			f[i] = f[stk.top()];
		}
	}

	rep (i, 1, m) if (not rmv[i]) std::cout << t[i]; std::cout << "\n";
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
