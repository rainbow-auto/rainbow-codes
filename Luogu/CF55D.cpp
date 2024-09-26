#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

const int maxn = 23;
const int MOD = 2520;

int a[maxn], len;

i64 gcd(i64 a, i64 b) {
	if (not b) return a;
	return gcd(b, a % b);
}

i64 lcm(i64 a, i64 b) {
	if (not a or not b) return a | b;
	return a / gcd(a, b) * b;
}

int d[MOD + 5];

i64 f[maxn][MOD + 5][55];
i64 dfs(int now, bool lim, int cur, int rst) {
	if (now <= 0) return rst % cur == 0 ? 1 : 0;

	i64 res = 0;
	if (not lim and ~f[now][rst][d[cur]]) return f[now][rst][d[cur]];

	rep (i, 0, (lim ? a[now] : 9)) {
		res += dfs(now - 1, lim and (i == a[now]), lcm(cur, i), (rst * 10 + i) % MOD);
	}

	if (not lim) f[now][rst][d[cur]] = res;
	return res;
}

i64 calc(u64 x) {
	len = 0;
	
	a[0] = -1;
	while(x) { 
		a[++len] = x % 10;
		x /= 10;
	}

	return dfs(len, true, 1, 0);
}

void init () {
	int tot = 0;
	rep (i, 1, MOD) if (MOD % i == 0) d[i] = ++tot;
}

void solve() {
	u64 l, r; std::cin >> l >> r;

	std::cout << calc(r) - calc(l - 1) << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	init();
	memset(f, -1, sizeof(f));
	while (_--) {
		solve();
	}

	return 0;
}
