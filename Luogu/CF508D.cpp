#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

// #define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

int n;

const int maxn = 200005;

const int base = 256;
inline int getID (char fst, char sec) {
	return (fst * base) + sec;
}

std::vector <int> g[maxn];
int ind[maxn], otd[maxn];

std::string ans;

void dfs (int now) {
	db (now);

	while (not g[now].empty ()) {
		int t = g[now].back ();
		g[now].pop_back ();
		dfs (t);
	}
	ans += (char) (now % 256); // 获取当前节点的第二个字符
}

int main () {
	fastread
	
	std::cin >> n;

	int tot = 0;
	int start = 0;

	for (int i = 1; i <= n; i++) {
		std::string s; std::cin >> s;
		int u = getID (s[0], s[1]);
		int v = getID (s[1], s[2]);
		g[u].push_back (v);
		ind[v] ++;
		otd[u] ++;

		tot = std::max (tot, u); tot = std::max (tot, v);
		start = u;
	}

	int dcnt1 = 0;
	int dcnt2 = 0;
	for (int i = 1; i <= tot; i++) {
		if (ind[i] - otd[i] == 0) { continue; }

		if (ind[i] - otd[i] == 1) { dcnt1 ++; continue; }

		if (ind[i] - otd[i] == -1) { dcnt2 ++; start = i; continue; }

		std::cout << "NO\n";
		return 0;
	}

	if (dcnt1 > 1 or dcnt2 > 1 or dcnt1 + dcnt2 == 1) { std::cout << "NO\n"; return 0; }

	dfs (start);
	ans += (char) (start / 256);

	if (ans.size () != n + 2) { std::cout << "NO\n"; return 0; }

	std::reverse (ans.begin (), ans.end ());

	std::cout << "YES\n";
	std::cout << ans << "\n";

	return 0;
}
