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

const int maxn = 100005;

int n, k;
i64 w[maxn];

struct Node {
	i64 w;
	int dep;

	static inline bool comp(Node a, Node b) {
		if (a.w != b.w) return a.w < b.w;
		return a.dep < b.dep;
	}

	friend bool operator < (Node a, Node b) {
		return not comp(a, b);
	}
};

std::priority_queue<Node> q;

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> w[i];

	rep (i, 1, n) q.push(Node { w[i], 0 });

	while (((int) q.size() - 1) % (k - 1)) q.push(Node { 0, 0 });

	i64 ans = 0;
	int mxdep = 0;

	while (q.size() >= k) {
		i64 val = 0;
		int dep = 0;
		rep (i, 1, k) {
			val += q.top().w;
			dep = std::max(dep, q.top().dep);
			q.pop();
		}

		ans += val;
		mxdep = std::max(mxdep, dep + 1);

		q.push(Node { val, dep + 1 });
	}	

	std::cout << ans << "\n";
	std::cout << mxdep << "\n";
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
