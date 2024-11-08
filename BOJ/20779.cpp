#include <bits/stdc++.h>

#pragma GCC Optimize(2)

using i64 = long long;
using f64 = long double;

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

const int maxn = 5005;

int n, m;
int a[maxn];

const f64 eps = 1e-18;


template <typename val_t>
struct Vector {
	val_t vec[maxn];

	Vector (val_t x = 0) { 
		rep (i, 0, m) { vec[i] = x; }
	}

	val_t& operator[] (int i) { return vec[i]; }

	friend Vector operator * (Vector a, Vector b) { // (min, +)
		Vector res (1e18);
		rep (i, 0, m) {
			rep (j, 0, i) {
				res[i] = std::min (res[i], a[j] + b[i - j]);
			} 
		}

		return res;
	}
};

template <typename val_t>
inline Vector<val_t> ksm (Vector<val_t> a, i64 b) {
	Vector<val_t> res (0);
	Vector<val_t> base = a;

	while (b) {
		if (b & 1) { res = res * base; }
		base = base * base; b >>= 1;
	}

	return res;
}

void solve () {
	std::sort (a + 1, a + n + 1);

	Vector<f64> f;
	rep (i, 0, m) {
		f64 cnt = n - ((std::upper_bound (a + 1, a + n + 1, i) - a) - 1);
		f[i] = 1.0 * cnt / f64 (n);
	}

	f = ksm (f, n);

	std::cout << std::fixed << std::setprecision (19) << f[m] << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	

    // freopen ("monster.in", "r", stdin);
    // freopen ("monster.out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	solve ();

    return 0;
}
