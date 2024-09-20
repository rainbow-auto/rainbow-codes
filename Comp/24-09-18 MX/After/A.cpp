#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl() std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 1000005;
const i64 mod = 1e9 + 7;

int n;
int tp;

inline void solve () {
	std::cin >> n >> tp;
	std::set <int> s;
	rep (i, 1, n) { int x; std::cin >> x; s.insert (x); }

	std::vector <int> vec; 

	i64 ans_val = 0;
	rep (i, 1, n >> 1) {
		int x = *s.begin (); s.erase (x);
		int y = *s.rbegin (); s.erase (y);
		vec.push_back (x); vec.push_back (y);
	}

	rep (i, 1, vec.size () - 1) { ans_val += std::abs (vec[i] - vec[i - 1]); }
	ans_val += std::abs (vec.front () - vec.back ());

	std::cout << ans_val << " ";

	if (not tp) { return; }

	i64 fac = 1;
	rep (i, 1, n >> 1) { (fac *= i) %= mod; }

	i64 ans_cnt = 2ll * i64 ((n & 1) ? n : 1) % mod * fac % mod * fac % mod;
	
	std::cout << ans_cnt << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("sort.in", "r", stdin);
	freopen ("sort.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}
