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

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 5000005;

struct Trie {
	int tr[maxn << 5][2], tot, root;

	int siz[maxn << 5];

	Trie () { tot = 0; root = ++tot; }

	inline void insert (i64 val) {
		int now = root; siz[now] ++;
		for (i64 i = 31; i >= 0; i--) {
			bool x = ((val >> i) & 1ll);

			if (not tr[now][x]) { tr[now][x] = ++tot; }
			now = tr[now][x];
			
			siz[now] ++;
		}
	}

	inline i64 query (i64 val, int rnk) {
		i64 res = 0;
		
		int now = root;
		for (i64 i = 31; i >= 0; i--) {
			bool x = ((val >> i) & 1ll);
			
			if (not tr[now][x ^ 1]) { now = tr[now][x]; continue; }

			if (rnk <= siz[tr[now][x ^ 1]]) {
				res |= 1ll << i;
				now = tr[now][x ^ 1];
			} else {
				rnk -= siz[tr[now][x ^ 1]];
				now = tr[now][x];
			}
		}

		return res;
	}
} trie;

int n, k;

struct Node {
	int id, rnk;
	i64 val;

	friend bool operator < (Node a, Node b) {
		return a.val < b.val; // priority_queue 反过来
	}
};

std::priority_queue <Node> q;

i64 sum[maxn];

int main () {
	fastread

	std::cin >> n >> k;

	sum[0] = 0;
	for (int i = 1; i <= n; i++) { 
		i64 val; std::cin >> val;
		sum[i] = sum[i - 1] xor val;
	}

	// 注意有 0 !!!
	for (int i = 0; i <= n; i++) { trie.insert (sum[i]); }

	for (int i = 0; i <= n; i++) {
		q.push (Node { i, 1, trie.query (sum[i], 1) });
	}

	i64 ans = 0;
	for (int i = 1; i <= (k << 1); i++) {
		Node t = q.top (); q.pop ();
		ans += t.val; 
		q.push (Node { t.id, t.rnk + 1, trie.query (sum[t.id], t.rnk + 1) });
	}

	ans >>= 1;

	std::cout << ans << "\n";
	
	return 0;
}
