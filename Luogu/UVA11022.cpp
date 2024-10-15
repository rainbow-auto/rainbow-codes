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

const int maxn = 85;

int n;

inline std::vector<int> get_pi(const std::string& s) {
	std::vector<int> pi(s.length());
	rep (i, 2, s.length() - 1) {
		int j = pi[i - 1];
		while (j and s[j + 1] != s[i]) j = pi[j];
		if (s[j + 1] == s[i]) j ++;
		pi[i] = j;
	}
	return pi;
}

std::string s;

inline int calc(int l, int r) {
	int len = r - l + 1;
	auto ss = " " + s.substr(l, len);
	auto pi = get_pi(ss);

	if (len % (len - pi[len])) return 0;
	return len - pi[len];
}

int f[maxn][maxn];

void RainbowAutomaton() {
	n = s.length();
	s = " " + s;

	std::memset(f, 0x3f, sizeof f);
	rep (i, 1, n) f[i][i] = 1;

	rep (len, 2, n) {
		rep (l, 1, n - len + 1) {
			int r = l + len - 1;

			int T = calc(l, r);
			if (T) f[l][r] = std::min(f[l][r], f[l][l + T - 1]); // 只需要压缩一个长度为 T 的串即可

			rep (k, l, r) {
				f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r]);
			}
		}
	}

	std::cout << f[1][n] << "\n";	
}

void solve() {
	while (true) {
		std::cin >> s;
		if (s == "*") break;
		RainbowAutomaton();
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
