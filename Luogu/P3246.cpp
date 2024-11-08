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

const int maxn = 100005;

int n, q;
i64 a[maxn];

struct SparseTable {
	std::pair <int, int> st[25][maxn];
	int lg2[maxn];

	inline void init () {
		rep (i, 1, n) { st[0][i] = { a[i], i }; }

		rep (j, 1, 20) {
			rep (i, 1, n - (1 << j) + 1) {
				st[j][i] = std::min (st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
			}
		}

		lg2[0] = 1;
		rep (i, 2, n) { lg2[i] = lg2[i >> 1] + 1; }
	}

	inline std::pair <int, int> query (int l, int r) {
		int len = lg2[r - l + 1];
		return std::min (st[len][l], st[len][r - (1 << len) + 1]);
	}
} st;

int pre[maxn];
inline void get_pre () {
	std::stack <int> stk; stk.push (0); a[0] = -2e9;
	rep (i, 1, n) {
		while (not stk.empty () and a[stk.top ()] >= a[i]) { stk.pop (); }
		pre[i] = stk.top ();
		stk.push ((int) i);
	}
}

int nxt[maxn];
inline void get_nxt () {
	std::stack <int> stk; stk.push (n + 1); a[n + 1] = -2e9;
	per (i, n, 1) {
		while (not stk.empty () and a[stk.top ()] >= a[i]) { stk.pop (); }
		nxt[i] = stk.top ();
		stk.push ((int) i);
	}
}

i64 f_pre[maxn], sp[maxn];
i64 f_nxt[maxn], sn[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> q;
	rep (i, 1, n) { std::cin >> a[i]; }

	st.init ();
	get_pre ();
	get_nxt ();

	rep (i, 1, n) { f_pre[i] = f_pre[pre[i]] + a[i] * (i - pre[i]); sp[i] = sp[i - 1] + f_pre[i]; }
	per (i, n, 1) { f_nxt[i] = f_nxt[nxt[i]] + a[i] * (nxt[i] - i); sn[i] = sn[i + 1] + f_nxt[i]; }

	while (q--) {
		int l, r; std::cin >> l >> r;
		i64 mn, pos; std::tie (mn, pos) = st.query (l, r);
		
		i64 ans = mn * (pos - l + 1) * (r - pos + 1);
		ans += sp[r] - sp[pos] - (f_pre[pos] * (r - pos));
		ans += sn[l] - sn[pos] - (f_nxt[pos] * (pos - l));
		std::cout << ans << "\n";
	}

	return 0;
}
