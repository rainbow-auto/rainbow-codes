#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 2000005;

int n, m;
int ac, dr;
int a[maxn], d[maxn];
int v[maxn];

int vmx;

// struct Tree1 {
// 	struct Node {
// 		int sum;
// 	} tr[maxn << 2];

// 	inline void pushUp(int now) {
// 		tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
// 	}

// 	void mdf(int now, int l, int r, int pos, int v) {
// 		if (l == r) return tr[now].sum += v, void(0);
// 		int mid = (l + r) >> 1;
// 		if (pos <= mid) mdf(now << 1, l, mid, pos, v);
// 		else mdf(now << 1 | 1, mid + 1, r, pos, v);
// 		pushUp(now);
// 	}

// 	int qry(int now, int l, int r, int L, int R) {
// 		if (L > R) return 0;
// 		if (L <= l and r <= R) return tr[now].sum;
// 		int mid = (l + r) >> 1;
// 		if (R <= mid) return qry(now << 1, l, mid, L, R);
// 		if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
// 		return qry(now << 1, l, mid, L, R) + qry(now << 1 | 1, mid + 1, r, L, R);
// 	}
// } tr1;

struct Tree {
	struct Node {
		int mx;
		int tag;
		Node() {
			mx = 0;
			tag = 0;
		}
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].mx = std::max(tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	inline void apply(int now, int x) {
		tr[now].tag += x;
		tr[now].mx += x;
	}

	inline void pushDown(int now) {
		if (not tr[now].tag) return;
		apply(now << 1, tr[now].tag);
		apply(now << 1 | 1, tr[now].tag);
		tr[now].tag = 0;
	}

	void mdf(int now, int l, int r, int L, int R, int v) {
		if (L <= l and r <= R) return apply(now, v), void(0);
		pushDown(now);
		int mid = (l + r) >> 1;
		if (L <= mid) mdf(now << 1, l, mid, L, R, v);
		if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, v);
		pushUp(now);
	}

	int qry(int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) return tr[now].mx;
		pushDown(now);
		int mid = (l + r) >> 1;
		if (R <= mid) return qry(now << 1, l, mid, L, R);
		if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
		return std::max(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
	}
} tr;

// inline int qry1() {
// 	int res = 0;
// 	rep (mid, 0, vmx) {
// 		if (tr1.qry(1, 0, vmx, 0, mid - 1) >= mid) {
// 			// sum[0, mid - 1] - mid >= 0
// 			res = mid;
// 		} else {
// 			// first mid - sum[0, mid - 1] > 0; 
// 			break;
// 		}
// 	}
// 	return tr1.qry(1, 0, vmx, 0, res - 1);
// }

inline int qry() {
	int l = 0, r = vmx;
	int res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (tr.qry(1, 0, vmx, 0, mid) > 0) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	res--;
	return res - tr.qry(1, 0, vmx, res, res);
}

void solve() {
	std::cin >> ac >> dr;
	std::cin >> n;

	vmx = 0;
	rep (i, 1, n) {
		std::cin >> a[i];
		v[i] += std::max(a[i] - ac, 0);
	}
	rep (i, 1, n) {
		std::cin >> d[i];
		v[i] += std::max(d[i] - dr, 0);
		vmx = std::max(vmx, v[i]);
	}

	// assert(vmx < maxn);
	// dbg(vmx);

	// rep (i, 1, n) db << v[i] << " "; dbendl;

	std::priority_queue<int> q;
	rep (i, 1, n) q.push(-v[i]);

	// auto display = [&]() -> void {
	// 	rep (i, 0, vmx) db << tr.qry(1, 0, vmx, i, i) << " ";
	// 	dbendl;
	// };

	vmx = 2e6;

	int cur = 0;
	rep (i, 0, vmx) {
		while (not q.empty() and -q.top() < i) {
			cur++;
			q.pop();
		}
		tr.mdf(1, 0, vmx, i, i, i - cur);
	}

	// assert(n != 1);

	// display();

	// db << qry() << "\n";

	std::cin >> m;
	while (m--) {
		int k; std::cin >> k;
		tr.mdf(1, 0, vmx, v[k] + 1, vmx, 1);

		std::cin >> a[k] >> d[k];
		v[k] = std::max(a[k] - ac, 0) + std::max(d[k] - dr, 0);
		tr.mdf(1, 0, vmx, v[k] + 1, vmx, -1);
		
		std::cout << qry() << "\n";
	}
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
