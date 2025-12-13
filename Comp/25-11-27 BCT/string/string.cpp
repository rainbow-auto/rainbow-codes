#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;
using u64 = unsigned long long;

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

int n, m;
std::string s, t;

const i64 mod[3] = { 998244353, i64(1e9 + 7), i64(1e9 + 9) };

i64 base;
i64 pw[3][maxn];

inline void init(int N) {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    // base = rng() % mod[0];
    base = 233;
    dbg(base);

    rep (j, 0, 2) {
        pw[j][0] = 1;
        rep (i, 1, N) pw[j][i] = pw[j][i - 1] * base % mod[j];
    }
} 
	
using Hash = std::array<i64, 3>;
struct Hashs {
    std::vector<Hash> h;
    Hashs(std::string s) {
        gen(s);
    }

    inline void gen(std::string s) {
        h = {};
        h.push_back({0, 0, 0});
        rep (i, 1, (int) s.size() - 1) {
            Hash h0; 
            rep (j, 0, 2) {
                h0[j] = (h.back()[j] * base % mod[j] + (s[i] - 'a')) % mod[j];
            }
            h.push_back(h0); 
        }
    }
    
    inline Hash sub(int l, int r) {
        if (l <= r and l > 0 and r < h.size()) {
            Hash res = {0, 0, 0}; 
            rep (j, 0, 2) {
                res[j] = ((h[r][j] - h[l - 1][j] * pw[j][r - l + 1] % mod[j]) % mod[j] + mod[j]) % mod[j];
            }
            return res;
        } else {
            return {-1, -1, -1};
        }
    }
};

namespace Task1 {
    inline void solve() {
        int ans = 0;

        rep (v, 1, n) {
            rep (p, 1, m) {
                // dbg(v);
                // dbg(p);

                std::string ss;
                rep (i, 1, v) ss += s[i];
                int slen = ss.size();
                ss = " " + ss;

                std::string tt;
                rep (i, p, m) tt += t[i];
                int tlen = tt.size();
                tt = " " + tt;
                
                Hashs hs(ss);
                Hashs ht(tt);

                // dbg(ss);
                // dbg(tt);
 
                {
                    // suf(ss) + (border + suf(ss) + border)
                    std::vector<int> pi(tlen + 1);
                    pi[1] = 0;
                    rep (i, 2, tlen) {
                        int j = pi[i - 1];
                        while (j and tt[j + 1] != tt[i]) j = pi[j];
                        if (tt[j + 1] == tt[i]) j++;
                        pi[i] = j;
                    }

                    rep (i, 2, tlen) {
                        int j = i;
                        while (j) {
                            j = pi[j];

                            int l = j + 1, r = i - j;
                            
                            if (l <= r) {
                                int len = (r - l + 1);
                                ans += (ht.sub(l, r) == hs.sub(slen - len + 1, slen));
                                // if (ht.sub(l, r) == hs.sub(slen - len + 1, slen)) db << "tbd ans++\n";
                            }
                        }
                    }
                }
                
                {
                    // (border + pre(tt) + border) + pre(tt)
                    std::vector<int> pi(slen + 1);
                    pi[1] = 0;
                    rep (i, 2, slen) {
                        int j = pi[i - 1];
                        while (j and ss[j + 1] != ss[i]) j = pi[j];
                        if (ss[j + 1] == ss[i]) j++;
                        pi[i] = j;
                    }
    
                    rep (i, 2, slen) {
                        int j = i;
                        while (j) {
                            j = pi[j];
                            int l = j + 1, r = i - j;
                            
                            if (l <= r) {
                                int len = (r - l + 1);
                                ans += (hs.sub(l, r) == ht.sub(1, len));
                                // if (hs.sub(l, r) == ht.sub(1, len)) db << "sbd ans++\n";
                            }
                        }
                    }
                }

                if (ss[slen] == tt[1]) ans++;

                // db << "---------\n";
            }
        }

        std::cout << ans << "\n";
    }
}

void solve() {
    init(5000);

	std::cin >> s >> t;
    n = s.size(); m = t.size();
    s = " " + s; t = " " + t;

    Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("string")

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
