#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

inline bool solve (std::string s) {
	if (s.size () <= 2) { return false; }
	
	if (s[0] != '1') { return false; }
	if (s[1] != '0') { return false; }

	int b = 0; bool lead = true;
	rep (i, 2, s.size () - 1) { 
		if (lead and s[i] == '0') { return false; }
		if (s[i] != '0') { lead = false; }
		b = b * 10 + (s[i] - '0'); 
	}

	return (b >= 2);
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		std::string s; std::cin >> s;
		if (solve (s)) { std::cout << "YES\n"; }
		else { std::cout << "NO\n"; }
	}

	return 0;
}
