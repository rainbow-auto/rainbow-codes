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

const int maxn = 1000005;

int n;
int a[maxn];

struct Node {
	int val;
	i64 id;
};

Node ns[maxn];

i64 ans;

int main () {
	fastread
	
	std::cin >> n;
	for (int i = 1; i <= n; i++) { std::cin >> a[i]; ns[i] = Node { a[i], i }; }

	std::sort (ns + 1, ns + n + 1, [](Node x, Node y) { return x.val < y.val; } );

	i64 lnow = ns[1].id;
	i64 rnow = ns[1].id;
	i64 ans = (n - ns[1].id) * (n - ns[1].id + 1) / 2 + (ns[1].id - 1) * ns[1].id / 2;

	for (int i = 2; i <= n; i++) {
		if (lnow <= ns[i].id and ns[i].id <= rnow) { continue; }

		if (ns[i].id < lnow) { ans ^= 1ull * (n - rnow + 1) * (lnow - ns[i].id); }
		if (ns[i].id > rnow) { ans ^= 1ull * (ns[i].id - rnow) * lnow; }

		lnow = std::min (lnow, ns[i].id);
		rnow = std::max (rnow, ns[i].id);
	}

	std::cout << ans << "\n";

	return 0;
}
