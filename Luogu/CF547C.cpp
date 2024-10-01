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

const int maxn = 500005;

int n, q;

i64 S[maxn], sum;
int a[maxn], mx;

int cnt[maxn];

std::bitset<maxn> e;

std::bitset<maxn> np;
std::vector<int> ps;

i64 choose2(i64 x) {
	return x * (x - 1) / 2;
}

i64 mu[maxn];
void sieve(int R) {
	mu[1] = 1;
	rep (i, 2, R) {
		if (not np[i]) { ps.push_back(i); mu[i] = -1; }

		for (auto p : ps) {
			if (i * p > R) break;
			np.set(i * p);
			mu[i * p] = mu[i] * -1;
			if (i % p == 0) { mu[i * p] = 0; break; }
		}
	}
}

void modify(int x, int val) {
	cnt[x] += val;
	
	auto wrk = [&](int d) -> void {
		sum += mu[d] * (choose2(S[d] + val) - choose2(S[d]));
		S[d] += val;
	};

	for (int d = 1; d * d <= x; d ++) {
		if (x % d) continue;
		wrk(d);
		if (d == x / d) continue;
		wrk(x / d);
	}
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) {
	 	std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}

	sieve(mx);

	while (q--) {
		int i; std::cin >> i;
		modify(a[i], e[i] ? -1 : 1);
		e.flip(i);

		std::cout << sum << "\n";
	}
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
