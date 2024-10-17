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

const int maxn = 1000005;

struct ACAM {
	struct Node {
		int ch[27];
		int fail;
	} tr[maxn];

	int rt, tot;

	inline void init() { rt = tot = 1; std::memset(tr, 0, sizeof tr); }

	ACAM() { init(); }

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

			for (int i = 0; i < 27; i++) {
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
} ac;

int n;
int end[maxn];

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

inline void counting(std::string s) {
	int now = ac.rt;
	for (auto c : s) {
		now = ac.tr[now].ch[c - 'a'];
		siz[now]++;
	}

	rep (i, ac.rt + 1, ac.tot) addEdge(ac.tr[i].fail, i);

	dfs(ac.rt);

	rep (i, 1, n) std::cout << siz[end[i]] << "\n";
}

void solve() {
	
	std::cin >> n;	

	std::string s;
	rep (i, 1, n) {
		std::string x; std::cin >> x;
		end[i] = ac.ins(x);
		s = s + x + "{";
	}	

	ac.build();

	counting(s);
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
