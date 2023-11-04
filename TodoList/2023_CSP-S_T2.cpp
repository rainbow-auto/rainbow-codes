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

namespace Subtask1 {
	
	inline void solve () {
		i64 ans = 0;

		for (int l = 1; l <= n; l ++) {
			std::stack <char> stk;
			for (int r = l; r <= n; r ++) {
				if (stk.empty ()) { stk.push (s[r]); continue; }
				
				if (stk.top () == s[r]) { stk.pop (); }
				else { stk.push (s[r]); }

				if (stk.empty ()) { ans ++; }
			}
		}

		std::cout << ans << "\n";
	}	
}


int main () {
	fastread

	// freopen ("lock.in", "r", stdin);
	// freopen ("lock.out", "w", stdout);

	std::cin >> n;
	std::cin >> (s + 1);

	Subtask1::solve ();

	return 0;
}
