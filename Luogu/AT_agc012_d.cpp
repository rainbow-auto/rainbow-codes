#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 200005;
const i64 mod = 1e9 + 7;

int n, A, B;

int w[maxn], c[maxn];
int a[maxn];

int siz[maxn];

i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	a %= mod;
	while (b) {
		if (b & 1) (res *= a) %= mod;
		(a *= a) %= mod; b >>= 1;
	}
	return res;
}

i64 inv(i64 x) { return ksm(x, mod - 2); }

i64 fac[maxn], ifac[maxn];
void init(int R) {
	fac[0] = 1;
	rep (i, 1, R) (fac[i] = fac[i - 1] * i) %= mod;
	ifac[R] = inv(fac[R]);
	per (i, R - 1, 0) (ifac[i] = ifac[i + 1] * (i + 1)) %= mod;
}

i64 choose(int a, int b) {
	if (a < b) return 0;
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

void solve() {
	memset(a, 0x3f, sizeof a);

	std::cin >> n >> A >> B;
	rep (i, 1, n) {
		std::cin >> c[i] >> w[i];
		a[c[i]] = std::min(a[c[i]], w[i]);
	}

	std::pair<int, int> mn1 = std::make_pair(0x3f3f3f3f, 0);
	std::pair<int, int> mn2 = std::make_pair(0x3f3f3f3f, 0);

	rep (i, 1, n) {
		mn2 = std::min(mn2, std::make_pair(a[i], (int) i));
		if (mn2 < mn1) std::swap(mn2, mn1);
	}

	int w1, p1; std::tie(w1, p1) = mn1;
	int w2, p2; std::tie(w2, p2) = mn2;

	rep (i, 1, n) {
		if (w[i] + a[c[i]] <= A) w[i] = a[c[i]];

		if (c[i] == p1) {
			siz[c[i]] += w[i] + w2 <= B;
		} else {
			siz[c[i]] += w[i] + w1 <= B;
		}
	}

	i64 sum = 0;
	rep (i, 1, n) (sum += siz[i]) %= mod;
	
	init(n);

	i64 ans = fac[sum];
	rep (i, 1, n) (ans *= ifac[siz[i]]) %= mod;

	std::cout << ans << "\n";
}	

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
