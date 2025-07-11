#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale

constexpr int maxn = 5005;
constexpr int maxv = 1000005;

int n;

int a[maxn], mx;
i64 sum[maxv];

inline i64 qry(int l, int r) {
	if (r > mx) r = mx;
	if (l < 1) l = 1;
	if (l > r) return 0;
	
	return sum[r] - sum[l - 1];
}

void solve() {
	std::cin >> n;

	std::memset(sum, 0, sizeof sum);

	mx = 0;
	rep (i, 1, n) {
		std::cin >> a[i];
		sum[a[i]] ++;
		mx = std::max(mx, a[i]);
	}

	sum[0] = 0;
	rep (i, 1, mx) sum[i] += sum[i - 1];

	i64 ans = 0;
	rep (i, 1, n) {
		rep (j, i + 1, n) {
			int x = a[i], z = a[j];
			
			if (x > z) std::swap(x, z);

			int l = std::max((z - x), mx - (x + z)) + 1;
			int r = (x + z) - 1;
			i64 c = qry(l, r);

			if (l <= x and x <= r) c --;
			if (l <= z and z <= r) c --;

			ans += c;
		}
	}

	std::cout << ans / 3 << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
