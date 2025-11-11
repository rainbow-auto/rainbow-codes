#include<bits/stdc++.h>
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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 400005;

int n;
i64 a[maxn];
i64 len[maxn];
i64 pre[maxn], suf[maxn];
i64 sum[maxn];

inline i64 qry(int l, int r) {
	if (l == 1) return sum[r];
	if (l <= r) return sum[r] - sum[l - 2];
	return 0;
}

void solve() {
	int n; std::cin >> n;	
	rep (i, 1, (n << 1)) {
		std::cin >> a[i];
		len[i - 1] = a[i] - a[i - 1];
	}

	pre[0] = 0; rep (i, 1, (n << 1) - 1) pre[i] = pre[i - 1] + std::min(i, (n << 1) - i) * len[i];
	suf[(n << 1)] = 0; per (i, (n << 1) - 1, 1) suf[i] = suf[i + 1] + std::min(i, (n << 1) - i) * len[i];

	sum[0] = 0; sum[1] = len[1];
	
	rep (i, 2, (n << 1) - 1) sum[i] = sum[i - 2] + len[i];

	rep (k, 1, n - 1) {
		i64 res = pre[k] + suf[(n << 1) - k];
		res += qry(k + 2, (n << 1) - k - 2) * k;
		res += qry(k + 1, (n << 1) - k - 1) * (k - 1);
		std::cout << res << " ";
	}

	std::cout << pre[(n << 1) - 1] << "\n";
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
