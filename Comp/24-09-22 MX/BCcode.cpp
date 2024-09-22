#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

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

const int maxn = 1000005;
const int maxB = (1 << 20) + 5;

int n, m, c;
int a[maxn];

namespace Task1 {
    int popcnt[maxB];
    inline void solve () {
        popcnt[0] = 0;
        rep (i, 1, 1 << 20) { popcnt[i] = popcnt[i >> 1] + (i & 1); }
        
        i64 ans = 0;
        rep (i, 1, n) {
            int curr = c;
            rep (j, 1, i - 1) {
                curr = std::min (curr, popcnt[a[i] ^ a[j]] + 1);
            }

            ans += curr;
        }
    }
}

// c = 1
namespace Task2 {
    inline void solve () {
        std::cout << 1ll * n * c << "\n";
    }
}

// c = 2
namespace Task3 {
    std::bitset <maxB> cnt;

    inline void solve () {
        i64 ans = 0;
        rep (i, 1, n) {
            if (cnt[a[i]]) { ans += 1; }
            else { ans += 2; }
            cnt.set (a[i]);
        }
        std::cout << ans << "\n";
    }
}

// namespace Solution {
std::bitset <maxB> cnt;

std::bitset <maxB> vis;

int q[maxB << 1], l, r; 

int bfs (int S) {
    if (cnt[S]) { return 0; }
    q[l = r = 1] = S;
    vis[S] = 1;
    int res = 0x3f3f3f3f;
    while (l <= r) {
        int u = q[l ++]; 
        // db << u << "\n";
        rep (i, 0, m - 1) {
            int v = u ^ (1 << i);
            if (vis[v]) { continue; }
            if(cnt[v]){
                res = __builtin_popcount(v^S);
                goto lty;
            }
            vis[v] = 1;
            q[++r] = v;
        }
    }
    lty:;
    rep (i, 1, r) { vis[q[i]] = 0; }

    return res;
}


inline void solve1 () {
    i64 ans = c;
    cnt.set (a[1]);
    rep (i, 2, n) {
        // if (i % 50000 == 0) { db << i << "\n"; }
        ans += std::min (c, bfs (a[i]) + 1);
        cnt.set (a[i]);
    }

    std::cout << ans << "\n";
}

inline void solve () {
    std::cin >> n >> m >> c;

    rep (i, 1, n) {
        rep (j, 0, m - 1) { 
            char ch; std::cin >> ch;
            a[i] |= ((ch - '0') << j); 
        }
    }

    // Solution::solve ();
    solve1 ();

    // if (c == 1) {
    //     Task2::solve ();
    // } else if (c == 2) {
    //     Task3::solve ();
    // } else {
    //     std::cerr << "kkk\n";
    //     Task1::solve ();
    // }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	TimeST = clock ();

    freopen ("code.in", "r", stdin);
    freopen ("code.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
    lookTime;

	while (_--) {
		solve ();
	}

    lookTime

	return 0;
}
