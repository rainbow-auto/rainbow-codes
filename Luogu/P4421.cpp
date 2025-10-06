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

constexpr int maxn = 20005;
constexpr int maxL = 15;

int n;
std::string s[maxn];
int len[maxn];

constexpr u64 base = 233;
u64 pw[maxL];
u64 pre[maxn][maxL];

inline void init() {
	pw[0] = 1; rep (i, 1, 10) pw[i] = pw[i - 1] * base;

	rep (i, 1, n) {
		rep (j, 1, len[i]) {
			pre[i][j] = pre[i][j - 1] * base + s[i][j];
		}
	}
}

inline u64 get(int i, int l, int r) {
	return pre[i][r] - pre[i][l - 1] * pw[r - l + 1];
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> s[i];
		len[i] = s[i].size();
		s[i] = " " + s[i];
	}

	init();

	i64 res = 0;
	std::unordered_map<u64, int> cnt;
	rep (i, 1, n) cnt[pre[i][len[i]]]++;

	i64 ans = 0;
	rep (i, 1, n) {
		cnt[pre[i][len[i]]]--;

		std::unordered_set<u64> used;
		rep (l, 1, len[i]) rep (r, l, len[i]) {
			if (used.count(get(i, l, r))) continue;
			used.insert(get(i, l, r));
			ans += cnt[get(i, l, r)];
		}

		cnt[pre[i][len[i]]]++;
	}

	std::cout << ans << "\n";
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
