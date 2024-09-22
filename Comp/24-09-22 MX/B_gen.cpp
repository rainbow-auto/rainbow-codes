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

const int maxn = 1000005;
const int maxB = (1 << 20) + 5;

int n, m, c;
int a[maxn];

std::bitset <maxB> cnt;
std::bitset <maxB> vis;

int stk[maxn], spos;

int bfs (int S) {
    std::queue <int> q;
    q.push (S);
    int res = 0x3f3f3f3f;
    while (not q.empty ()) {
        int u = q.front (); q.pop ();

        if (cnt[u]) { res = __builtin_popcount (u ^ S); break; }

        vis[u] = 1; stk[++spos] = u;
        rep (i, 0, m - 1) {
            int v = u ^ (1 << i);
            if (vis[v]) { continue; }

            q.push (v);
        }
    }

    rep (i, 1, spos) { vis[stk[i]] = 0; }
    spos = 0;

    return res;
}


inline void solve () {
    std::cin >> n >> m >> c;

    rep (i, 1, n) {
        rep (j, 0, m - 1) { 
            char ch; std::cin >> ch;
            a[i] |= ((ch - '0') << j); 
        }
    }

    i64 ans = c;
    cnt.set (a[1]);
    rep (i, 2, n) {
        ans += std::min (c, bfs (a[i]) + 1);
        cnt.set (a[i]);
    }

    std::cout << ans << "\n";

    // Solution::solve ();

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
	// TimeST = clock ();

    // freopen ("code.in", "r", stdin);
    freopen ("code.in", "w", stdout);

	// int _ = 1;
	
	// int _; std::cin >> _;
	
	// while (_--) {
		// solve ();
	// }

    int n = 1000000;
    int m = 20;
    int c = 1000;

    std::cout << n << " " << m << " " << c << "\n";

    rep (i, 1, n) {
        rep (j, 1, m) {
            std::cout << (rand() & 1);
        }
        std::cout << "\n";
    }

    lookTime;

	return 0;
}
