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
#include <queue>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 100005;
const i64 mod = 1e9 + 7;

int n, m;

inline i64 ksm (i64 a, int b) {
	i64 res = 1;
	i64 base = a;
	while (b) {
		if (b & 1) { res = res * base % mod; }

		base = base * base % mod;
		b >>= 1;
	}

	return res;
}

int log2[maxn << 1];
inline void log2_init () {
	log2[1] = 0;
	for (int i = 2; i <= n; i++) { log2[i] = log2[i >> 1] + 1; }
}

int fa[maxn][25];

int find (int x, int len) {
	if (fa[x][len] == x) { return fa[x][len]; }
	return fa[x][len] = find (fa[x][len], len);
}

inline void merge (int l1, int l2, int len) {
	int fa1 = find (l1, len);
	int fa2 = find (l2, len);

	fa[fa1][len] = fa2;	
}

inline void fa_init () {
	for (int len = 20; len >= 0; len--) {
		for (int i = 1; i <= n; i++) { fa[i][len] = i; }
	}
}

int main () {
	fastread

	std::cin >> n >> m;

	fa_init ();
	log2_init ();

	for (int i = 1; i <= m; i++) {
		int l1, r1, l2, r2; std::cin >> l1 >> r1 >> l2 >> r2;
		int len = log2[r1 - l1 + 1];
		merge (l1, l2, len);
		merge (r1 - (1 << len) + 1, r2 - (1 << len) + 1, len);	
	}

	// 分裂区间
	for (int len = 20; len >= 1; len--) {
		for (int i = 1; i + (1 << len) - 1 <= n; i++) {
			int fa_i = find (i, len);
			if (fa_i == i) { continue; }

			// 分裂
			merge (i, fa_i, len - 1);
			merge (i + (1 << (len - 1)), fa_i + (1 << (len - 1)), len - 1);
		}
	}	

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (fa[i][0] == i) { ++cnt; }
	}
	
	std::cout << (ksm (10, cnt - 1) * 9ll) % mod << "\n";

	return 0;
}
