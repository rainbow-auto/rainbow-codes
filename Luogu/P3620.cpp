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

struct ListNode {
	int pre, nxt;
	i64 val;
} d[maxn];

struct Node {
	int pos;
	i64 val;

	friend bool operator < (Node x, Node y) {
		return x.val > y.val;
	}
};

int n, k;
int a[maxn];

std::priority_queue<Node> q;
std::bitset<maxn> removed;

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];
	
	rep (i, 1, n - 1) d[i] = ListNode { i - 1, i + 1, a[i + 1] - a[i] };
	d[0].nxt = 1; d[0].val = 0x3f3f3f3f;
	d[n].pre = n - 1; d[n].val = 0x3f3f3f3f;

	rep (i, 1, n - 1) q.push(Node { i, d[i].val });

	i64 ans = 0;
	rep (_, 1, k) {
		int x; do {
			x = q.top().pos; q.pop();
		} while (removed[x]);

		ans += d[x].val;

		d[x].val = d[d[x].pre].val + d[d[x].nxt].val - d[x].val;
		q.push(Node { x, d[x].val });

		removed.set(d[x].pre); removed.set(d[x].nxt);

		if (d[x].pre != 0) d[x].pre = d[d[x].pre].pre;
		if (d[x].nxt != n) d[x].nxt = d[d[x].nxt].nxt;

		d[d[x].pre].nxt = x;
		d[d[x].nxt].pre = x;
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
