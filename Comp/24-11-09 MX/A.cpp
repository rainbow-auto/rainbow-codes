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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

// #define MultiTask lovely_fairytale

const int maxn = 400005;
const i64 mod = 1e9 + 7;


int n, q;
i64 m;
bool a[maxn];
std::vector<int> ps;

inline int get(i64 pos) {
	return (pos - 1) % n + 1;
}

namespace Solution {
	std::pair<i64, int> nxt[maxn];
	inline void init() {
		rep (i, 1, n) a[n + i] = a[i];
		rep (i, 1, n << 1) if (a[i]) ps.push_back(i);

		if (m < n) {
			rep (i, 1, n) {
				auto it = std::upper_bound(ps.begin(), ps.end(), i + m);
				if (it == ps.begin() or *std::prev(it) <= i) nxt[i] = std::make_pair(1, (int) i + 1);
				else nxt[i] = std::make_pair(*std::prev(it) - i, *std::prev(it));
			}

			rep (i, 1, n) nxt[i].second = get(nxt[i].second);
		} else {
			rep (i, 1, n) {
				int R = get(i + m);
				i64 t = (m - R) / n;

				auto it1 = std::upper_bound(ps.begin(), ps.end(), R);
				if (it1 != ps.begin()) {
					nxt[i] = std::make_pair(1ll * n * t + *std::prev(it1), *std::prev(it1));
					continue;
				}

				auto it2 = std::lower_bound(ps.begin(), ps.end(), n);
				if (it2 != ps.begin()) {
					nxt[i] = std::make_pair(1ll * n * (t - 1) + *std::prev(it2), *std::prev(it2));
					continue;
				}

				nxt[i] = std::make_pair(1ll, (int) i + 1);
			}	

			rep (i, 1, n) nxt[i].second = get(nxt[i].second);
		}
	}


	int bel[maxn];
	std::pair<int, i64> to[maxn];

	std::pair<int, i64> O[maxn];
	int cnt;
	std::bitset<maxn> inO;

	inline void findO() {
		std::stack<std::pair<int, i64>> stk;
		std::bitset<maxn> vis;

		rep (i, 1, n) {
			if (bel[i]) continue;

			int now = i;
			while (true) {
				if (bel[now]) { // 旧环
					i64 cur = 0;
					int stp = 0;
					while (not stk.empty()) {
						auto top = stk.top(); stk.pop();
						cur += top.second; stp++;
						bel[top.first] = bel[now];
						to[top.first] = std::make_pair(stp, cur);
					}
					break;
				}
				if (vis[now]) { // 新环
					i64 sum = 0;
					int siz = 0;
					cnt++;
					while (not stk.empty()) {
						auto top = stk.top(); stk.pop();	
						sum += top.second;
						siz++;
						bel[top.first] = cnt;
						if (top.first == now) break;
						inO.set(top.first);
					}
					O[cnt] = std::make_pair(siz, sum);
					
					i64 cur = 0;
					int stp = 0;
					while (not stk.empty()) {
						auto top = stk.top();
						cur += top.second;
						bel[top.first] = cnt;
						to[top.first] = std::make_pair(stp, cur);
					}
					break;
				}

				vis.set(now);
				stk.push(std::make_pair(now, nxt[now].first));
				now = nxt[now].second;
			}
		}
	}

	inline i64 go(int now, i64 k) {
		i64 len = 0;
		while (k--) {
			(len += nxt[now].first) %= mod;
			now = nxt[now].second;
		}
		return len;	
	}

	inline i64 fastgo(int now, i64 k) {
		if (k <= to[now].first) {
			return go(now, k);
		} else {
			k -= to[now].first;
			i64 sum = to[now].second;
			(sum += k / O[bel[now]].first * O[bel[now]].second) %= mod;
			k %= O[bel[now]].first;
			return (sum + go(now, k)) % mod;
		}
	}

	inline void solve() {
		init();

		findO();

		while (q--) {
			i64 s, k; std::cin >> s >> k;
			(s += fastgo(get(s), k)) %= mod;
			std::cout << s << "\n";
		}
	}
}

namespace Task0 {
	inline void solve() {
		while(q--) {
			i64 s, k; std::cin >> s >> k;
			std::cout << (s + k) % mod << "\n";
		}
	}
}

void solve() {
	std::cin >> n >> m >> q;

	i64 flg1 = true;
	i64 flg0 = true;
	rep (i, 1, n) {
		char ch; std::cin >> ch;
		a[i] = ch - '0';
		flg0 &= (a[i] == 0);
		flg1 &= (a[i] == 1);
	}

	if (flg0 or flg1) return Task0::solve(), void(0);
	Task1::solve();
	Solution::solve();
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
