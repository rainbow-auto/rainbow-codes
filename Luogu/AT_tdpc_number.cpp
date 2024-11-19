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

const int maxn = 10005;
const int maxd = 105;

const int mod = 1e9 + 7;

int n, d;
int a[maxn];

int mem[maxn][maxd][2];
int dfs(int now, int rst, bool lim) {
	if (now > n) return rst == 0;

	int &res = mem[now][rst][lim];
	if (~res) return res;
	res = 0;
	int mx = lim ? a[now] : 9;
	rep (i, 0, mx) {
		(res += dfs(now + 1, (rst + i) % d, lim and i == mx)) %= mod;
	}
	return res;
}

void solve() {
	std::cin >> d;
	
	std::string s; std::cin >> s; n = s.length();
	rep (i, 1, n) a[i] = s[i - 1] - '0';

	std::memset(mem, -1, sizeof mem);
	std::cout << (((dfs(1, 0, true) - 1) % mod) + mod) % mod << "\n";
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
