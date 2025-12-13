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
int p[maxn];

namespace Task0 {
    constexpr int maxn = 15;

    std::set<int> pos[maxn];
    inline void solve() {
        rep (i, 1, n) p[i] = i;
        db << "kkkkkk\n";

        do {
            bool flg = true;
            rep (i, 1, n - 1) {
                if (i * p[i] > (i + 1) * p[i + 1]) {
                    flg = false; break;
                }
            }
        
            if (flg) {
                rep (i, 1, n) pos[p[i]].insert(i);
                rep (i, 1, n) db << p[i] << " "; dbendl;
            }
        } while (std::next_permutation(p + 1, p + n + 1));
        
        rep (i, 1, n) {
            dbg(i);
            for (auto p : pos[i]) db << p << " "; dbendl;
        }
    }
}

namespace Sol {
    bool vis[maxn];
    int pos[maxn];

    struct Tree {
        i64 tr[maxn];
        int siz;
        Tree(int n) {
            siz = n;
            rep (i, 1, n) tr[i] = 0;
        }

        inline int lowbit(int x) {
            return x & (-x);
        }

        inline void mdf(int pos, int v) {
            for (int i = pos; i <= siz; i += lowbit(i)) tr[i] += v;
        }

        inline i64 qry(int pos) {
            i64 res = 0;
            for (int i = pos; i > 0; i -= lowbit(i)) res += tr[i];
            return res;
        }
    };

    inline void solve() {  
        Tree tr(n);

        i64 ans = 0;

        rep (i, 1, n) {
            ans += (i - 1) - tr.qry(p[i] - 1);
            tr.mdf(p[i], 1);
        }

        rep (i, 1, n) pos[p[i]] = i;
        rep (i, 1, n) vis[i] = false;
    
        rep (i, 1, n - 1) {
            if (vis[i]) continue;
            if (pos[i + 1] <= pos[i]) {
                vis[i + 1] = true;
                ans--;
            }
        }

        std::cout << ans << "\n";
    }  
}

void solve() {
    std::cin >> n;
    // Task0::solve();
    rep (i, 1, n) std::cin >> p[i];   

    Sol::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	
    
    // file("permutation")

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
