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

const int maxn = 155;
const int maxL = 85;

template <int maxn>
struct ACAM {
	struct Node {
		int ch[26];
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

			for (int i = 0; i < 26; i++) {
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
};

ACAM<maxn * maxL> ac;

int n;
std::string a[maxn];
int end[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn * maxL];

int last[maxn * maxL], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int siz[maxn * maxL];

void dfs(int now) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		dfs(t);
		siz[now] += siz[t];
	}
}


inline void counting(const std::string &s) {
	std::memset(siz, 0, sizeof siz);
	std::memset(last, 0, sizeof last);
	cnt = 0;

	int now = ac.rt;
	for (auto c : s) {
		now = ac.tr[now].ch[c - 'a'];
		siz[now]++;
	}

	rep (i, 2, ac.tot) addEdge(ac.tr[i].fail, i);
	dfs(ac.rt);

	std::vector<std::pair<int, int>> ans;
	rep (i, 1, n) ans.push_back(std::make_pair(-siz[end[i]], i));

	std::sort(ans.begin(), ans.end());

	int mx = -ans.front().first;

	std::cout << mx << "\n";
	for (auto x : ans) {
		if (-x.first != mx) break;
		std::cout << a[x.second] << "\n";
	}
}

inline bool Rainbow() {
	std::cin >> n;
	if (not n) return false;

	rep (i, 1, n) std::cin >> a[i];

	ac.init();

	rep (i, 1, n) end[i] = ac.ins(a[i]);

	ac.build();

	std::string s; std::cin >> s;

	counting(s);

	return true;
}

void solve() {
	while (Rainbow());
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
