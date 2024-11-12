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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 25;
const int maxS = (1 << 20) + 5;
const int maxm = 105;

int n, m;
int a[maxm][maxn];

bool vis[maxS];
int dis[maxS];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, m) {
		rep (j, 1, n) std::cin >> a[i][j];
	}

	int mask = (1 << n) - 1;
	dis[mask] = 0; vis[mask] = true;
	dis[0] = -1;

	std::queue<int> q; q.push(mask);

	while (not q.empty()) {
		int S = q.front(); q.pop();

		rep (i, 1, m) {
			int nxtS = S;
			rep (j, 1, n) {
				if (a[i][j] == 0) continue;
				if (a[i][j] == -1) nxtS |= 1 << (j - 1);
				if (a[i][j] == 1) nxtS &= (mask ^ (1 << (j - 1)));
			}

			if (vis[nxtS]) continue;
			vis[nxtS] = true;
			dis[nxtS] = dis[S] + 1;
			q.push(nxtS);
		}
	}

	std::cout << dis[0] << "\n";
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
