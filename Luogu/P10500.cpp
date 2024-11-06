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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 100005;

i64 n;
int a[maxn];

bool b[maxn];
f64 A = 0, B = 0, C = 0;

inline i64 len(int l, int r) {
	return std::max(r - l + 1, 0);
}

bool pre[maxn];
int cnt[maxn][2];

inline void calc(f64 w) {
	rep (i, 1, n) pre[i] = (pre[i - 1] xor b[i]);
	cnt[0][pre[0]] = 1;
	rep (i, 1, n) rep (w, 0, 1) cnt[i][w] = cnt[i - 1][w] + (pre[i] == w); 

	i64 curA = 0, curB = 0, curC = 0;
	int lst[2] = { 0, -1 };
	rep (r, 1, n) {
		if (r != 1) {
		 	// l < r => l - 1 <= r - 2
			curA += cnt[r - 2][pre[r] ^ 1];
			curB += b[r] * len(lst[0] + 1, r - 1);
			
			if (b[r]) curC += len(1, r - 1);
			else if (~lst[1]) curC += len(1, lst[1]);
		} 
		lst[b[r]] = r;
	}

	curA *= 2; curB *= 2; curC *= 2;

	rep (i, 1, n) if (b[i]) curA++, curB++, curC++;

	A += 1.0 * curA / (n * n) * w; 
	B += 1.0 * curB / (n * n) * w;
	C += 1.0 * curC / (n * n) * w;
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	rep (w, 0, 30) {
		rep (i, 1, n) b[i] = (a[i] >> w) & 1;
		calc(1 << w);
	}

	std::printf("%.3lf %.3lf %.3lf\n", A, B, C);
}

bool MemED;
int main() {
	// fastread
	// lookMem	
	// TimeST = clock ();

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
