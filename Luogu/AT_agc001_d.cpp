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

const int maxn = 100005;

int n, m;
std::vector<int> A[2];

std::vector<int> a, b;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, m) {
		int x; std::cin >> x;
		A[x & 1].push_back(x);
	}

	if (m == 1) {
		if (n == 1) {
			std::cout << "1\n";
			std::cout << "1\n";
			std::cout << "1\n";
		} else {
			int x = A[0].empty() ? A[1].front() : A[0].front();
			std::cout << x << "\n";
			std::cout << "2\n";
			std::cout << 1 << " " << x - 1 << "\n";
		}
		return;
	}

	if ((int) A[1].size() > 2) return std::cout << "Impossible\n" , void(0);

	if (A[1].size() > 0) a.push_back(A[1][0]);
	for (auto x : A[0]) a.push_back(x);
	if (A[1].size() > 1) a.push_back(A[1][1]);

	b = a;
	b.front()++;
	if (b.back() - 1 == 0) b.pop_back();
	else b.back()--;

	for (auto x : a) std::cout << x << " ";
	std::cout << "\n";
	std::cout << b.size() << "\n";
	for (auto x : b) std::cout << x << " ";
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
