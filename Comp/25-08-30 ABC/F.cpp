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

constexpr int maxn = 500005;

int q;

int nxt[maxn];

int tot = 0;

void solve() {
	std::cin >> q;
	
	int tail = q + 1;
	nxt[0] = tail;
	nxt[tail] = tail;

	rep (i, 1, q) {
		int op; std::cin >> op;

		if (op == 1) {
			int x; std::cin >> x;
			nxt[i] = nxt[x];
			nxt[x] = i;
		} else {
			int p, q; std::cin >> p >> q;
			int np = p, nq = q;
			i64 sp = 0, sq = 0;
			while (true) {
				if (np == q) {
					nxt[p] = np;
					std::cout << sp - q << "\n";
					break;
				}
				if (nq == p) {
					nxt[q] = nq;
					std::cout << sq - p << "\n";
					break;
				} 

				np = nxt[np], nq = nxt[nq];
				sp += np;
				sq += nq;
			}
		}
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
