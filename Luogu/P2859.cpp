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

const int maxn = 1000005;

int n;

std::vector<int> tsk[maxn][2];

int id[maxn];

void solve() {
	std::cin >> n;
	int R = 0;
	rep (i, 1, n) {
		int l, r; std::cin >> l >> r;
		tsk[l][0].push_back(i);
		tsk[r][1].push_back(i);

		R = std::max(R, r);
	}

	std::set<int> rst;
	int tot = 0;

	auto get = [&]() -> int {
		int x;
		if (rst.empty()) x = ++tot;
		else rst.erase(x = *rst.begin());
		return x;
	};

	rep (i, 1, R) {
		for (auto x : tsk[i][0]) id[x] = get();
		for (auto x : tsk[i][1]) rst.insert(id[x]);
	}

	std::cout << tot << "\n";
	rep (i, 1, n) std::cout << id[i] << "\n";
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
