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
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 22;

int n;

struct Operation {
	int x, y, z;
};

std::vector<Operation> ops, ans;
int ans_cnt;

void dfs(std::vector<std::pair<i64, int>> s) {
	if (not s.size()) {
		if (ops.size() < ans_cnt) {
			ans = ops;
			ans_cnt = ops.size();
		}
		return;
	}

	rep (i, 0, s.size() - 1) {
		rep (j, 0, s.size() - 1) {
			if (s[i].first < 0) continue;
			if (s[j].first > 0) continue;

			auto nxt = s;
			int z = std::min(s[i].first, -s[j].first); 
			nxt[i].first -= z;
			nxt[j].first += z;
			std::vector<std::pair<i64, int>> nnxt;
			for (auto x : nxt) if (x.first != 0) nnxt.push_back(x);
			ops.push_back({i, j, z});
			dfs(nnxt);
			ops.pop_back();
		}
	}
}

void solve() {
	std::cin >> n;
	i64 sum = 0;
	std::vector<std::pair<i64, int>> st;
	rep (i, 1, n) {
		int x; std::cin >> x;
		st.push_back({x, i});
		sum += x;
	}

	if (sum % n) return std::cout << "-1\n", void(0);
	for (auto &x : st) x.first -= sum % n;

	ans_cnt = 0x3f3f3f3f;
	dfs(st);

	std::cout << ans.size() << "\n";
	for (auto [x, y, z] : ans) std::cout << x << " " << y << " " << z << "\n";
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
