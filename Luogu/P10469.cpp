#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

int n;
std::string s;

int sa[maxn];

u64 pw[maxn];
u64 pre[maxn];
constexpr int base = 233;
inline void init() {
	pw[0] = 1; rep (i, 1, n) pw[i] = pw[i - 1] * base;
	rep (i, 1, n) pre[i] = pre[i - 1] * base + s[i];
}

inline u64 get(int l, int r) {
	return pre[r] - pre[l - 1] * pw[r - l + 1];
}

inline int lcp(int i, int j) {
	int len = n - std::max(i, j) + 1;
	int res = 0;
	int l = 0, r = len;
	
	while (l <= r) {
		int mid = (l + r) >> 1;

		if (not mid or get(i, i + mid - 1) == get(j, j + mid - 1)) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return res;
}

inline bool comp(int i, int j) {
	int len = n - std::max(i, j) + 1;
	int x = lcp(i, j);
	if (x == len) return i > j;
	return s[i + x] < s[j + x];
}

void solve() {
	std::cin >> s; n = s.length();
	s = " " + s;

	init();

	rep (i, 1, n) sa[i] = i;
	std::sort(sa + 1, sa + n + 1, comp);

	rep (i, 1, n) std::cout << sa[i] - 1 << " "; std::cout << "\n";
	std::cout << "0 "; rep (i, 2, n) std::cout << lcp(sa[i], sa[i - 1]) << " ";
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
