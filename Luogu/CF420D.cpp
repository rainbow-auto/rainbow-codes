#include <bits/stdc++.h>
#pragma GCC optimize(3)

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

const int maxn = 1000005;

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

struct Tree {
	struct Node {
		int ls, rs;
		int siz;
		int val; 
		int rnd;
	} tr[maxn];

	int tot, root;

	inline int newNode (int val) {
		tr[++tot] = Node { 0, 0, 1, val, rng () };
		return tot;
	}

	inline void pushUp (int now) { tr[now].siz = tr[tr[now].ls].siz + tr[tr[now].rs].siz + 1; }

	void split (int now, int siz, int& x, int& y) {
		if (not now) { x = y = 0; return; }
		if (tr[tr[now].ls].siz >= siz) {
			y = now;
			split (tr[now].ls, siz, x, tr[now].ls);
		} else {
			x = now;
			split (tr[now].rs, siz - tr[tr[now].ls].siz - 1, tr[now].rs, y);
		}
		pushUp (now);
	}

	int merge (int x, int y) {
		if (not x or not y) { return x | y; }
		if (tr[x].rnd > tr[y].rnd) {
			tr[x].rs = merge (tr[x].rs, y);
			pushUp (x);
			return x;
		} else {
			tr[y].ls = merge (x, tr[y].ls);
			pushUp (y);
			return y;
		}
	}

	inline void push_back (int x) {
		root = merge (root, newNode (x));
	}
} tr;

struct Operation {
	int pos, val;
} ops[maxn];

int n, m;
std::vector <int> unused;

void output (int now) {
	if (not now) { return; }
	output (tr.tr[now].ls);
	if (tr.tr[now].val == 0) {
		// assert (unused.size () != 0);
		// std::cout << (*unused.begin ()) << " ";
		printf ("%d ", unused.back ());
		unused.pop_back ();
	} else {
		// std::cout << tr.tr[now].val << " ";
		printf ("%d ", tr.tr[now].val);
	}
	output (tr.tr[now].rs);
}

std::bitset <maxn> vis;

inline int read () {
	char ch = getchar ();
	int res = 0;

	while (not isdigit (ch)) { ch = getchar (); }
	while (isdigit (ch)) { res = res * 10 + ch - '0'; ch = getchar (); }

	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	// std::cin >> n >> m;
	n = read (); m = read ();
	rep (i, 1, m) {
		// int pos, val; std::cin >> val >> pos;
		int val = read ();
		int pos = read ();
		ops[i] = Operation { pos, val };
	}
	
	rep (i, 1, n) { tr.push_back (0); }

	// output (tr.root);

	// std::cout << "\n";
	// std::cout << "\n";

	per (i, m, 1) {
		auto op = ops[i];

		int l, m, r;
		tr.split (tr.root, 1, l, m);
		tr.split (m, op.pos - 1, m, r);

		if (tr.tr[l].val != op.val) { 
			if (tr.tr[l].val) { std::cout << "-1\n"; return 0; }
			if (vis[op.val]) { std::cout << "-1\n"; return 0; }
		}

		tr.tr[l].val = op.val;
		tr.root = tr.merge (tr.merge (m, l), r);

		vis.set (op.val);
	}

	per (i, n, 1) { if (not vis[i]) { unused.push_back (i); } }

	output (tr.root);

	return 0;
}
