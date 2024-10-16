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

struct Trie {
	struct Node {
		int ch[2];
		int end;
	} tr[maxn << 4];

	int rt, tot;

	Trie() { rt = tot = 1; std::memset(tr, 0, sizeof tr); }

	inline void ins(int x) {
		int now = rt;
		per (i, 30, 0) {
			int &t = tr[now].ch[!!(x & (1 << i))];
			if (not t) t = ++tot;
			now = t;
		}
	}

	inline int qry(int x) {
		int now = rt;
		int res = 0;
		per (i, 30, 0) {
			int cur = !!(x & (1 << i));
			if (tr[now].ch[cur ^ 1]) {
				res |= 1 << i;
				now = tr[now].ch[cur ^ 1];
			} else {
				now = tr[now].ch[cur];
			}
		}
		return res;
	}

} tr;

void solve() {
	int n; std::cin >> n;

	int ans = 0;
	rep (i, 1, n) {
		int x; std::cin >> x;
		tr.ins(x);
		ans = std::max(ans, tr.qry(x));
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
