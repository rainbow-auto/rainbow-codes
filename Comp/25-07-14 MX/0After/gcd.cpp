/*
调破防了

流泪了

呜呜呜呜

求求你了让我过一次吧 /kel/kel/kel
*/

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

constexpr int maxn = 100005;
constexpr int maxq = 300005;

int n, q;
int a[maxn];

namespace Solution {
    constexpr int maxg = 75;

    int nxt[maxn][maxg];

    int gcd(int a, int b) {
        if (not b) return a;
        return gcd(b, a % b);
    }

    int tot;
    std::unordered_map<int, int> key;
    int val[maxg];

    inline void add(int x) {
        if (not key.count(x)) {
            key[x] = ++tot;
            val[tot] = x;
        }
    }

    inline void init() {
        std::memset(nxt, 0x3f, sizeof nxt);

        std::unordered_map<int, int> suf;
        per (i, n, 1) {
            std::unordered_map<int, int> now;
            now.clear();
            now[a[i]] = i;

            for (auto x : suf) {
                int cg = gcd(x.first, a[i]);
                add(cg);

                if (not now.count(cg)) now[cg] = x.second;
                else now[cg] = std::min(now[cg], x.second);
            }

            rep (k, 1, tot) {
                if (now.count(val[k])) {
                    nxt[i][k] = now[val[k]];
                }
            }
            nxt[i][0] = now[a[i]];

            suf = now;
        }

        dbg(tot);
    }
    
    struct Tree {
        int to[18][maxn];
        int g;
        
        inline void init(int _g) {
            g = _g;

            std::memset(to, 0x3f, sizeof to);
            rep (i, 1, n) {
                to[0][i] = nxt[i][key[g]] + 1;
            }

            rep (k, 1, 17) {
                rep (i, 1, n) {
                    if (to[k - 1][i] <= n) {
                        to[k][i] = to[k - 1][to[k - 1][i]];
                    }
                }
            }
        }

        inline int qry(int l, int r) {
            int res = 0;
            int cur = l;
            per (k, 17, 0) {
                if (to[k][cur] <= r + 1) {
                    cur = to[k][cur];
                    res += (1ll << k);
                } 
            }

            return res;
        }
    };

    Tree tr[maxg];

    inline int qrygcd(int l, int r) {
        int g = 0;
        rep (k, 1, tot) {
            if (nxt[l][k] <= r) g = gcd(g, val[k]);
        }
        return g;
    }

    inline void solve() {
        tot = 0;
        init();

        rep (k, 1, tot) tr[k].init(val[k]);

        while (q--) {
            int l, r; std::cin >> l >> r;
            int g = qrygcd(l, r);

            int k = tr[key[g]].qry(l, r);
            std::cout << (r - l + 1) - k << "\n";
        }
    }   
}

void solve() {
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> a[i];

    Solution::solve();
}

bool MemED;
int main() {
	fastread
	lookMem	

    // file("gcd_2")

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
