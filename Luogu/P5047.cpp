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

const int maxn = 100005;
const int maxB = 333;

int n, q;
int a[maxn];

int mx;
void lsh() {
	std::vector<int> vals;
	rep (i, 1, n) vals.push_back(a[i]);
	std::sort(vals.begin(), vals.end());
	vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
	rep (i, 1, n) a[i] = std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
	mx = vals.size();
}

namespace valBlocking {
	int belong[maxn], L[maxB], R[maxB], tot;
	i64 pre[maxn], tag[maxB];

	void blocking() {
		memset(L, 0x3f, sizeof L);
		int B = (int) sqrt(mx) + 1;
		rep (i, 1, mx) {
			belong[i] = i / B + 1;
			L[belong[i]] = std::min(L[belong[i]], (int) i);
			R[belong[i]] = i;
		}
		tot = belong[mx];
	}

	void pushDown(int id) {
		if (not tag[id]) return;
		rep (i, L[id], R[id]) pre[i] += tag[id];
		tag[id] = 0;
	}

	void modify(int pos, int val) {
		int bl = belong[pos];
		rep (i, bl + 1, tot) tag[i] += val;
		pushDown(bl);
		rep (i, pos, R[bl]) pre[i] += val;
	}

	i64 query(int pos) {
		return tag[belong[pos]] + pre[pos];
	}
}

namespace idBlocking {	
	int B;
	int belong[maxn];

	void blocking() {
		B = sqrt(n);
		rep (i, 1, n) belong[i] = int (i / B) + 1;
	}
}

struct Query {
	int l, r;
	int id;
	friend bool operator < (Query a, Query b) {
		if (idBlocking::belong[a.l] ^ idBlocking::belong[b.l]) return a.l < b.l;
		if (idBlocking::belong[a.l] & 1) return a.r < b.r;
		return a.r > b.r;
	}
} qs[maxn];

i64 qans[maxn];
i64 ans[maxn];

struct Task {
	int id;
	i64 c; // 系数
	int l, r;
};
std::vector<Task> tsks[maxn][2];

struct FenwickTree {
	i64 tr[maxn];
	int lowbit(int x) { return x & (-x); }

	i64 query(int pos) {
		i64 res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}

	void modify(int pos, i64 val) {
		for (int i = pos; i <= mx; i += lowbit(i)) tr[i] += val;
	}
} tr;

i64 s[2][maxn];
void init_s() {
	rep (i, 1, n) {
		tr.modify(a[i], 1);
		s[0][i] = tr.query(a[i] - 1);
		s[1][i] = i - tr.query(a[i]);
	}
}

void solve() {
	std::cin >> n >> q;
	
	rep (i, 1, n) std::cin >> a[i];

	lsh();

	init_s();
	valBlocking::blocking();

	rep (i, 1, q) {
		int l, r; std::cin >> l >> r;
		qs[i] = Query { l, r, i };
	}

	idBlocking::blocking();
	std::sort(qs + 1, qs + q + 1);

	int l = 1, r = 0;
	rep (i, 1, q) {
		auto qcur = qs[i];

		// add l
		if (l > qcur.l) tsks[r][0].push_back(Task { i, 1, qcur.l, l - 1 });
		while (l > qcur.l) qans[i] -= s[0][--l];

		// add r		
		if (r < qcur.r) tsks[l - 1][1].push_back(Task { i, -1, r + 1, qcur.r });
		while (r < qcur.r) qans[i] += s[1][++r];

		// del l
		if (l < qcur.l) tsks[r][0].push_back(Task { i, -1, l, qcur.l - 1 });
		while (l < qcur.l) qans[i] += s[0][l++];
		
		// del r
		if (r > qcur.r) tsks[l - 1][1].push_back(Task { i, 1, qcur.r + 1, r });
		while (r > qcur.r) qans[i] -= s[1][r--];
	}

	rep (i, 1, n) {
		valBlocking::modify(a[i], 1);

		for (auto t : tsks[i][0]) {
			rep (j, t.l, t.r) qans[t.id] += t.c * valBlocking::query(a[j] - 1);
		}

		for (auto t : tsks[i][1]) {
			rep (j, t.l, t.r) qans[t.id] += t.c * (i - valBlocking::query(a[j]));
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
