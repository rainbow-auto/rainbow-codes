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

const int maxn = (1 << 20) + 10;
const int inf = 0x3f3f3f3f;

int n;

int a[maxn];

struct Node {
	int mx1, mx2;
	
	friend Node operator + (Node x, Node y) {
		Node res;
		if (x.mx1 > y.mx1) {
			res.mx1 = x.mx1;
			res.mx2 = std::max ({ x.mx2, y.mx1, y.mx2 });
		} else {
			res.mx1 = y.mx1;
			res.mx2 = std::max ({ x.mx1, x.mx2, y.mx2 });
		}
		return res;
	}
};

Node sum[maxn];

int main () {
	fastread

	std::cin >> n;
	int m = (1 << n);

	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
		sum[i] = Node { a[i], -inf };
	}

	for (int i = 0; i < n; i++) {
		for (int S = 0; S < m; S++) {
			if (S & (1 << i)) { sum[S] = sum[S] + sum[S ^ (1 << i)]; }
		}
	}

	int curr = 0;
	for (int k = 1; k <= m - 1; k++) {
		curr = std::max (curr, sum[k].mx1 + sum[k].mx2);
		std::cout << curr << "\n";
	}

	return 0;
}
