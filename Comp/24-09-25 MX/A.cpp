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

const int maxn = 500005;

int n;
struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxn << 1];

int last[maxn], cnt;
void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

namespace Task1 {
	int dep[maxn];

	std::vector <int> sons[maxn];
	void build(int now, int fa) {
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa) continue;
			sons[now].push_back(t);
			dep[t] = dep[now] + es[i].w;
			build(t, now);
		}
	}

	i64 ans;

	using Info = std::pair<int, std::vector<int>>;

	void merge(Info& a, const Info b) {
		a.first = std::max(a.first, b.first);
		for (auto x : b.second) a.second.push_back(x);
	}

	Info dfs(int now, int y) {
		std::vector<Info> s;
		std::vector<Info> ni;

		std::multiset<int> mxs;

		for (auto t : sons[now]) {
			Info ti = dfs(t);
			s.push_back(ti);
			mxs.insert(ti.first);
			merge(ni, ti);
		}

		int tot = s.size();
		
		rep (i, 0, tot - 1) {
			mxs.erase(mxs.find(s[i].first));
			rep (j, i + 1, tot - 1) {
				mxs.erase(mxs.find(s[j].first));
				int x = *mxs.rbegin();
				for (auto u : s[i].second) {
					for (auto v : s[j].second) {
						i64 cur = std::max({dep[u] + dep[v] - 2 * dep[now], std::min(dep[u], dep[v]) + y, std::min(dep[u], dep[v]) + x - dep[now]});
					}
				}
				mxs.insert(s[j].second);
			}
			mxs.insert(s[i].second);
		}

		Info cur;
		cur.first = dep[now];
		cur.second.push_back(now);
		merge(ni, cur);

		return ni;
	}

	void solve() {
		ans = 0;
		build(1, -1);
		dfs(1);

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
