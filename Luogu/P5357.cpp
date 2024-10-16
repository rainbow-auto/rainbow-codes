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

int n, m;

struct ACAM {
	struct Node {
		int ch[26];
		int fail;
	} tr[maxn];

	int rt, tot;

	ACAM() { rt = tot = 1; std::memset(tr, 0, sizeof tr); }

	inline int ins(const std::string &s) {
		int now = rt;
		for (auto c : s) {
			int &t = tr[now].ch[c - 'a'];
			if (not t) t = ++tot;
			now = t;
		}
		return now;
	}

	inline void build() {
		for (auto &t : tr[0].ch) t = rt;

		std::queue<int> q;
		q.push(rt);

		while (not q.empty()) {
			int now = q.front(); q.pop();

			rep (i, 0, 25) {
				int &t = tr[now].ch[i];
				int f = tr[tr[now].fail].ch[i];

				if (not t) t = f;
				else {
					tr[t].fail = f;
					q.push(t);
				}
			}
		}
	}

	struct Edge {
		int u, v;
		int pre;
	} es[maxn];

	int last[maxn], cnt;

	inline void addEdge(int u, int v) {
		es[++cnt] = Edge { u, v, last[u] };
		last[u] = cnt;
	}

	int siz[maxn];
	void dfs(int now) {
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			dfs(t);
			siz[now] += siz[t];
		}
	}

	inline void counting(const std::string &s) {
		int now = rt;
		for (auto c : s) {
			now = tr[now].ch[c - 'a'];
			siz[now] ++;
		}	

		rep (i, 2, tot) addEdge(tr[i].fail, i);

		dfs(rt);
	}
} acam;

int end[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::string s; std::cin >> s;
		end[i] = acam.ins(s);
	}

	acam.build();

	std::string s; std::cin >> s;
	acam.counting(s);

	rep (i, 1, n) std::cout << acam.siz[end[i]] << "\n";
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
