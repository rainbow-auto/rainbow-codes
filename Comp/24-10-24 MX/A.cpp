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

const int maxn = 5005;
const int maxc = 305;

int n, m, S;
short a[maxn][maxn];

std::vector<int> cols;

// int cnt[maxc];

void solve() {
	std::cin >> n >> m >> S;

	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> a[i][j];
			cols.push_back(a[i][j]);
		}
	}

	std::sort(cols.begin(), cols.end());
	cols.erase(std::unique(cols.begin(), cols.end()), cols.end());

	rep (i, 1, n) rep (j, 1, m) a[i][j] = std::lower_bound(cols.begin(), cols.end(), a[i][j]) - cols.begin() + 1;
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
