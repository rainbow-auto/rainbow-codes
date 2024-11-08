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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 100005;

int n, q;
std::string a;

int sum[maxn];

int main () {
	fastread

	std::cin >> n >> q;
	std::cin >> a; a = " " + a;

	for (int i = 2; i <= n; i++) { sum[i] = sum[i - 1] + bool (a[i] != a[i - 1]); }

	while (q--) {
		int l, r; std::cin >> l >> r;

		int ans = ((sum[r] - sum[l] + bool (a[r] != a[l]) + 1) >> 1); // +1 上取整

		std::cout << ans << "\n";
	}

	return 0;
}
