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

inline i64 calc(std::vector<int> a) {
	int n = a.size();

	i64 val = 0;
	rep (i, 0, n - 1) val += a[i];
	val /= n;

	std::vector<i64> s(n);
	i64 sum = 0, cur = 0;
	rep (i, 0, n - 1) {
		sum += a[i];
		cur += val;

		s[i] = sum - cur;
	}

	std::sort(s.begin(), s.end());
	i64 p = s[((s.size() + 1) >> 1) - 1];

	i64 res = 0;
	rep (i, 0, n - 1) res += std::abs(s[i] - p);
	return res;
}

int n, m;

void solve() {
	std::cin >> n >> m;

	std::vector<std::pair<int,int>> ps;
	int t; std::cin >> t;
	rep (i, 1, t) {
		int x, y; std::cin >> x >> y;
		x--; y--;
		ps.push_back(std::make_pair(x, y));
	}


	bool flg1 = !(t % n);
	i64 res1 = 0;
	if (flg1) {
		std::vector<int> a(n);
		for (auto x : ps) a[x.first] ++;
		res1 = calc(a);
	} 

	bool flg2 = !(t % m);
	i64 res2 = 0;
	if (flg2) {
		std::vector<int> b(m);
		for (auto x : ps) b[x.second] ++;
		res2 = calc(b);
	}

	if (not flg1 and not flg2) {
		std::cout << "impossible\n";
	} else if (flg1 and not flg2) {
		std::cout << "row " << res1 << "\n";
	} else if (not flg1 and flg2) {
		std::cout << "column " << res2 << "\n";
	} else {
		std::cout << "both " << res1 + res2 << "\n";
	}
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
