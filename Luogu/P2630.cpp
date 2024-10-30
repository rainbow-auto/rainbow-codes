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

const int maxn = 5;

int a[maxn][maxn];
int b[maxn][maxn];

int cur[maxn][maxn];
int nxt[maxn][maxn];

std::string ops;
inline bool chk() {
	std::memcpy(cur, a, sizeof a);
	for (auto op : ops) {
		if (op == 'A') {
			rep (i, 1, 3) {
				rep (j, 1, 3) {
					nxt[j][3 - i + 1] = cur[i][j];
				}
			}
			std::memcpy(cur, nxt, sizeof nxt);
		} else if (op == 'B') {
			rep (i, 1, 3) {
				rep (j, 1, 3) {
					nxt[3 - j + 1][i] = cur[i][j];
				}
			}
			std::memcpy(cur, nxt, sizeof nxt);
		} else if (op == 'C') {
			rep (i, 1, 3) {
				std::swap(cur[i][1], cur[i][3]);
			}
		} else if (op == 'D') {
			rep (i, 1, 3) {
				std::swap(cur[1][i], cur[3][i]);
			}
		}
	}

	bool res = true;
	rep (i, 1, 3) rep (j, 1, 3) res &= (cur[i][j] == b[i][j]);

	return res;
}

std::string ans;

void dfs(int stp) {
	if (stp != 1 and chk()) {
		if (stp < ans.length()) {
			ans = ops;
		} else {
			ans = std::min(ans, ops);
		}
	}

	if (stp > 4) return;

	for (char c = 'A'; c <= 'D'; c++) {
		std::string old_ops = ops;
		ops += c;
		dfs(stp + 1);
		ops = old_ops;
	}
}

void solve() {
	rep (i, 1, 3) rep (j, 1, 3) std::cin >> a[i][j];
	rep (i, 1, 3) rep (j, 1, 3) std::cin >> b[i][j];

	// if (chk()) return std::cout << "AB\n", void(0);

	ans = "ZZZZZ";
	// std::cout << ans << "\n";
	dfs(1);
	if (ans == "ZZZZZ") std::cout << "Poland cannot into space!!!\n";
	else std::cout << ans << "\n";
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
