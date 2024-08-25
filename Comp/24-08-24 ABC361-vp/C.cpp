#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
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

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 200005;

int n, k;
int a[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> k;
	rep (i, 1, n) { std::cin >> a[i]; }

	k = n - k;

	std::sort (a + 1, a + n + 1);

	std::multiset <int> s;
	rep (i, 1, k - 1) { s.insert (a[i]); }
	
	int ans = 2e9;

	rep (i, k, n) {
		s.insert (a[i]);

		int mn = *s.begin ();
		int mx = *s.rbegin ();

		ans = std::min (ans, mx - mn);

		s.erase (s.find (a[i - k + 1]));
	}w
	std::cout << ans << "\n";

	return 0;
}
