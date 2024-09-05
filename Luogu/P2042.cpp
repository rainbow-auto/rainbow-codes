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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 500005;

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

struct Node {
	int ls, rs;
	int key;
	int siz;

	int val;
	int mx_pre, mx_suf, mx_sum;
	int sum;
	int cov_tag; bool cov;
	bool rev_tag;
} tr[maxn];

int root;

int tot;
std::queue <int> bin;

inline void pushUp (int now) {
	tr[now].siz = tr[tr[now].ls].siz + 1 + tr[tr[now].rs].siz;
	tr[now].sum = tr[tr[now].ls].sum + tr[now].val + tr[tr[now].rs].sum;
	tr[now].mx_pre = std::max ({ tr[tr[now].ls].mx_pre, tr[tr[now].ls].sum + tr[now].val + tr[tr[now].rs].mx_pre, 0 });	
	tr[now].mx_suf = std::max ({ tr[tr[now].rs].mx_suf, tr[tr[now].rs].sum + tr[now].val + tr[tr[now].ls].mx_suf, 0 });	
	tr[now].mx_sum = std::max (tr[now].val, tr[tr[now].ls].mx_suf + tr[now].val + tr[tr[now].rs].mx_pre);
	if (tr[now].ls) { tr[now].mx_sum = std::max (tr[now].mx_sum, tr[tr[now].ls].mx_sum); }
	if (tr[now].rs) { tr[now].mx_sum = std::max (tr[now].mx_sum, tr[tr[now].rs].mx_sum); }
}

inline int newNode (int val) {
	int now;
	if (not bin.empty ()) {
		now = bin.front (); bin.pop ();
	} else {
		now = ++tot;
	}
	tr[now].ls = tr[now].rs = 0;
	tr[now].siz = 1;
	tr[now].key = rng ();
	tr[now].val = tr[now].sum = tr[now].mx_sum = val;
	tr[now].mx_pre = tr[now].mx_suf = std::max (0, val);
	tr[now].cov = tr[now].cov_tag = tr[now].rev_tag = false;
	return now;
}

void delTree (int now) {
	if (not now) { return; }
	bin.push (now);
	delTree (tr[now].ls); delTree (tr[now].rs);
}

inline void rev (int now) {
	tr[now].rev_tag ^= 1;
	std::swap (tr[now].ls, tr[now].rs);
	std::swap (tr[now].mx_pre, tr[now].mx_suf);
}

inline void cov (int now, int c) {
	tr[now].cov = true; tr[now].cov_tag = c;
	tr[now].val = c;
	tr[now].sum = tr[now].siz * c;
	tr[now].mx_pre = std::max (0, tr[now].sum);
	tr[now].mx_suf = std::max (0, tr[now].sum);
	tr[now].mx_sum = std::max (c, tr[now].sum);
}

inline void pushDown (int now) {
	if (not now) { return; }

	if (tr[now].rev_tag) {
		if (tr[now].ls) { rev (tr[now].ls); }
		if (tr[now].rs) { rev (tr[now].rs); }
		tr[now].rev_tag = false;
	}
	if (tr[now].cov) {
		if (tr[now].ls) { cov (tr[now].ls, tr[now].cov_tag); }
		if (tr[now].rs) { cov (tr[now].rs, tr[now].cov_tag); }
		tr[now].cov = false; tr[now].cov_tag = 0;
	}
}

void split (int now, int siz, int& x, int& y) {
	if (not now) { x = y = 0; return; }
	
	pushDown (now);
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
	if (x) { pushDown (x); }
	if (y) { pushDown (y); }
	if (not x or not y) { return x | y; }

	if (tr[x].key > tr[y].key) {
		pushDown (x);
		tr[x].rs = merge (tr[x].rs, y);
		pushUp (x);
		return x;
	} else {
		pushDown (y);
		tr[y].ls = merge (x, tr[y].ls);
		pushUp (y);
		return y;
	}
}

int nums[maxn];
int build (int l, int r) {
	if (l == r) { return newNode (nums[l]); }
	int mid = (l + r) >> 1;
	return merge (build (l, mid), build (mid + 1, r));
}

inline void Insert (int pos, int len) {
	int x, y; split (root, pos, x, y);
	root = merge (merge (x, build (1, len)), y);
}

inline void Delete (int l, int r) {
	int x, y, z;
	split (root, r, x, z);
	split (x, l - 1, x, y);
	
	delTree (y);

	root = merge (x, z);
}

inline void MakeSame (int l, int r, int c) {
	int x, y, z;
	split (root, r, x, z);
	split (x, l - 1, x, y);

	cov (y, c);

	root = merge (merge (x, y), z);
}

inline void Reverse (int l, int r) {
	int x, y, z;
	split (root, r, x, z);
	split (x, l - 1, x, y);

	rev (y);

	root = merge (merge (x, y), z);
}

inline int GetSum (int l, int r) {
	int x, y, z;
	split (root, r, x, z);
	split (x, l - 1, x, y);

	int res = tr[y].sum;
	
	root = merge (merge (x, y), z);

	return res;
}

inline int MaxSum () {
	return tr[root].mx_sum;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int n, q; std::cin >> n >> q;

	rep (i, 1, n) { std::cin >> nums[i]; }
	Insert (0, n);

	while (q--) {
		std::string op; std::cin >> op;
		if (op == "INSERT") {
			int pos; std::cin >> pos;
			int len; std::cin >> len;
			rep (i, 1, len) { std::cin >> nums[i]; }
			Insert (pos, len);
		} else if (op == "DELETE") {
			int pos; std::cin >> pos;
			int len; std::cin >> len;
			Delete (pos, pos + len - 1);
		} else if (op == "MAKE-SAME") {
			int l; std::cin >> l;
			int len; std::cin >> len;
			int r = l + len - 1;
			int c; std::cin >> c;
			MakeSame (l, r, c);	
		} else if (op == "REVERSE") {
			int l; std::cin >> l;
			int len; std::cin >> len;
			int r = l + len - 1;
			Reverse (l, r);
		} else if (op == "GET-SUM") {
			int l; std::cin >> l;
			int len; std::cin >> len;
			int r = l + len - 1;
			std::cout << GetSum (l, r) << "\n";
		} else if (op == "MAX-SUM") {
			std::cout << MaxSum () << "\n";
		}
	}

	return 0;
}
