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
#define MultiTask lovely_fairytale

const int maxn = 1000005;

int n, m;
int a[maxn];

namespace Task1 {
	const int maxn = 23;
	int p[maxn];

	inline void solve() {
		int ans = 0;
		
		rep (i, 1, n) p[i] = i;
		
		do {
			std::vector<int> vec;
			std::bitset<maxn> del;

			rep (i, 1, n) {
				int cur = p[i];
				int pos = 0;
				
				rep (j, 1, n) {
					if (del[j]) continue;
					pos++;
					if (pos & 1) vec.push_back(a[j]);
				}
				del.set(cur);
			}


			if ((int) vec.size() < m) continue;
			
			std::sort(vec.begin(), vec.end());
			std::reverse(vec.begin(), vec.end());
			ans = std::max(ans, vec[m - 1]);
			
		} while (std::next_permutation(p + 1, p + n + 1));

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i];

	Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::freopen("card.in", "r", stdin);
	std::freopen("card.out", "w", stdout);

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
