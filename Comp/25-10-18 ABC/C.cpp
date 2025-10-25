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

int q;
std::vector<int> a;
std::vector<int> sum;

std::multiset<int> sms;

void solve() {
	std::cin >> q;

	a.push_back(0);
	sum.push_back(0);
	
	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			char c; std::cin >> c;
			int x;
			if (c == '(') x = 1;
			if (c == ')') x = -1;

			a.push_back(x);
			sum.push_back(sum.back() + x);
			sms.insert(sum.back());
		} else {
			a.pop_back();
			sms.erase(sms.find(sum.back()));
			sum.pop_back();
		}

		if (sum.back() == 0 and (*sms.begin() >= 0)) std::cout << "Yes\n";
		else std::cout << "No\n";
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
