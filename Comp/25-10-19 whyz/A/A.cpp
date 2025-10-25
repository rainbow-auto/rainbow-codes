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
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;

int n, m;
int a[maxn], b[maxn];

namespace Task1 {
    int cnt[maxn][2]; // 0 : +1 | 1 : -1
    int cnt1[maxn][2];
    
    inline void mv(int c, int x) {
        rep (i, 0, (m << 1)) cnt1[i][c] = 0;
        rep (i, 0, (m << 1)) cnt1[i + x][c] = cnt[i][c];
    }
    
    int ans[maxn];
    inline void upd() {
        int cur = 0;
        rep (i, 0, (m << 1)) {
            cur += cnt1[i][0] - cnt1[i][1];
            ans[i] += cur;
        }
    }
    
    void solve() {
        std::cin >> n >> m;
        rep (i, 1, n) {
            std::cin >> a[i] >> b[i];
            cnt[a[i]][0]++;
            cnt[b[i] + 1][1]++;
        }
    
        rep (i, 1, n) {
            mv(0, a[i]);
            mv(1, b[i]);
            upd();
        }
    
        rep (i, 0, (m << 1)) std::cout << ans[i] << "\n";
    }
}

namespace Task2 {
    i64 cnt[maxn][2]; // 0 : +1 | 1 : -1
    
    i64 ans[maxn];
    inline void upd(int a, i64 c, int id) {
        i64 cur = 0;
        rep (i, 0, (m << 1)) {
            if (i - a >= 0) cur += cnt[i - a][id];
            ans[i] += c * cur;
        }
    }

    i64 acnt[maxn], bcnt[maxn];

    void solve() {
        std::cin >> n >> m;
        rep (i, 1, n) {
            std::cin >> a[i] >> b[i];
            acnt[a[i]]++;
            bcnt[b[i]]++;

            cnt[a[i]][0]++;
            cnt[b[i] + 1][1]++;
        }

        // rep (i, 1, n) {
        //     upd(a[i], 1, 0);
        //     upd(b[i], -1, 1);
        // }

        rep (a, 0, m) upd(a, acnt[a], 0);
        rep (b, 0, m) upd(b, -bcnt[b], 1);
    
        rep (i, 0, (m << 1)) std::cout << ans[i] << "\n";
    }
}

void solve() {
    // Task1::solve();
    Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
