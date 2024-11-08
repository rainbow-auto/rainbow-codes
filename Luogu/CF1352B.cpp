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

std::vector<int> ans;

inline void solve (int n, int k) {
	ans.clear ();

	if (n > (k - 1) and ((n - (k - 1)) & 1)) {
		for (int i = 1; i <= k - 1; i++) { ans.push_back (1); n--; }
		ans.push_back (n);		
	}

	if (n > ((k - 1) << 1) and not ((n - ((k - 1) << 1)) & 1)) {
		for (int i = 1; i <= k - 1; i++) { ans.push_back (2); n -= 2; }
		ans.push_back (n);
	}
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		int n, k; std::cin >> n >> k;

		solve (n, k);

		if (ans.size ()) {
			std::cout << "YES\n";
			for (auto now : ans) { std::cout << now << " "; }
			std::cout << "\n";
		} else {
			std::cout << "NO\n";
		}
	}

	return 0;
}
