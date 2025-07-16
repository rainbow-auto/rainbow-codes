/*
终于懂了！！！！！！

调了一万年。

只能静态查错。

这我调牛魔啊。
*/

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

constexpr int maxn = 300005;
constexpr i64 mod = 998244353;

int n;

i64 p[maxn];

std::vector<i64> nums;

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) { return ksm(x, mod - 2); }

int ch[maxn][3], siz[maxn];

int rt[maxn], tot;

struct Node {
	int ls, rs;
	i64 sum;
	i64 tag;
} tr[maxn << 5];

inline int create() {
	tr[++tot] = Node { 0, 0, 0, 1 };
	return tot;
}

inline void pushup(int now) {
	tr[now].sum = (tr[tr[now].ls].sum + tr[tr[now].rs].sum) % mod;
}

inline void apply(int now, i64 v) {
	tr[now].sum = 1ll * tr[now].sum * v % mod;
	tr[now].tag = 1ll * tr[now].tag * v % mod;
}

inline void pushdown(int now) {
	if (tr[now].tag == 1) return;
	if (tr[now].ls) apply(tr[now].ls, tr[now].tag);
	if (tr[now].rs) apply(tr[now].rs, tr[now].tag);
	tr[now].tag = 1;
}

void mdf(int &now, int l, int r, int pos, int v) {
	if (not now) now = create();
	if (l == r) return tr[now].sum = v, void(0);
	pushdown(now);
	int mid = (l + r) >> 1;
	if (pos <= mid) mdf(tr[now].ls, l, mid, pos, v);
	else mdf(tr[now].rs, mid + 1, r, pos, v);
	pushup(now);
}

int mrg(int lnow, int rnow, int lp, int rp, int ls, int rs, const i64 p) {
	// db << "mrg " << lnow << " " << rnow << "\n";

	if (not lnow and not rnow) return 0;
	pushdown(lnow);
	pushdown(rnow);

	int now = create();
	if (not lnow) {
		tr[now] = tr[rnow];
		apply(now, 1ll * (1ll * p * lp % mod + 1ll * (mod + 1ll - p) * ls % mod) % mod);
		return now;
	}

	if (not rnow) {
		tr[now] = tr[lnow];
		apply(now, 1ll * (1ll * p * rp % mod + 1ll * (mod + 1ll - p) * rs % mod) % mod);
		return now;
	}

	tr[now].ls = mrg(tr[lnow].ls, tr[rnow].ls, lp, rp, (ls + tr[tr[lnow].rs].sum) % mod, (rs + tr[tr[rnow].rs].sum) % mod, p);
	tr[now].rs = mrg(tr[lnow].rs, tr[rnow].rs, (lp + tr[tr[lnow].ls].sum) % mod, (rp + tr[tr[rnow].ls].sum) % mod, ls, rs, p);
	pushup(now);

	return now;
} 

void dfs(int now) {
	if (not siz[now]) {
		mdf(rt[now], 1, n, p[now], 1);
		return;
	}

	rep (i, 1, siz[now]) {
		int t = ch[now][i];
		dfs(t);
		if (not rt[now]) {
			rt[now] = rt[t];
		} else {
			rt[now] = mrg(rt[now], rt[t], 0, 0, 0, 0, p[now]);
		}
	}
}

i64 ans;
void qry(int now, int l, int r) {
	// db << now << " " << l << " " << r << "\n";
	if (not now) return;
	if (l == r) {
		// db << nums[l] << " " << tr[now].sum << " " << "\n";
		(ans += 1ll * nums[l] * l % mod * tr[now].sum % mod * tr[now].sum % mod) %= mod;
		return;
	}

	pushdown(now);

	int mid = (l + r) >> 1;
	qry(tr[now].ls, l, mid);
	qry(tr[now].rs, mid + 1, r);
}

void solve() {
	std::cin >> n;

	rep (i, 1, n) {
		int f; std::cin >> f;
		ch[f][++siz[f]] = i;
	}

	i64 inv10000 = inv(10000);
	rep (i, 1, n) {
		std::cin >> p[i];
		if (siz[i]) p[i] = 1ll * p[i] * inv10000 % mod;
		else nums.push_back(p[i]);
	}

	nums.push_back(0); // 0
	std::sort(nums.begin(), nums.end());
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
	rep (i, 1, n) if (not siz[i]) p[i] = std::lower_bound(nums.begin(), nums.end(), p[i]) - nums.begin();

	dfs(1);

	qry(rt[1], 1, n);

	std::cout << ans << "\n";
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
