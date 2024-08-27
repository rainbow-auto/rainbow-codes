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
#include <cassert>

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

const int maxn = 100005;

i64 exgcd (i64 a, i64 b, i64& x, i64& y) {
	if (not b) { x = 1; y = 0; return a; }
	i64 d = exgcd (b, a % b, y, x);
	y -= (a / b) * x;
	// x -= (a / b) * x;
	return d;
}

i64 gcd (i64 a, i64 b) {
	if (not b) { return a; }
	return gcd (b, a % b);
}

inline i64 lcm (i64 a, i64 b) { return a / gcd (a, b) * b; }

inline bool merge (i64& m1, i64& a1, i64 m2, i64 a2) {
	if (m1 < m2) { std::swap (m1, m2); std::swap (a1, a2); }
	i64 tot = 0;
	while (a1 % m2 != a2) {
		a1 += m1;
		tot ++; if (tot > m2) { return false; }
	} 
	m1 = lcm (m1, m2);
	a1 %= m1;
	return true;
}

i64 mul (i64 a, i64 b, i64 mod) {
	i64 res = 0;
	i64 base = a % mod;
	while (b) {
		if (b & 1) { res += base; res %= mod; }
		base += base; base %= mod; b >>= 1;
	}
	return res;
}

int n, m;
i64 a[maxn], p[maxn], c[maxn];
i64 reward[maxn];
i64 A[maxn], M[maxn];

inline bool solve_sub1 () {
	bool flag = true;
	rep (i, 1, n) { flag &= (p[i] == 1); }
	if (not flag) { return false; }
	
	i64 res = 0;
	rep (i, 1, n) {
		res = std::max (res, (a[i] / c[i]) + (a[i] % c[i] != 0));
	}
	std::cout << res << "\n";
	return true;
}

inline void solve () {
	std::multiset <i64> s;
	std::cin >> n >> m;
	rep (i, 1, n) { std::cin >> a[i]; }
	rep (i, 1, n) { std::cin >> p[i]; }
	rep (i, 1, n) { std::cin >> reward[i]; }

	rep (i, 1, m) {
		i64 x; std::cin >> x;
		s.insert (x);
	}	

	rep (i, 1, n) {
		auto it = s.upper_bound (a[i]);
		if (it != s.begin ()) { it = std::prev (it); }
		c[i] = (*it);
		s.erase (it); s.insert (reward[i]);
	}

	if (solve_sub1 ()) { return; }
	
	rep (i, 1, n) {
		a[i] %= p[i]; c[i] %= p[i];
		if (a[i] == 0 and c[i] == 0) { M[i] = 1; A[i] = 0; continue; }
		if (a[i] != 0 and c[i] == 0) { std::cout << "-1\n"; return; }

		i64 x, y; 
		i64 d = exgcd (c[i], p[i], x, y);

		assert (c[i] * x + p[i] * y == d);

		if (a[i] % d) { std::cout << "-1\n"; return; }

		M[i] = p[i] / d;
		x = ((x % M[i]) + M[i]) % M[i];
		A[i] = mul (x, a[i] / d, M[i]);
	}

	i64 currM = M[1], currA = A[1];
	rep (i, 2, n) {
		if (not merge (currM, currA, M[i], A[i])) { std::cout << "-1\n"; return; }
	}

	std::cout << currA << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	

	int T; std::cin >> T;

	while (T--) { solve (); }

	return 0;
}
