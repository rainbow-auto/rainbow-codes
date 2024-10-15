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

struct Trie {
	struct Node {
		int ch[26];
		int end;
	} tr[maxn];

	int rt, tot;

	Trie() {
		std::memset(tr, 0, sizeof tr);
		rt = tot = 1;
	}

	inline void ins(const std::string& s) {
		int now = rt;
		for (auto c : s) {
			int& t = tr[now].ch[c - 'a'];
			if (not t) t = ++tot;
			now = t;
		}
		tr[now].end ++;
	}

	inline int qry(const std::string& t) {
		int res = 0;
		int now = rt;
		for (auto c : t) {
			now = tr[now].ch[c - 'a'];
			res += tr[now].end;
		}
		return res;
	}
} tr;

int n, m;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		std::string s; std::cin >> s;
		tr.ins(s);
	}

	while (m--) {
		std::string t; std::cin >> t;
		std::cout << tr.qry(t) << "\n";
	}
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
