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

const int maxn = 200005;
const int maxk = 55;

int n, k, p;
int a[maxn];
int color[maxn];

struct Sum {
	i64 sum[maxn];
	inline i64 query (int l, int r) { return sum[r] - sum[l - 1]; }
} prefix[maxk];

int main () {
	fastread

	std::cin >> n >> k >> p;

	for (int i = 1; i <= n; i++) { 
		std::cin >> color[i] >> a[i]; 
	}

	for (int i = 1; i <= n; i++) {
		for (int c = 0; c <= k - 1; c++) {
			prefix[c].sum[i] = prefix[c].sum[i - 1];
		}

		prefix[color[i]].sum[i] ++;
	}

	i64 ans = 0;

	int last = -1;

	for (int i = 1; i <= n; i++) {
		if (a[i] <= p) { last = i; } 

		if (last == i) {
			ans += prefix[color[i]].query (1, last - 1);
		} else {
			ans += prefix[color[i]].query (1, last);
		}
	}

	std::cout << ans << "\n";

	return 0;
}
