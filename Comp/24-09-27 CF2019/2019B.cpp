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

const int maxn = 100005;

int n, q;
int x[maxn];

i64 qs[maxn];

void solve() {
    std::map <i64, int> ans;

    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> x[i];
    rep (i, 1, q) std::cin >> qs[i];

    rep (i, 1, n - 1) {
        i64 len = x[i + 1] - x[i] - 1;
        i64 lsiz = i;
        i64 rsiz = n - i;
    
        i64 cur = lsiz * rsiz;
        ans[cur] += len;
    }

    rep (i, 1, n) {
        i64 lsiz = i;
        i64 rsiz = n - i + 1;
        i64 cur = lsiz * rsiz - 1;
        ans[cur] ++;
    }

    rep (i, 1, q) {
        if (not ans.count(qs[i])) std::cout << "0 ";
        else std::cout << ans[qs[i]] << " ";
    }
    std::cout << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
