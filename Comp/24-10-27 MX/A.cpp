#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 5005;
const int maxc = 505;

int n, m, S;
int a[maxn][maxn];

std::vector<int> colors;

struct Rect {
	int L, R, U, D;

	Rect() {
		std::memset(&L, 0x3f, sizeof L);
		std::memset(&U, 0x3f, sizeof U);
		R = D = 0;
	}

	friend bool operator < (Rect a, Rect b) {
		return a.L < b.L;
	}

} col[maxc];

template<typename T> 
inline bool chkmax(T& x, T y) { return x < y ? x = y, 1 : 0; }

template<typename T> 
inline bool chkmin(T& x, T y) { return x > y ? x = y, 1 : 0; }

struct Tree {
	int tr[maxn];
	int mx;
	Tree(int _mx) {
		mx = _mx;
		std::memset(tr, 0, sizeof tr);
	}

	inline int lowbit(int x) { return x & -x; }
	
	inline void mdf(int pos, int val) {
		for (int i = pos; i <= mx; i += lowbit(i)) tr[i] += val;
	}

	inline int qry(int pos) {
		chkmin(pos, mx);
		int res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}
};

void solve() {
	std::freopen("disinfect.in", "r", stdin);
	std::freopen("disinfect.out", "w", stdout);

	std::cin >> n >> m >> S;

	int mxc = 0;
	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> a[i][j];
			colors.push_back(a[i][j]);
		}
	}

	std::sort(colors.begin(), colors.end());
	colors.erase(std::unique(colors.begin(), colors.end()), colors.end());

	rep (i, 1, n) {
		rep (j, 1, m) {
			int c = std::lower_bound(colors.begin(), colors.end(), a[i][j]) - colors.begin() + 1;
			chkmin(col[c].L, j); chkmax(col[c].R, j);
			chkmin(col[c].U, i); chkmax(col[c].D, i);
			chkmax(mxc, c);
		}
	}

	std::sort(col + 1, col + mxc + 1);

	int ans = 0;

	int lst = -1;
	rep (cl, 1, mxc) {

		if (col[cl].L == lst) continue;
		lst = col[cl].L;

		std::set<std::pair<int, int>> rgs;

		rep (cr, cl, mxc) {
			int W = col[cr].R - col[cl].L;
			if (W <= 0) continue;
			int H = S / W;
			if (H <= 0) break;

			rgs.insert(std::make_pair(col[cr].U, col[cr].D));

			Tree tr(m);

			int cur = 0;
			for (auto it = rgs.rbegin(); it != rgs.rend(); it++) {
				int l, r; std::tie(l, r) = *it;
				tr.mdf(r, 1);
				chkmax(cur, tr.qry(l + H));
			}

			chkmax(ans, cur);
		}
	}

	std::cout << mxc - ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
