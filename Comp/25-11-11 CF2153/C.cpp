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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

void solve() {
	int n; std::cin >> n;
	std::map<i64, i64> cnt;

	rep (i, 1, n) {
		int x; std::cin >> x;
		cnt[-x]++;
	}

	i64 len = 0;
	i64 tot = 0;

	for (auto _ : cnt) {
		i64 x = _.first, c = _.second;
		x = -x;
		if (c & 1) c--;
		len += x * c;
		tot += c;
	}

	if (not tot) return std::cout << "0\n", void(0);

	std::vector<i64> mids;
	for (auto _ : cnt) {
		i64 x = _.first, c = _.second;
		x = -x;
		if (c & 1) {
			mids.push_back(x);
		}
	}

	if (mids.size() == 0) {
		if (tot <= 2) return std::cout << "0\n", void(0);
		else return std::cout << len << "\n", void(0);
	}
	if (mids.size() == 1) {
		if (len > mids.front()) {
			std::cout << mids.front() + len << "\n";
		} else {
			if (tot <= 2) std::cout << "0\n";
			else std::cout << len << "\n";
		}
		return;
	}

	mids.push_back(0);
	rep (i, 0, (int) mids.size() - 2) {
		if (len + mids[i + 1] > mids[i]) return std::cout << mids[i] + mids[i + 1] + len << "\n", void(0);
	}

	if (tot <= 2) return std::cout << "0\n", void(0);
	std::cout << len << "\n";
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
