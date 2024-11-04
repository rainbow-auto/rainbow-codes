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
// #define MultiTask lovely_fairytale

const int maxn = 200005;

int n, m;

struct Node {
	int pre, nxt;
	i64 val;
} a[maxn];

inline void del(int x) {
	a[a[x].pre].nxt = a[x].nxt;
	a[a[x].nxt].pre = a[x].pre;
}

void solve() {
	std::cin >> n >> m;

	if (n < (m << 1)) return std::cout << "Error!\n", void(0);

	std::priority_queue<std::pair<i64, int>> q;	
	rep (i, 1, n) {
		i64 x; std::cin >> x;
		a[i] = Node { i - 1, i + 1, x };
		q.push(std::make_pair(x, (int) i));
	}

	a[n].nxt = 1;
	a[1].pre = n; 

	std::bitset<maxn> mark;

	i64 ans = 0;
	while (m--) {
		int x; do {
			x = q.top().second;
			q.pop();
		} while (mark[x]);

		db << "x: " << x << "\n";

		ans += a[x].val;
		a[x].val = a[a[x].pre].val + a[a[x].nxt].val - a[x].val;
		q.push(std::make_pair(a[x].val, (int) x));

		mark.set(a[x].pre); mark.set(a[x].nxt);
		del(a[x].pre); del(a[x].nxt);
	}	

	std::cout << ans << "\n";
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
	
	while (_--) {
		solve();
	}

	return 0;
}
