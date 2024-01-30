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

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 300005;
const i64 base = 3;
const i64 mod = 1e9 + 7;

int n;
i64 a[maxn];

i64 p[maxn];

struct Node {
	i64 hash1, hash2; // hash1 : 正序 ; hash2 : 倒序
	int len;
} tr[maxn << 3];

inline Node merge (Node a, Node b) {
	Node res;
	res.len = a.len + b.len;
	res.hash1 = (a.hash1 * p[b.len] % mod + b.hash1) % mod;
	res.hash2 = (b.hash2 * p[a.len] % mod + a.hash2) % mod;
	return res;
}

void build (int now, int l, int r) {
	if (l == r) { tr[now] = Node { 0, 0, 1 }; return; }

	int mid = (l + r) >> 1;
	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);

	tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
}

void modify (int now, int l, int r, int pos) {
	if (l == r) { tr[now].hash1 = tr[now].hash2 = 1; return; }

	int mid = (l + r) >> 1;
	if (pos <= mid) { modify (now << 1, l, mid, pos); }	
	if (pos > mid) { modify (now << 1 | 1, mid + 1, r, pos); }

	tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
}

Node query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now]; }

	int mid = (l + r) >> 1;

	if (R <= mid) { return query (now << 1, l, mid, L, R); }
	if (L > mid) { return query (now << 1 | 1, mid + 1, r, L, R); }

	return merge (query (now << 1, l, mid, L, R), query (now << 1 | 1, mid + 1, r, L, R));
}

int main () {
	fastread

	std::cin >> n;

	p[0] = 1;
	for (int i = 1; i <= n; i++) { p[i] = 1ll * p[i - 1] * base % mod; }

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	build (1, 1, n);

	for (int i = 1; i <= n; i++) {
		modify (1, 1, n, a[i]);

		i64 d = std::min (a[i] - 1, n - a[i]); // 排列a中最大为n
		
		if (query (1, 1, n, a[i] - d, a[i]).hash1 != query (1, 1, n, a[i], a[i] + d).hash2 and i >= 3) {
			std::cout << "YES\n";
			return 0;
		}
	}

	std::cout << "NO\n";

	return 0;
}
