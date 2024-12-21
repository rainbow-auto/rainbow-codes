#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale

const int maxn = 100005;

int n;
int s[2][maxn];
int t[2][maxn];

inline void input(int *a) {
	rep (i, 1, n) {
		char ch; std::cin >> ch;
		a[i] = ch - '0';
	}
}

namespace Solution {

	int L[2][maxn];
	int cnt[2][maxn][2];

	inline void init(int b) {
		std::memset(cnt[b], 0, sizeof(cnt[b]));
		rep (i, 1, n) {
			L[b][i] = i;
			if (t[b][i] and t[b][i - 1]) L[b][i] = L[b][i - 1];
			cnt[b][L[b][i]][s[b][i]]++;
		}
	}

	bool st[maxn], ed[maxn];

	inline void solve() {
		init(0), init(1);

		std::memset(st, 0, sizeof st); 
		std::memset(ed, 0, sizeof ed); 
		rep (i, 1, n) {
			if (L[0][i] == i or L[1][i] == i) {
				st[i] = true;
				if (i != 1) ed[i - 1] = true;
			}
		}
		ed[n] = true;

		int ans = 0;
		int j = 0;
		rep (i, 1, n) {
			if (st[i]) j = i;
			if (not ed[i]) continue;
			// [j, i] 是一个交
			int len = i - j + 1;

			int cnt0 = std::min(cnt[0][L[0][j]][0], cnt[1][L[1][j]][0]);

			int c0 = std::min(cnt0, len);
			ans += c0;
			len -= c0;
			cnt[0][L[0][j]][0] -= c0;
			cnt[1][L[1][j]][0] -= c0;
			
			int cnt1 = std::min(cnt[0][L[0][j]][1], cnt[1][L[1][j]][1]);
			
			int c1 = std::min(cnt1, len);
			ans += c1;
			len -= c1;
			cnt[0][L[0][j]][1] -= c1;
			cnt[1][L[1][j]][1] -= c1;
		}

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n;
	input(s[0]);
	input(s[1]);
	input(t[0]);
	input(t[1]);

	Solution::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

	file("edit");

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
