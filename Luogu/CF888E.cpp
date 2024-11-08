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

int n;
i64 m;

std::vector<i64> a[2];

inline bool get (int S, int pos) { return S & (1 << pos); }

std::vector<i64> ans[2];

inline void solve (int id) {
	for (int S = 0; S < (1 << a[id].size ()); S++) {
		i64 res = 0;
		for (int i = 0; i < a[id].size (); i++) {
			if (get (S, i)) { res = (res + a[id][i]) % m; }
		}
		ans[id].push_back (res % m);
	}
}

inline void merge () {
	std::sort (ans[1].begin (), ans[1].end ());
	
	i64 fans = 0; // final answer
	for (auto x : ans[0]) {
		int pos = std::lower_bound (ans[1].begin (), ans[1].end (), m - x) - ans[1].begin () - 1;
		fans = std::max (fans, (ans[1][pos] + x) % m);
		fans = std::max (fans, (ans[1][ans[1].size () - 1] + x) % m);
	}

	std::cout << fans << "\n";
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { 
		i64 x; std::cin >> x; x %= m;
		a[i > (n >> 1)].push_back (x);
	}

	solve (0);
	solve (1);

	merge ();

	return 0;
}
