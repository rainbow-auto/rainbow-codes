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

using i64 = unsigned long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 15000005;

int a[maxn];
int n, m, s;

int st[maxn][26];

int lg2[maxn];
inline void init_log2 () {
	lg2[1] = 0;
	for (int i = 2; i <= n; i++) {
		lg2[i] = lg2[i / 2] + 1;
	}
}

inline void build () {
	for (int i = 1; i <= n; i++) { st[i][0] = a[i]; }

	for (int len = 1; len <= 25; len ++) {
		for (int i = 1; i + (1 << len) - 1 <= n; i++) {
			st[i][len] = std::max (st[i][len - 1], st[i + (1 << (len - 1))][len - 1]);
		}
	}
}

inline i64 query (int l, int r) {
	int len = lg2[r - l + 1];
	return std::max (st[l][len], st[r - (1 << len) + 1][len]);
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
	
	init_log2 ();
	build ();

	for (int i = 1; i <= m; i++) { 
		int l, r; std::cin >> l >> r;
		if (l > r) { std::swap (l, r); }
		std::cout << query (l, r) << "\n";
	}

	return 0;
}
