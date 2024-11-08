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

using std::cin;
using std::cout;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

const int maxn = 2000005;

int n;
std::string s;

int sa[maxn], rk[maxn];

int cnt[maxn];
int old_rk[maxn], id[maxn], key1[maxn];

inline bool comp (int x, int y, int w) {
	return old_rk[x] == old_rk[y] and old_rk[x + w] == old_rk[y + w];
}

int main () {
	fastread

	cin >> s; s = " " +	s;
	n = s.size () - 1;

	int m = 127;

	for (int i = 1; i <= n; i++) { cnt[rk[i] = s[i]] ++; }
	for (int i = 1; i <= m; i++) { cnt[i] += cnt[i - 1]; }
	for (int i = n; i >= 1; i--) { sa[cnt[rk[i]]--] = i; }

	int p;
	for (int w = 1; ; w <<= 1, m = p) {
		p = 0;
		for (int i = n; i + w > n; i--) { id[++p] = i; }
		for (int i = 1; i <= n; i++) { if (sa[i] - w > 0) { id[++p] = sa[i] - w; } }

		memset (cnt, 0, sizeof (cnt));
		for (int i = 1; i <= n; i++) { cnt[key1[i] = rk[id[i]]] ++; }
		for (int i = 1; i <= m; i++) { cnt[i] += cnt[i - 1]; }
		for (int i = n; i >= 1; i--) { sa[cnt[key1[i]]--] = id[i]; }

		p = 0;
		memcpy (old_rk + 1, rk + 1, sizeof (int) * n);
		for (int i = 1; i <= n; i++) { rk[sa[i]] = comp (sa[i], sa[i - 1], w) ? p : ++p; }

		if (p == n) { break; }
	}

	for (int i = 1; i <= n; i++) { cout << sa[i] << " "; }

	return 0;
}
