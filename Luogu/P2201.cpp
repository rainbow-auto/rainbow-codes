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
// #define MultiTask lovely_fairytale

const int maxn = 1000005;

int n;
int s1[maxn], sp1;
int s2[maxn], sp2;
int mx[maxn], sum[maxn];

inline void upd() {
	sum[sp1] = sum[sp1 - 1] + s1[sp1];
	mx[sp1] = std::max(mx[sp1 - 1], sum[sp1]);
}

inline void ins(int x) { s1[++sp1] = x; upd(); }

inline void del() { sp1--; }

inline void L() { s2[++sp2] = s1[sp1--]; }

inline void R() { s1[++sp1] = s2[sp2--]; upd(); }

inline int qry(int x) { return mx[x]; }

void solve() {
	int _; std::cin >> _;

	std::memset(mx, 0x3f, sizeof(mx[0])); mx[0] *= -1;

	while (_--) {
		char op; std::cin >> op;
		if (op == 'I') {
			int x; std::cin >> x;
			ins(x);
		} else if (op == 'D') {
			del();
		} else if (op == 'L') {
			L();
		} else if (op == 'R') {
			R();
		} else if (op == 'Q') {
			int x; std::cin >> x;
			std::cout << qry(x) << "\n";
		}
	}	
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
