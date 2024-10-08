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

const int maxn = 100005;

int n, m;
int x, y;
int d[maxn];

inline void sub(int l, int r) {
	if (l > r) return;
	d[l] --;
	d[r + 1] ++;
}

void solve() {
	std::cin >> n >> x >> y >> m;
	
	std::set<std::pair<int, int>> vis;	

	rep (i, 1, m) {
		int a, b; std::cin >> a >> b;
		if (a > b) std::swap(a, b);
		if (vis.count(std::make_pair(a, b))) continue;
		vis.insert(std::make_pair(a, b));
		sub(a + 1, b - 1);
	}

	int cur = y;
	rep (i, 1, n) std::cout << (cur += d[i]) << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
