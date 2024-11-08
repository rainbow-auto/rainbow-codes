#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 200005;
const int mod = 1e9 + 7;

int n;
i64 k1, k2;

i64 a[maxn];

struct Trie {
	struct Node {
		int ch[2];
		bool tag; // 全部置零
		int sum;
	} tr[maxn << 7];

	int tot, root;

	Trie () { tot = root = 1; }

	inline void apply (int now) {
		tr[now].sum = 0;
		tr[now].tag = true;
	}

	inline void pushDown (int now) {
		if (not tr[now].tag) { return; }

		if (tr[now].ch[0]) { apply (tr[now].ch[0]); }
		if (tr[now].ch[1]) { apply (tr[now].ch[1]); }
		tr[now].tag = false;
	}

	inline void insert (i64 id, int val) {
		if (not val) { return; }
	
		int now = root;
		per (i, 62, 0) {
			pushDown (now);
			tr[now].sum += val; tr[now].sum %= mod;
			bool curr = (id & (1ll << i));
			if (not tr[now].ch[curr]) { tr[now].ch[curr] = ++tot; }
			now = tr[now].ch[curr];
		}
		tr[now].sum += val; tr[now].sum %= mod;
	}

	inline int query (i64 id, i64 lim) {
		int now = root;
		int res = 0;
		per (i, 62, 0) {
			pushDown (now);
			bool currid = (id & (1ll << i));
			bool currlim = (lim & (1ll << i));
			if (currlim == 0) { res += tr[tr[now].ch[1 ^ currid]].sum; res %= mod; }
			if (tr[now].ch[currlim ^ currid]) { now = tr[now].ch[currlim ^ currid]; }
			else { return res; }
		}
		res += tr[now].sum; res %= mod;
		return res;
	}

} f, g;

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> k1 >> k2;
	rep (i, 1, n) { std::cin >> a[i]; }

	std::sort (a + 1, a + n + 1);

	// 只是用一种食材 : 正无穷
	f.insert ((1ll << 61), 1);
	g.insert ((1ll << 61), 1);

	rep (i, 2, n) {
		int fnxt = g.query (a[i], k1);	
		int gnxt = f.query (a[i], k2);

		if ((a[i] xor a[i - 1]) < k1) { f.apply (f.root); }
		if ((a[i] xor a[i - 1]) < k2) { g.apply (g.root); }

		f.insert (a[i - 1], fnxt);
		g.insert (a[i - 1], gnxt);
	}

	// 统计是否有可能有一个集合为空
	bool all1 = true;
	bool all2 = true;
	rep (i, 2, n) {
		if ((a[i] xor a[i - 1]) < k1) { all1 = false; }
		if ((a[i] xor a[i - 1]) < k2) { all2 = false; }
	}

	std::cout << ((f.tr[f.root].sum + g.tr[g.root].sum) % mod - all1 - all2 + mod) % mod << "\n";

	return 0;
}
