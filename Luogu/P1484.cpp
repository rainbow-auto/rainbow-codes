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

const int maxn = 2000005;

int n, k;
i64 a[maxn];

struct Node {
	int pre, nxt;
} ls[maxn];

void solve() {
	std::cin >> n >> k;

	rep (i, 1, n) std::cin >> a[i];	

	rep (i, 1, n) ls[i] = Node { i - 1, i + 1 };
	ls[0].nxt = 1;
	ls[n + 1].pre = n;

	std::priority_queue<std::pair<i64, int>> q;
	std::bitset<maxn> mark;

	rep (i, 1, n) q.push(std::make_pair(a[i], (int) i));

	i64 ans = 0;
	i64 mx = 0;

	while (k--) {
		int now; do {
			now = q.top().second;
			q.pop();
		} while (mark[now]);

		ans += a[now];
		
		if (ans < mx) return std::cout << mx << "\n", void(0);
		else mx = ans;

		a[now] = a[ls[now].pre] + a[ls[now].nxt] - a[now];
		mark.set(ls[now].pre); mark.set(ls[now].nxt);

		ls[ls[ls[now].pre].pre].nxt = now; ls[now].pre = ls[ls[now].pre].pre;
		ls[ls[ls[now].nxt].nxt].pre = now; ls[now].nxt = ls[ls[now].nxt].nxt;

		q.push(std::make_pair(a[now], now));
	}
	
	std::cout << mx << "\n";
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
