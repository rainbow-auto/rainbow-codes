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

const int maxn = 5005;

int n, m;

struct Node {
	int l, r;

	friend bool operator < (Node a, Node b) {
		return a.l > b.l;
	}
} a[maxn];

std::map<int, int> cnt;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i].l >> a[i].r;

	rep (i, 1, m) {
		int spf, x; std::cin >> spf >> x;
		cnt[spf] += x;
	}

	std::sort(a + 1, a + n + 1);

	int ans = 0;
	rep (i, 1, n) {
		int choice = -1;
		for (auto x : cnt) {
			int s, c; std::tie(s, c) = x;
			if (not c) continue;
			if (a[i].l <= s and s <= a[i].r) choice = s;
		}

		if (~choice) ans++, cnt[choice]--;
	}

	std::cout << ans << "\n";
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
