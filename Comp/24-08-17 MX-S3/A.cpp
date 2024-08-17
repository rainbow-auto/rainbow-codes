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

const int maxn = 1000005;

inline int read () {
	int res = 0, flag = 1;
	char ch = getchar ();

	while (not isdigit (ch)) { ch = getchar (); }
	while (isdigit (ch)) { res = res * 10 + (ch - '0'); ch = getchar (); }

	return res;
}

int n;
int p[maxn];

struct Node {
	std::set <int> nums;
	struct Map {
		int t[maxn];
		int siz;

		inline void clear (int R) {
			rep (i, 0, R) { t[i] = 0; }
			siz = 0;
		}

		inline void ins (int val) { 
			if (t[val] == 0) { siz ++; }
			t[val] ++; 
		}

		inline void del (int val) {
			t[val] --;
			if (t[val] == 0) { siz --; }
		}
	} d;

	inline void clear (int R) {
		d.clear (R);
		nums.clear ();
	}

	inline void ins (int val) {
		if (nums.size () == 0) { nums.insert (val); return; }

		auto it = nums.lower_bound (val);

		int minn = (*nums.begin ());
		int maxx = (*nums.rbegin ());

		if (minn < val and maxx > val) { d.del ((*it) - (*std::prev (it))); }
		if (minn < val) { d.ins (val - (*std::prev (it))); }
		if (maxx > val) { d.ins ((*it) - val); }

		nums.insert (val);
	}
	
	inline void del (int val) {
		if (nums.size () == 1) { nums.erase (val); return; }

		auto it = nums.lower_bound (val);
		
		int minn = (*nums.begin ());
		int maxx = (*nums.rbegin ());

		if (minn < val) { d.del (val - (*std::prev (it))); }
		if (maxx > val) { d.del ((*std::next (it)) - val); }
		if (minn < val and maxx > val) { d.ins ((*std::next (it)) - (*std::prev (it))); }

		nums.erase (val);
	}

	inline bool chk () { return d.siz == 1 or nums.size () == 1; }

} pre, suf;

int main () {
	fastread

	// int T; std::cin >> T;
	int T = read ();

	while (T--) {
		// std::cin >> n;
		n = read ();
		// rep (i, 1, n) { std::cin >> p[i]; }
		rep (i, 1, n) { p[i] = read (); }

		pre.clear (n); suf.clear (n);

		int ans = 0;

		rep (i, 2, n) { suf.ins (p[i]); } 
		pre.ins (p[1]);

		ans += bool (pre.chk () and suf.chk ());
		rep (i, 2, n - 1) {
			pre.ins (p[i]); suf.del (p[i]);		
			ans += bool (pre.chk () and suf.chk ());	
		}	

		std::cout << ans << "\n";
	}

	return 0;
}
