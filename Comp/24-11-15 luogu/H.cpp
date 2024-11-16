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

const int maxn = 1005;

int n, m;
char ch[maxn][maxn];
int a[maxn][maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> ch[i][j];
		}
	}

	rep (i, 1, n) {
		int cnt[2] = { 0, 0 };
		rep (j, 1, m) if (ch[i][j] == 'A') cnt[0]++;
		rep (j, 1, m) if (ch[i][j] == 'B') cnt[1]++;
		bool wall = false;
		rep (j, 1, m) wall |= ch[i][j] == 'H';

		if (wall) {
			rep (j, 1, cnt[0]) a[i][j] = 1;
			rep (j, m - cnt[1] + 1, m) a[i][j] = 2;
			rep (j, 1, m) if (ch[i][j] == 'H') a[i][j] = 3;
		} else {
			if (cnt[0] == cnt[1]) continue;
			if (cnt[0] > cnt[1]) rep (j, m - cnt[0] + 1, m) a[i][j] = 1;
			if (cnt[0] < cnt[1]) rep (j, 1, cnt[1]) a[i][j] = 2;
		}
	}

	rep (i, 1, n) {
		rep (j, 1, m) {
			if (not a[i][j]) std::cout << "#";
			else if (a[i][j] == 3) std::cout << "H";
			else {
				if (a[i][j] == a[i - 1][j] or a[i][j] == a[i + 1][j]) std::cout << "#";
				else if (a[i][j] == 1) std::cout << "A";
				else if (a[i][j] == 2) std::cout << "B";
			}
		}
		std::cout << "\n";
	}
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
