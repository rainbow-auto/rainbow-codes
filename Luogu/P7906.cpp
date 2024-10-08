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

const int maxn = 200005;
const int maxq = 1000005;
const int maxB = 666;

int n, q, X;
int a[maxn];

int belong[maxn];
void blocking() {
	int B = sqrt(n);
	rep (i, 1, n) belong[i] = i / B + 1;
}

struct Query {
	int l, r;
	int id;
	
	friend bool operator < (Query a, Query b) {
		if (belong[a.l] ^ belong[b.l]) return belong[a.l] < belong[b.l];
		if (belong[a.l] & 1) return a.r < b.r;
		return a.r > b.r;
	}
} qs[maxq];

i64 qans[maxq];
i64 ans[maxq];

struct Task {
	int qid;
	int l, r;

	i64 op;
};
std::vector<Task> tsks[maxn];

struct DS {
	i64 c1[1 << 9 | 5], c2[1 << 9 | 5][1 << 9 | 5];
	int mask;
	DS() { mask = (1 << 9) - 1; clear(); }

	void ins(int x) {
		rep (S, 0, (1 << 9) - 1) c1[S] += (((x >> 9) ^ S) < (X >> 9));
		rep (S, 0, (1 << 9) - 1) c2[x >> 9][S] += (((x & mask) ^ S) <= (X & mask));
	}

	i64 qry(int x) {
		return c1[x >> 9] + c2[(x ^ X) >> 9][x & mask];
	}

	void clear() { std::memset(c1, 0, sizeof c1); std::memset(c2, 0, sizeof c2); }
} ds;

i64 pre[maxn][2]; 

void init_pre() {
	rep (i, 1, n) {
		pre[i][0] = ds.qry(a[i]);
		ds.ins(a[i]);
		pre[i][1] = ds.qry(a[i]);
	}
	ds.clear();
}

void solve() {
	std::cin >> n >> X;
	rep (i, 1, n) std::cin >> a[i];

	std::cin >> q;
	rep (i, 1, q) {
		std::cin >> qs[i].l >> qs[i].r;
		qs[i].id = i;
	}

	blocking();
	std::sort(qs + 1, qs + q + 1);

	init_pre();

	int l = 1, r = 0;
	rep (i, 1, q) {
		auto qcur = qs[i];

		if (l > qcur.l) tsks[r].push_back(Task { i, qcur.l, l - 1, 1 });
		while (l > qcur.l) {
			qans[i] -= pre[--l][1];
		}

		if (r < qcur.r) tsks[l - 1].push_back(Task { i, r + 1, qcur.r, -1 });
		while (r < qcur.r) {
			qans[i] += pre[++r][0];
		}

		if (l < qcur.l) tsks[r].push_back(Task { i, l, qcur.l - 1, -1 });
		while (l < qcur.l) {
			qans[i] += pre[l++][1];
		}

		if (r > qcur.r) tsks[l - 1].push_back(Task { i, qcur.r + 1, r, 1 });
		while (r > qcur.r) {
			qans[i] -= pre[r--][0];
		}
	}

	rep (p, 1, n) {
		ds.ins(a[p]);

		for (auto cur : tsks[p]) {
			rep (i, cur.l, cur.r) {
				qans[cur.qid] += cur.op * ds.qry(a[i]);
			}
		}
	}

	rep (i, 2, q) qans[i] += qans[i - 1];
	rep (i, 1, q) ans[qs[i].id] = qans[i];

	rep (i, 1, q) std::cout << ans[i] << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}

/*
ins 11
ins 4
ins 5
ins 1
ins 4
ins 1
ins 9
ins 1
ins 9
ins 8
qry 11 4
qry 4 3
qry 5 6
qry 1 4
qry 4 3
qry 1 4
qry 9 4
ins 10
*/