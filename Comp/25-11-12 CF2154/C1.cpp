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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;
int n;
int a[maxn], b[maxn];


std::vector<int> ps[maxn];
std::bitset<maxn> vis;
inline void sieve(int N) {
	rep (i, 2, N) {
		if (not ps[i].empty()) continue;
		for (int j = i; j <= N; j += i) ps[j].push_back(i);
	}
} 

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) std::cin >> b[i];

	std::map<int, int> cnt;
	rep (i, 1, n) {
		for (auto p : ps[a[i]]) if (cnt[p]) return std::cout << "0\n", void(0);
		for (auto p : ps[a[i]]) cnt[p]++;
	}

	rep (i, 1, n) {
		for (auto p : ps[a[i]]) cnt[p]--;
		for (auto p : ps[a[i] + 1]) if (cnt[p]) return std::cout << "1\n", void(0);
		for (auto p : ps[a[i]]) cnt[p]++;
	}

	std::cout << "2\n";
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

	sieve(200001);

	while (_--) {
		solve();
	}

	return 0;
}
