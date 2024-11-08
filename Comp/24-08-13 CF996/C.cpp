#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
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

const int maxn = 200005;

int n;
int a[maxn];

int m; 

std::string s[maxn];

inline void chk () {
	rep (i, 1, m) {
		std::map <char, int> id;
		std::set <int> used;

		if (s[i].size () != n) { std::cout << "NO\n"; goto End; }

		rep (j, 1, n) {
			if (id.count (s[i][j - 1])) {
				if (id[s[i][j - 1]] != a[j]) { std::cout << "NO\n"; goto End; }
			} else {
				id[s[i][j - 1]] = a[j];
				if (used.count (a[j])) { std::cout << "NO\n"; goto End; }
				used.insert (a[j]);
			}
		}

		std::cout << "YES\n";

		End:;
	}
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		std::cin >> n;
		rep (i, 1, n) { std::cin >> a[i]; }
		std::cin >> m;
		rep (i, 1, m) { std::cin >> s[i]; }

		chk ();
	}

	return 0;
}
