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

const int maxn = 1000005;
const i64 mod = 1e9 + 7;

i64 n;
i64 f[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;

	i64 sufsum = 0;
	f[n] = n;
	f[n - 1] = n * n % mod;
	per (i, n - 2, 1) {
		sufsum += f[i + 3]; sufsum %= mod;
		f[i] += f[i + 1]; f[i] %= mod;
		f[i] += (n - 1) * (n - 1) % mod; f[i] %= mod;
		f[i] += sufsum + (i + 1) % mod; f[i] %= mod; // (i + 1) 为 j > n 的 f[j] 的和 
	}

	std::cout << f[1] << "\n";

	return 0;
}
