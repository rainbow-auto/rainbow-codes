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
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 300005;
constexpr int maxB = 605;

int n, q;

i64 a[maxn];

std::vector<std::pair<i64, int>> nums[maxB];
int L[maxB], R[maxB];
int bel[maxn], tot;

i64 tag[maxB];
i64 suf[maxB][maxB];

inline void init() {
	int B = std::sqrt(n);
	rep (i, 1, n) {
		bel[i] = (i / B) + 1;
		if (not L[bel[i]]) L[i] = i;
		R[bel[i]] = i;
		nums[bel[i]].push_back({a[i], i});
	}	

	tot = bel[n];
	rep (i, 1, tot) std::sort(nums[i].begin(), nums.end());
	rep (b, 1, tot) {
		suf[b][nums[b].size()] = 0;
		per (i, nums[b].size() - 1, 0) suf[b][i] = suf[b][i + 1] + nums[i];
	}
}

inline void pushdown(int b) {
	rep (i, L[b], R[b]) {
		a[i] -= tag[b];
	}
	tag[b] = 0;
}

inline void rebuild(int b) {
	pushdown(b);
	nums.clear();
	rep (i, L[b], R[b]) nums.push_back(a[i]);
	std::sort(nums.begin(), nums.end());
}

inline i64 qry(int l, int r) {
	i64 res = 0;
	if (bel[l] == bel[r]) {
		pushdown(bel[l]);
		rep (i, l, r) res += std::max(a[i], 0);
		return res;
	}

	pushdown(bel[l]);
	rep (i, l, R[bel[l]]) res += std::max(a[i], 0);

	rep (i, bel[l] + 1, bel[r] - 1) {
		int pos = std::lower_bound(nums[i].begin(), nums[i].end(), tag[i]);
	}

	pushdown(bel[r]);
	rep (i, L[bel[r]], r) res += std::max(a[i], 0);
}

inline void mdf(int l, int r, i64 x) {
	i64 res = 0;
	if (bel[l] == bel[r]) {
		pushdown(bel[l]);
		rep (i, l, r) a[i] -= x;
		rebuild(bel[l]);
		return;
	}

	pushdown(bel[l]);
	rep (i, l, R[bel[l]]) a[i] -= x;
	rebuild(bel[l]);
	
	pushdown(bel[r]);
	rep (i, L[bel[r]], r) a[i] -= x;
	rebuild(bel[r]);

	rep (i, bel[l] + 1, bel[r] - 1) tag[i] += x;
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> a[i];

	init();

	while (q--) {
	
	}
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
