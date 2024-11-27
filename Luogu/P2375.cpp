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

const int maxn = 1000005;
const int mod = 1e9 + 7;

int n;
std::string s;

int pi[maxn];
inline void get_pi() {
	pi[1] = 0;
	rep (i, 2, n) {
		int j = pi[i - 1];
		while (j and (s[j + 1] != s[i])) j = pi[j];
		pi[i] = j + bool(s[j + 1] == s[i]);
	}
}

int f[maxn];
int sum[maxn];

void solve() {
	std::cin >> s;
	n = s.length();
	s = " " + s;

	get_pi();

	f[1] = 0;
	rep (i, 2, n) {
		int j = f[i - 1];
		while (j and (s[j + 1] != s[i])) j = pi[j];
		j += (s[j + 1] == s[i]);
		while (j > (i >> 1)) j = pi[j];
		f[i] = j;
	}

	rep (i, 1, n) sum[i] = sum[pi[i]] + 1; 

	i64 ans = 1;
	rep (i, 1, n) {
		i64 cur = sum[f[i]];
		(ans *= 1ll * (cur + 1) % mod) %= mod;
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
