#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 1005;

int curT;

int n;
std::map<int, int> bel;

std::queue<int> q[maxn];

bool solve() {
	std::cin >> n;

	if (not n) return false;

	std::cout << "Scenario #" << (++curT) << "\n";

	rep (i, 1, n) {
		int len; std::cin >> len;
		rep (j, 1, len) {
			int x; std::cin >> x;
			bel[x] = i;
		}
	}

	rep (i, 0, n) while (not q[i].empty()) q[i].pop();

	std::bitset<maxn> inq;

	while (true) {
		std::string op; std::cin >> op;

		if (op[0] == 'E') {
			int x; std::cin >> x;
			if (not inq[bel[x]]) {
				inq.set(bel[x]);
				q[0].push(bel[x]);
			}
			q[bel[x]].push(x);
		} else if (op[0] == 'D') {
			// if (q[0].empty()) continue;
			int x = q[0].front();
			// if (q[x].empty()) continue;

			std::cout << q[x].front() << "\n"; q[x].pop();
			
			if (q[x].empty()) {
				inq.reset(x);
				q[0].pop();
			}
		} else {
			break;
		}
	}

	std::cout << "\n";
	return true;
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
	
	while (solve());

	return 0;
}
