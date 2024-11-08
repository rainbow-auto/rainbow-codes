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

const int maxn = 10000005;

int n;
int w[maxn];

struct Node {
	int ls, rs;
} tr[maxn];


inline int build () {
	std::stack <int> rChain; // 右链
	rep (now, 1, n) {
		int last = 0;
		while (not rChain.empty () and w[rChain.top ()] > w[now]) { last = rChain.top (); rChain.pop (); }
		tr[rChain.empty () ? 0 : rChain.top ()].rs = now;
		tr[now].ls = last;
		rChain.push (now);
	}
	return tr[0].rs;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n) { std::cin >> w[i]; }

	int root = build ();

	i64 Lsum = 0;
	i64 Rsum = 0;
	rep (i, 1, n) {
		Lsum ^= (i64) i * (tr[i].ls + 1);
		Rsum ^= (i64) i * (tr[i].rs + 1);
	}

	std::cout << Lsum << " " << Rsum << "\n";

	return 0;
}
