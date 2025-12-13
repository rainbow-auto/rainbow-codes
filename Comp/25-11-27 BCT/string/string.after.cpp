// 别样的做法

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

constexpr int maxn = 5005;

std::string s, t;

struct DS {
    int n;
    i64 sum[maxn];

    DS(int siz) {
        n = siz;
        rep (i, 0, siz) sum[i] = 0;
    }

    inline void mdf(int pos, int v) {
        sum[pos] += v;
    }

    inline void build() {
        rep (i, 1, n) sum[i] += sum[i - 1];
    }

    inline i64 qry(int l, int r) {
        if (l > r) return 0;
        if (l == 0) return sum[r];
        return sum[r] - sum[l - 1];
    }
};

inline i64 calc(std::string s, std::string t, bool flg = false) {
    // db << "calc " << s << " " << t << "\n";

    std::vector<std::vector<int>> f(s.size() + 1, std::vector<int>(s.size() + 1));
    per (i, (int) s.size() - 1, 0) {
        per (j, (int) s.size() - 1, 0) {
            f[i][j] = 0;
            if (s[i] == s[j]) f[i][j] = f[i + 1][j + 1] + 1;
        }
    }

    std::vector<std::vector<int>> g(s.size(), std::vector<int>(t.size()));
    rep (i, 0, (int) s.size() - 1) {
        rep (j, 0, (int) t.size() - 1) {
            g[i][j] = 0;
            if (s[i] == t[j]) {
                if (i - 1 >= 0 and j - 1 >= 0) g[i][j] = g[i - 1][j - 1];
                g[i][j]++;
            }
        }
    }

    i64 res = 0;
    rep (i, 1, (int) s.size() - 1) {
        int mx = std::max(s.size(), t.size());
        DS gsum(mx);
        rep (j, 0, t.size() - 1) gsum.mdf(g[i - 1][j], 1);
        gsum.build();
        
        DS sum(s.size());
        per (j, i - 1, 0) {
            sum.mdf(j, gsum.qry((i - 1) - j + 1, mx));
        }
        sum.build();
        
        rep (j, 0, i - 1) {
            // dbg(j);
            // dbg(f[i][j]);
            int l = j + 1;
            int r = std::min(j + f[i][j], i - 1);
            // dbg(l); dbg(r);
            // dbg(qry(l, r));
            res += sum.qry(l, r);
            // dbendl;
        }
        
        // db << "-----------\n";
    }

    if (flg) {
        rep (i, 0, s.size() - 1) {
            int mx = std::max(s.size(), t.size());
            DS gsum(mx);
            rep (j, 0, t.size() - 1) gsum.mdf(g[i][j], 1);
            gsum.build();
            
            per (j, i, 0) {
                res += gsum.qry(i - j + 1, mx);
            }
        }
    }

    return res;
}

// 4 + 4 + 2 + 2 + 2 + 2

void solve() {
    std::cin >> s >> t;
    std::cout << calc(s, t) + calc(t, s, 1) << "\n";
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
