#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const i64 mod = 1e9 + 7;
const int maxn = 200005;

int n;
struct Range {
	int l, r;
	
	friend bool operator < (Range x, Range y) {
		return x.l < y.l;
	}
} a[maxn];

i64 f[maxn];

struct Fenwick {
	int siz;
	int tr[maxn];
	Fenwick (int _siz) { siz = _siz; memset (tr, 0, sizeof (tr)); }

	inline int lowbit (int x) { return x & (-x); }

	inline void add (int pos, int val) {
		for (int i = pos; i <= siz; i += lowbit (i)) { tr[i] += val; }
	}

	inline int query (int pos) {
		int res = 0;
		for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; }
		return res;
	}
};

inline i64 ksm (i64 a, i64 b) {
	i64 base = a % mod;
	i64 res = 1;
	while (b) {
		if (b & 1) { res *= base; res %= mod; }
		base *= base; base %= mod; b >>= 1;
	}
	return res;
}	

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n) { int l, r; std::cin >> l >> r; a[i] = Range { l, r }; }

	std::sort (a + 1, a + n + 1);

	Fenwick s (n << 1);

	rep (i, 1, n) {
		int cnt = s.query (a[i].l - 1);
		f[i] = (f[i - 1] * 2ll % mod + ksm (2, cnt)) % mod; 
		s.add (a[i].r, 1);
	}

	std::cout << f[n] << "\n";

	return 0;
}
