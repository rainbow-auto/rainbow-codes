#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

struct Tree {
	struct Node {
		int ls, rs;
		int key;
		i64 val, valTag;
		i64 cnt, cntTag;
		int id;
	} tr[maxn];

	int root, tot;

	inline int newNode (int val, int id) {
		tr[++tot] = Node { 0, 0, rng (), val, 0, 0, 0, id };
		return tot;
	}

	inline void apply (int now, int val, int cnt) {
		tr[now].val += val; tr[now].valTag += val;
		tr[now].cnt += cnt; tr[now].cntTag += cnt;
	}

	inline void pushDown (int now) {
		if (not tr[now].cntTag and not tr[now].valTag) { return; }
		if (tr[now].ls) { apply (tr[now].ls, tr[now].valTag, tr[now].cntTag); }
		if (tr[now].rs) { apply (tr[now].rs, tr[now].valTag, tr[now].cntTag); }
		tr[now].cntTag = tr[now].valTag = 0;
	}

	void split (int now, int val, int& x, int& y) {
		if (not now) { x = y = 0; return; }
	
		pushDown (now);
		if (tr[now].val <= val) {
			x = now;
			split (tr[now].rs, val, tr[now].rs, y);
		} else {
			y = now;
			split (tr[now].ls, val, x, tr[now].ls);
		}
	}

	int merge (int x, int y) {
		if (not x or not y) { return x | y; }
		pushDown (x); pushDown (y);
		if (tr[x].key > tr[y].key) {
			tr[x].rs = merge (tr[x].rs, y);
			return x;
		} else {
			tr[y].ls = merge (x, tr[y].ls);
			return y;
		}
	}

	inline void insert (int val, int id) {
		int x, y; split (root, val, x, y);
		root = merge (merge (x, newNode (val, id)), y);
	}

} tr;

int n, k;

struct Cloth {
	int c, q;

	friend bool operator < (Cloth a, Cloth b) {
		if (a.q != b.q) { return a.q > b.q; }
		else { return a.c < b.c; }
	}
};

std::vector <Cloth> clothes;

int ans[maxn];
void getans (int now) {
	if (not now) { return; }
	tr.pushDown (now);
	getans (tr.tr[now].ls);
	getans (tr.tr[now].rs);
	
	ans[tr.tr[now].id] = tr.tr[now].cnt;
}

void dfs (int now, int& rt) { // insert now to rt
	if (not now) { return; }
	tr.pushDown (now);
	dfs (tr.tr[now].ls, rt); 
	dfs (tr.tr[now].rs, rt);	

	tr.tr[now].ls = tr.tr[now].rs = 0;
	int x, y; tr.split (rt, tr.tr[now].val, x, y);
	rt = tr.merge (tr.merge (x, now), y);
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;
	rep (i, 1, n) { int c, q; std::cin >> c >> q; clothes.push_back (Cloth { c, q }); }
	std::sort (clothes.begin (), clothes.end ());

	std::cin >> k;
	rep (i, 1, k) { int x; std::cin >> x; tr.insert (x, i); }

	for (auto cloth : clothes) {
		int x, y, z;
		tr.split (tr.root, cloth.c - 1, x, y);
		tr.split (y, (cloth.c << 1), y, z);

		if (y) { tr.apply (y, -cloth.c, 1); }
		if (z) { tr.apply (z, -cloth.c, 1); }
		dfs (y, x); // insert y to x

		tr.root = tr.merge (x, z);
	}

	getans (tr.root);
	rep (i, 1, k) { std::cout << ans[i] << " "; }

	return 0;
}
