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

constexpr int maxn = 100005;

int n, m;

std::string s;

void solve() {
	std::cin >> n >> m;
	std::set<int> b;
	
	std::cin >> s; s = " " + s;
	
	rep (i, 1, m) {
		int x; std::cin >> x;
		b.insert(x);
	}
	
	auto nxt = [&](int pos) -> int {
		auto it = b.upper_bound(pos);
		int lst = pos;
		while (true) {
			if (it == b.end()) {
				return lst + 1;
			}
			if ((*it) != lst + 1) {
				return lst + 1;
			}
			lst = (*it);
			it++;
		}
	};

	int pos = 1;
	rep (i, 1, n) {
		char op = s[i];
		if (op == 'A') {
			pos++;
			b.insert(pos);
		} else {
			int t = nxt(pos);
			b.insert(t);
			pos = nxt(t);
		}
	}

	std::cout << b.size() << "\n";
	for (auto p : b) std::cout << p << " "; std::cout << "\n";
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
