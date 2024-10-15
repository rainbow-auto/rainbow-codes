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

int n;

std::vector<int> get_pi(std::string s) {
	std::vector<int> pi(s.length());

	rep (i, 2, (int) s.length() - 1) {
		int j = pi[i - 1];
		while (j and s[j + 1] != s[i]) j = pi[j];
		if (s[j + 1] == s[i]) j++;
		pi[i] = j;
	}

	return pi;
}

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

std::set<int> pos;
std::set<int> dis;

void add(int now) {
	auto it = pos.lower_bound(now);

	if (it != pos.end()) dis.insert((*it) - now);
	if (it != pos.begin()) dis.insert(now - (*std::prev(it)));

	if (it != pos.end() and it != pos.begin()) dis.erase((*it) - (*std::prev(it)));

	pos.insert(now);
}

void ins(int now) {
	add(now);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		ins(t);
	}
}

inline bool chk(int len) {
	return (dis.empty() or ((*dis.rbegin()) <= len)) and (*pos.begin()) <= (len << 1);
}

void solve() {
	std::string s; std::cin >> s;
	n = s.length();
	s = " " + s;

	auto pi = get_pi(s);

	rep (i, 1, n) addEdge(pi[i], i);

	pos.insert(n);

	int now = n;
	int ans = n;
	while (now) {
		int lst = now;
		now = pi[now];

		add(lst);
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == lst) continue;
			ins(t);
		}

		if (chk(now)) ans = now;
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
