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
// #define MultiTask lovely_fairytale

const int maxn = 2000005;

i64 L, R;

std::bitset<maxn> np;
std::vector<i64> ps;
inline void sieve(int R) {
	ps.clear(); np.reset();

	np.set(1);
	rep (i, 2, R) {
		if (not np[i]) ps.push_back(i);
		for (auto p : ps) {
			if (i * p > R) break;
			np.set(i * p);
			if (i % p == 0) break;
		}
	}
}

struct Answer {
	i64 a, b;
	friend bool operator < (Answer x, Answer y) {
		return (x.b - x.a) < (y.b - y.a);
	}
};

void solve() {
	std::bitset<maxn> mark;
	for (auto p : ps) {
		rep (i, L / p, R / p + 1) {
			i64 x = (i64) i * p;
			if (i != 1 and L <= x and x <= R) mark.set(x - L);
		}
	}

	if (L == 1) mark.set(0);

	i64 lst = -1;
	Answer mn = Answer { 0, (i64) 1e15 };
	Answer mx = Answer { (i64) 1e15, 0 };
	rep (i, L, R) {
		if (mark[i - L]) continue;

		if (~lst) {
			mn = std::min(mn, Answer { lst, i });
			mx = std::max(mx, Answer { lst, i });
		}
		lst = i;
	}

	if (mn.b == (i64) 1e15) std::cout << "There are no adjacent primes.\n";
	else std::cout << mn.a << "," << mn.b << " are closest, " << mx.a << "," << mx.b << " are most distant.\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	sieve(100000);
	while (std::cin >> L >> R) {
		solve();
	}

	return 0;
}
