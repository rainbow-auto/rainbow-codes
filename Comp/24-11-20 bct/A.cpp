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

const int maxn = 105;

int n, m;
int s[maxn][maxn];

namespace Solution {
	int t[26];
	int cur[maxn], ok[maxn];

	inline void solve() {
		std::memset(s, 0, sizeof s);
		std::cin >> n >> m;
		rep (i, 1, n) {
			rep (j, 1, m) {
				char ch; std::cin >> ch;
				s[i][j] = ch - 'a';
			}
		}

		std::sort(s[1] + 1, s[1] + m + 1);
		// db << "s: "; rep (j, 1, m) db << char(s[1][j] + 'a'); dbendl;

		rep (i, 2, n) {
			// dbg(i);
			bool flg = false;
			rep (len, 0, m - 1) {
				// dbg(len);
				rep (j, 1, m) cur[j] = s[i][j];

				std::memset(t, 0, sizeof t);
				rep (j, 1, m) t[cur[j]]++;

				bool reach = true;
				rep (j, 1, len) {
					if (t[s[i - 1][j]] > 0) {
						t[s[i - 1][j]]--;
						cur[j] = s[i - 1][j];
					} else {
						reach = false;
						// db << "not reach\n";
						break;
					}
				}
				if (not reach) break;

				if (len != m) {
					bool found = false;
					rep (c, 0, 25) {
						if (not t[c]) continue;
						if (c > s[i - 1][len + 1]) {
							t[c]--; 
							cur[len + 1] = c;
							found = true; 
							break;
						}
					}
					// if (not found) db << "not found\n";
					if (not found) continue;
				}
				
				rep (j, len + 2, m) {
					rep (c, 0, 25) {
						if (not t[c]) continue;
						cur[j] = c;
						t[c]--;
						break;
					}
				}

				flg = true;
				rep (j, 1, m) ok[j] = cur[j];
				// rep (j, 1, m) db << char(ok[j] + 'a'); dbendl;
			}

			if (not flg) return std::cout << "No\n", void(0);
			rep (j, 1, m) s[i][j] = ok[j];

			// db << "s: "; rep (j, 1, m) db << char(s[i][j] + 'a'); dbendl;
		}

		std::cout << "Yes\n";
	}
}

void solve() {
	Solution::solve();
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
