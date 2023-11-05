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

const int maxn = 2000005;

int n;
char s[maxn];

i64 f[maxn];
int lpos[maxn];

int main () {
	fastread

	std::cin >> n;

	std::cin >> (s + 1);

	for (int i = 2; i <= n; i++) {
		int now = i - 1;
		while (now > 0 and s[now] != s[i]) { now = lpos[now] - 1; }
		lpos[i] = now;
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (lpos[i] <= 0) { continue; }

		f[i] = f[lpos[i] - 1] + 1;
		ans += f[i];
	}

	std::cout << ans << "\n";

	return 0;
}
