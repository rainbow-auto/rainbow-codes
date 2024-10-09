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

const int maxn = 100005;

int n, L;
i64 a[maxn];

i64 sum[maxn], pre[maxn];
inline bool chk(i64 val) {
	rep (i, 1, n) sum[i] = sum[i - 1] + (a[i] - val);
	rep (i, 1, n) pre[i] = std::min(pre[i - 1], sum[i]);

	i64 mx; std::memset(&mx, 0x3f, sizeof(mx)); mx *= -1ll;
	rep (i, L, n) mx = std::max(mx, sum[i] - pre[i - L]);

	return mx >= 0;
}

void solve() {
	std::cin >> n >> L;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) a[i] *= 1000;

	i64 res = 0;
	i64 l = 1, r = 1e13;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk(mid)) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}

	std::cout << res << "\n";
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
