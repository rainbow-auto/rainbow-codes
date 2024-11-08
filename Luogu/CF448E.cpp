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
bool MemST;

const int lim = 100000;

i64 d[1000005], dpos;

int tot;
void dfs (i64 now, i64 k) {
	if (tot >= lim) { return; }
	if (not k or now == 1) { printf ("%lld ", now); tot ++; return; }

	rep (i, 1, dpos) {
		if (now % d[i] == 0) { dfs (d[i], k - 1); }
		if (d[i] > now or tot > lim) { return; }
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	

	i64 n, k; std::cin >> n >> k;
	for (i64 i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			d[++dpos] = i;
			if (i != n / i) { d[++dpos] = n / i; }
		}
	}

	std::sort  (d + 1, d + dpos + 1);

	dfs (n, k);

	return 0;
}
