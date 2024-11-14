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

const int maxn = 3005;
const int mod = 1e9 + 7;

int n;
std::string s;

int f[maxn][maxn];
int sum[maxn];
inline int qry(int l, int r) { 
	if (l > r) return 0;
	return ((sum[r] - sum[l - 1]) % mod + mod) % mod; 
}

void solve() {
	std::cin >> n;
	std::cin >> s;
	s = " " + s;

	f[1][1] = 1; sum[1] = 1;
	rep (i, 2, n) {
		rep (j, 1, i) {
			if (s[i - 1] == '<') {
				f[i][j] = qry(1, j - 1);
			} else { // >
				f[i][j] = qry(j, i - 1);
			}
		} 

		rep (j, 1, n) sum[j] = (sum[j - 1] + f[i][j]) % mod;
	}

	std::cout << qry(1, n) << "\n";
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
