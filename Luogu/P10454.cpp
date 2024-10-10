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

const int maxn = 250005;

struct Tree {
	int tr[maxn];
	int mx;

	Tree(int _mx) {
		mx = _mx;
		clr();
	}

	inline int lowbit(int x) { return x & (-x); }

	inline void mdfy(int pos, int val) {
		for (int i = pos; i <= mx; i += lowbit(i)) tr[i] += val;
	}

	inline int qry(int pos) {
		int res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}

	void clr() {
		rep (i, 1, mx) tr[i] = 0;
	}	
};

bool chk(int n) {
	int mx = 0;
	
	std::vector<int> a;
	rep (i, 1, n) {
		rep (j, 1, n) {
			int x; std::cin >> x;
			if (not x) continue;
			a.push_back(x);
			mx = std::max(mx, x);
		}
	}

	Tree tr(mx);

	i64 res = 0;
	for (auto x : a) {
		res += tr.qry(mx) - tr.qry(x);
		tr.mdfy(x, 1);
	}

	return res & 1;
}

void RainbowAutomaton(int n) {
	bool res1 = chk(n);
	bool res2 = chk(n);

	if (res1 ^ res2) std::cout << "NIE\n";
	else std::cout << "TAK\n";
}

void solve() {
	int n;
	while (std::cin >> n) RainbowAutomaton(n);
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
