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

const int maxn = 1005;
const i64 mod = 998244353;

int n, m;
int k;

i64 ksm(i64 a, i64 b) {
	i64 res = 1, base = a % mod;
	while (b) {
		if (b & 1) (res *= base) %= mod;
		(base *= base) %= mod; b >>= 1;
	}
	return res;
}

i64 inv(i64 x) { return ksm(x, mod - 2); }

i64 choose(int a, int b) {
	if (a < b) return 0;
	i64 ans = 1;
	per (i, a, a - b + 1) (ans *= i) %= mod;
	rep (i, 1, b) (ans *= inv(i)) %= mod;
	return ans;
}

int fa[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	fa[v] = u;
}

bool a[maxn][maxn]; // 横边
bool b[maxn][maxn]; // 竖边

bool get(int S, int x, int y) {
	int pos = 0;
	
	rep (i, 1, x) {
		bool flag = false;
		rep (j, 1, y + 1) {
			a[i][j] = !!(S & (1 << pos));
			pos ++;

			flag |= a[i][j];
		}
		if (not flag) return false;
	}

	rep (j, 1, y) {
		bool flag = false;
		rep (i, 1, x + 1) {
			b[i][j] = !!(S & (1 << pos));
			pos ++;
			
			flag |= b[i][j];
		}
		if (not flag) return false;
	}

	return true;
}

int id[maxn][maxn], tot;

int L[maxn], R[maxn], U[maxn], D[maxn];

bool chk(int S, int x, int y) {
	if (not get(S, x, y)) return false;

	tot = 0;
	rep (i, 1, x + 1) rep (j, 1, y + 1) id[i][j] = ++tot;
	rep (i, 1, tot) fa[i] = i;

	rep (i, 1, x + 1) {
		rep (j, 1, y + 1) {
			if (i != 1 and not a[i - 1][j]) merge(id[i][j], id[i - 1][j]);
			if (j != 1 and not b[i][j - 1]) merge(id[i][j], id[i][j - 1]);
		}
	}
	
	int cnt = 0;
	rep (i, 1, tot) cnt += find(i) == i;

	if (cnt != k) return false;

	// db << "------\n";
	// rep (i, 1, x + 1) {
	// 	rep (j, 1, y + 1) {
	// 		db << find(id[i][j]);
	// 		if (j != y + 1) db << (b[i][j] ? '|' : ' ');
	// 	}
	// 	dbendl;

	// 	if (i == x + 1) continue;

	// 	rep (j, 1, y + 1) {
	// 		db << (a[i][j] ? "- " : "  ");
	// 	}
	// 	dbendl;
	// }

	rep (i, 1, tot) {
		L[i] = U[i] = 0x3f3f3f3f;
		R[i] = D[i] = 0;
	}

	std::set<int> rts;
	rep (i, 1, x + 1) {
		rep (j, 1, y + 1) {
			int rt = find(id[i][j]);
			L[rt] = std::min(L[rt], (int) j);
			R[rt] = std::max(R[rt], (int) j);
			U[rt] = std::min(U[rt], (int) i);
			D[rt] = std::max(D[rt], (int) i);
			rts.insert(rt);
		}
	}

	int siz = 0;
	for (auto rt : rts) {
		siz += (D[rt] - U[rt] + 1) * (R[rt] - L[rt] + 1);
		rep (i, U[rt], D[rt]) {
			rep (j, L[rt], R[rt]) {
				if (i != U[rt] and a[i - 1][j]) return false;
				if (j != L[rt] and b[i][j - 1]) return false;
			}
		}
	}

	// db << "ok\n";

	return siz == ((x + 1) * (y + 1));
}

int rcnt;

// x 条横边，y 条竖边
i64 calc(int x, int y) {
	int tot = (x + 1) * y + x * (y + 1);

	i64 ans = 0;
	rep (S, 0, (1 << tot) - 1) {
		ans += chk(S, x, y);
	}

	rcnt += (1 << tot);

	return ans;
}

void solve() {
	std::cin >> n >> m >> k;

	i64 ans = 0;
	rep (x, 0, std::min(n - 1, k - 1)) {
		rep (y, 0, std::min(m - 1, k - 1)) {
			if (x + y > k - 1) break;

			(ans += calc(x, y) % mod * choose(n - 1, x) % mod * choose(m - 1, y) % mod) %= mod;
		}
	}	

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen("floor.in", "r", stdin);
	freopen("floor.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
