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

constexpr int maxn = 200005;

int n;
int a[maxn];

int st[maxn], ed[maxn], tot;
int pre[maxn], nxt[maxn];

/*
12
1 2 3 4 5 6 7 8 9 10 11 12
  1   0   1 1     1     0
*/

void solve() {
	std::cin >> n;

	a[0] = 2; a[n + 1] = 2;

	std::set<int> rst;
	rep (i, 1, n) {
		std::cin >> a[i];

		if (a[i] != a[i - 1]) {
			++tot;
			st[tot] = i;
			rst.insert(tot);
		}

		ed[tot] = i;

		pre[i] = i - 1;
		nxt[i] = i + 1;
	}	

	// rep (i, 1, tot) db << st[i] << " "; dbendl; 

	while (not rst.empty()) {
		// db << "rst: ";
		for (auto x : rst) {
			// db << x << " ";
			int t = st[x];
			std::cout << t << " ";

			nxt[pre[t]] = nxt[t];
			pre[nxt[t]] = pre[t];
		}
		// dbendl;
		std::cout << "\n";

		std::vector<int> del;

		for (auto x : rst) {
			int t = st[x];

			if (a[nxt[t]] == a[t]) {
				st[x] = nxt[t];
			} else {
				del.push_back(x);
			}
		}

		for (auto x : del) rst.erase(x);
		del.clear();

		// db << "segs: ";
		// for (auto x : rst) {
		// 	db << "(" << st[x] << " " << ed[x] << ") ";
		// }
		// dbendl;

		int lst = -1;
		for (auto x : rst) {
			if (not ~lst) {
				lst = x;
				continue;
			}

			if (a[st[x]] == a[st[lst]]) del.push_back(x);
			lst = x;
		}

		for (auto x : del) rst.erase(x);
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
