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

int id = 0;

void solve() {
	++id;
	std::cout << "#" << id << "\n";
	std::system("./gen > dict.in");
	// std::system("./temp < dict.in > ctldict.out");
	std::system("./std < dict.in > ctldict.out");
    std::system("./hyt < dict.in > hytdict.out");
    if (std::system("diff ctldict.out hytdict.out")) { std::cout << "WA\n"; exit(0); }
	std::cout << "AC\n";
}

bool MemED;
int main() {
	// fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MultiTask
	int _ = 1000000;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
