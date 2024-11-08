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

const int maxn = 100005;

int n, m, k;
int s[maxn];

namespace Subtask1 {

	int ord[maxn];	

	inline int getAns () {
		int ans = 0;
		for (int i = 1; i <= n - 1; i++) {
			if (ord[s[i]] <= ord[s[i + 1]]) { ans += ord[s[i + 1]] - ord[s[i]]; }
			else { ans += (ord[s[i]] + ord[s[i + 1]]) * k; }
		}

		return ans;
	}

	inline void solve () {
		for (int i = 1; i <= m; i++) { ord[i] = i; }

		int ans = 0x3f3f3f3f;

		do {
			ans = std::min (ans, getAns ());
		} while (std::next_permutation (ord + 1, ord + m + 1));
		
		std::cout << ans << '\n';
	}
}

int main () {
	fastread
	
	std::cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) { std::cin >> s[i]; }

	Subtask1::solve ();

	return 0;
}
