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

const int maxn = 100005;

int n, m;
int b[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	n = 10000; m = 100;

	rep (i, 1, m) { b[i] = i; }

	std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());
	std::shuffle (b + 1, b + m + 1, rng);

	std::cout << n << " " << m << "\n";
	rep (i, 1, m) { std::cout << b[i] << " "; } std::cout << "\n";

	return 0;
}
