#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

int n;
std::pair<int, int> a[maxn][3];

void solve() {
    std::cin >> n;
    rep (i, 1, n) {
        rep (j, 0, 2) {
            std::cin >> a[i][j].first;
            a[i][j].second = j;
        }
        std::sort(a[i], a[i] + 3);
        std::reverse(a[i], a[i] + 3);
    }

    i64 inf = 1e18;

    i64 ans = 0;
    std::array<std::priority_queue<std::pair<i64, int>>, 3> q;
    rep (i, 1, n) {
        ans += a[i][0].first;
        q[a[i][0].second].push({-a[i][0].first + a[i][1].first, i});
        if (q[a[i][0].second].size() > (n >> 1)) {
            ans += q[a[i][0].second].top().first;
            int t = q[a[i][0].second].top().second;
            q[a[i][0].second].pop();
            q[a[t][1].second].push({inf, t});
        }
    }

    std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
    
    file("club")

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
