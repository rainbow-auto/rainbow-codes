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

const int maxn = 1005;

int n, m, k;
std::set <int> s[maxn];

int main () {
	fastread

	std::cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x; std::cin >> x;
			s[x].insert (j);
		}
	}

	for (int i = 1; i <= k; i++) {
		std::cout << s[i].size () << " ";
	}
	std::cout << "\n";

	return 0;
}
