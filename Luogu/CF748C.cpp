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
std::string s;

inline void solve () {

	char vertical_last = '#';
	char horizontal_last = '#';
	int ans = 1;

	for (int i = 1; i <= n; i++) {
		if (s[i] == 'U' or s[i] == 'D') {
			if (horizontal_last == '#') { horizontal_last = s[i]; continue; }
			if (horizontal_last == s[i]) { continue; }
			horizontal_last = s[i];
			vertical_last = '#';
		} else if (s[i] == 'R' or s[i] == 'L') {
			if (vertical_last == '#') { vertical_last = s[i]; continue; }
			if (vertical_last == s[i]) { continue; }
			vertical_last = s[i];
			horizontal_last = '#';
		}

		ans ++;
	}

	std::cout << ans << "\n";
}

int main () {
	fastread
	
	std::cin >> n;

	std::cin >> s;
	s = " " + s;

	solve ();
	
	return 0;
}
