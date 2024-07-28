#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 100005;

int n;
i64 a[maxn];

i64 pre[maxn];
i64 suf[maxn];

struct Trie {
	struct Node {
		int ch[2];
	} tr[maxn << 6];

	int tot, root;

	Trie () { tot = root = 1; }

	inline void ins (i64 x) {
		int now = root;
		for (int i = 40; i >= 0; i--) {
			bool nxt = (x & (1ll << i));

			if (not tr[now].ch[nxt]) { tr[now].ch[nxt] = ++tot; }
			now = tr[now].ch[nxt];
		}
	}		

	inline i64 query (i64 x) {
		i64 res = 0;
		
		int now = root;
		for (int i = 40; i >= 0; i--) {
			bool nxt = (x & (1ll << i));

			if (tr[now].ch[nxt ^ 1]) {
				res += (1ll << i);
				now = tr[now].ch[nxt ^ 1];
			} else {
				now = tr[now].ch[nxt];
			}
		}	

		return res;
	}
} tr;

int main () {
	fastread

	std::cin >> n;
	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] xor a[i]; }
	for (int i = n; i >= 1; i--) { suf[i] = suf[i + 1] xor a[i]; }

	i64 ans = 0;

	tr.ins (0);
	
	for (int i = 1; i <= n + 1; i++) {
		ans = std::max (ans, tr.query (suf[i]));
		tr.ins (pre[i]);	
	}

	std::cout << ans << "\n";

	return 0;
}
