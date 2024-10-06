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

const int maxn = 200005;

int n, m, q;
int a[maxn], b[maxn];

std::bitset<maxn> vis;

bool chk() {
    int id = 0;
    rep (i, 1, m) {
        if (a[id] == b[i]) {
            continue;
        } else if (a[id + 1] == b[i]) {
            vis.set(a[++id]);
        } else {
            if (not vis[b[i]]) {
                return false;
            }
        }
    } 

    return true;  
}

void solve() {
    std::cin >> n >> m >> q;
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, m) std::cin >> b[i];

    if (chk()) std::cout << "YA\n";
    else std::cout << "TIDAK\n";

    rep (i, 1, n) vis[i] = false;
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
