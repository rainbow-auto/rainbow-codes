#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

using i128 = __int128;
constexpr i128 $1 = 1;

i64 c, d;

inline i128 getL(i128 x) {
	i128 l = 1, r = 1e12;
	i128 res = 0;
	while (l <= r) {
		i128 mid = (l + r) >> 1;
		if (mid * mid >= x) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

inline i128 getR(i128 x) {
	i128 l = 1, r = 1e12;
	i128 res = 0;
	while (l <= r) {
		i128 mid = (l + r) >> 1;
		if (mid * mid <= x) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return res;
}

inline int getlen(i128 x) {
	int res = 0;
	while (x) {
		x /= 10;
		res ++;
	}
	return res;
}

inline i64 getXL(int len) {
	i64 l = 1, r = d;
	i64 res = 0;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (getlen(c + mid) >= len) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

inline i64 getXR(int len) {
	i64 l = 1, r = d;
	i64 res = 0;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (getlen(c + mid) <= len) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return res;
}

i64 pw10[15];

void solve() {
	std::cin >> c >> d;

	i64 ans = 0;

	int cl = getlen(c);
	int cr = getlen(c + d);

	i64 lst = 0;
	rep (len, cl, cr) {
		i64 l = lst + 1;
		i64 r = std::min(pw10[len] - 1 - c, d);
		lst = r;

		if (l > r) continue;
		if (getlen(c + r) != len) continue;

		i128 t = (pw10[len] + 1) * c;

		ans += getR(t + r) - getL(t + l) + 1;
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	pw10[0] = 1; rep (i, 1, 14) pw10[i] = pw10[i - 1] * 10ll;

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
