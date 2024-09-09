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

int n;
struct Node {
	int p;
	int d;
} a[maxn]; 

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	while (std::cin >> n) {
		rep (i, 1, n) { std::cin >> a[i].p >> a[i].d; }

		std::sort (a + 1, a + n + 1, [] (Node x, Node y) -> bool { return x.d < y.d; });

		std::priority_queue <int, std::vector <int>, std::greater <int> > q;
		rep (i, 1, n) {
			if (q.size () > a[i].d) { continue; }
			if (q.size () == a[i].d) { if (q.top () < a[i].p) { q.pop (); q.push (a[i].p); } }
			if (q.size () < a[i].d) { q.push (a[i].p); }
		}

		i64 ans = 0;
		while (not q.empty ()) { ans += q.top (); q.pop (); }
		std::cout << ans << "\n";
	}


	return 0;
}
