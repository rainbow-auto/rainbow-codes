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

int a, b, c;
i64 I, D, R;
i64 pw10[17];
inline void init() {
    pw10[0] = 1;
    rep (i, 1, 16) pw10[i] = pw10[i - 1] * 10ll;
}

namespace Task1 {
    inline i64 to_num(std::string s) {
        i64 res = 0;
        rep (i, 0, (int) s.size() - 1) {
            res += pw10[i] * (s[i] - '0');
        }
        return res;
    }

    i64 ans = 1e18;;
    void dfs(std::array<std::string, 3> ss, i64 stp) {
        if (to_num(ss[0]) + to_num(ss[1]) == to_num(ss[2])) {
            ans = std::min(ans, stp);
            return;
        }

        if (stp >= ans) return;

        // delete
        rep (id, 0, 2) {
            rep (i, 0, (int) ss[id].size() - 1) {
                auto ss1 = ss;
                ss1[id].erase(ss1[id].begin() + i);
                dfs(ss1, stp + D);
            }
        }

        // insert
        rep (id, 0, 2) {
            rep (t, 0, 9) {
                rep (i, 0, (int) ss[id].size() - 1) {
                    if (i == ss[id].size() - 1 and t == 0) continue;
                    auto ss1 = ss;
                    ss1[id].insert(ss1[id].begin() + i, char(t + '0'));
                    dfs(ss1, stp + I);
                }

                rep (i, 0, (int) ss[id].size() - 1) {
                    if (i == ss[id].size() - 1 and t == 0) continue;
                    auto ss1 = ss;
                    ss1[id][i] = t + '0';
                    dfs(ss1, stp + R);
                }
            }
        }
    }

    inline void solve() {
        std::string A = std::to_string(a); std::reverse(A.begin(), A.end());
        std::string B = std::to_string(a); std::reverse(B.begin(), B.end());
        std::string C = std::to_string(a); std::reverse(C.begin(), C.end());
        
        ans = 1e18;
        if (A.size() == B.size() and B.size() == C.size()) ans = std::min(ans, 3ll * i64(A.size()) * R);
        ans = std::min(ans, D * i64(A.size() - 1) + R + D * i64(B.size() - 1) + R + D * i64(C.size() - 1) + R);
        ans = std::min(ans, D * i64(A.size()) + I + D * i64(B.size()) + I + D * i64(C.size()) + I);

        dfs({A, B, C}, 0);

        std::cout << ans << "\n";
    }
}

namespace Task2 {
    i64 ans = 1e18;

    inline i64 to_num(std::vector<int> s) {
        i64 res = 0;
        rep (i, 0, (int) s.size() - 1) {
            if (s[i] == -1) continue;
            res += pw10[i] * s[i];
        }
        return res;
    }
    
    void dfs(std::array<std::vector<int>, 3> s, i64 stp, int addid, int lst) {
        if (stp > ans) return;

        if (addid < 3) {
            rep (i, lst, s[addid].size()) {
                auto s1 = s;
                s1[addid].insert(s1[addid].begin() + i, -1);
                dfs(s1, stp + I, addid, lst + 1);
                dfs(s1, stp + I, addid + 1, 0);
            }
        } else {
            i64 dt = to_num(s[2]) - to_num(s[1]) - to_num(s[0]);

            if (dt == 0) return ans = std::min(ans, stp), void(0);
            
            if (dt > 0) {
                std::array<int, 3> pos = { (int) s[0].size() - 1, (int) s[1].size() - 1, (int) s[2].size() - 1 };

                while (pos[0] >= 0 and pos[1] >= 0 and pos[2] >= 0) {
                    rep (b, 0, 1) {
                        int c = s[b][pos[b]];
                        if (c == -1) c = 0;
                        c *= pw10[pos[b]];
                        
                        i64 tt = -1;
                        rep (t, 0, 9) {
                            if (pos[b] == s[b].size() - 1 and t == 0) continue;
                            if (dt + c - t * pw10[pos[b]] >= 0) {
                                tt = t;
                            }
                        }
    
                        if (~tt) {
                            dt = dt + c - tt * pw10[pos[b]];
                            if (s[b][pos[b]] != -1) stp += R;
                        }
                    }
                    
                    rep (b, 2, 2) {
                        int c = s[b][pos[b]];
                        if (c == -1) c = 0;
                        c *= pw10[pos[b]];
                        
                        std::pair<i64, int> mn = {i64(1e18), -1};
                        i64 tt = -1;
                        per (t, 9, 0) {
                            if (pos[b] == s[b].size() - 1 and t == 0) continue;
                            if (dt - c + t * pw10[pos[b]] >= 0) {
                                tt = t; break;
                            }
                        }
    
                        if (~tt) {
                            dt = dt - c + tt * pw10[pos[b]];
                            if (s[b][pos[b]] != -1) stp += R;
                        }
                    }
    
                    if (not dt) return ans = std::min(ans, stp), void(0);
                    pos[0]--; pos[1]--; pos[2]--;
                }
            } else {
                std::array<int, 3> pos = { (int) s[0].size() - 1, (int) s[1].size() - 1, (int) s[2].size() - 1 };

                while (pos[0] >= 0 and pos[1] >= 0 and pos[2] >= 0) {
                    rep (b, 0, 1) {
                        int c = s[b][pos[b]];
                        if (c == -1) c = 0;
                        c *= pw10[pos[b]];
                        
                        std::pair<i64, int> mn = {i64(1e18), -1};
                        i64 tt = -1;
                        rep (t, 0, 9) {
                            if (pos[b] == s[b].size() - 1 and t == 0) continue;
                            if (dt + c - t * pw10[pos[b]] <= 0) {
                                tt = t;
                                break;
                            }
                        }
    
                        if (~tt) {
                            dt = dt + c - tt * pw10[pos[b]];
                            if (s[b][pos[b]] != -1) stp += R;
                        }
                    }
                    
                    rep (b, 2, 2) {
                        int c = s[b][pos[b]];
                        if (c == -1) c = 0;
                        c *= pw10[pos[b]];
                        
                        std::pair<i64, int> mn = {i64(1e18), -1};
                        i64 tt = -1;
                        rep (t, 0, 9) {
                            if (pos[b] == s[b].size() - 1 and t == 0) continue;
                            if (dt - c + t * pw10[pos[b]] <= 0) {
                                tt = t;
                            }
                        }
    
                        if (~tt) {
                            dt = dt - c + tt * pw10[pos[b]];
                            if (s[b][pos[b]] != -1) stp += R;
                        }
                    }
    
                    if (not dt) return ans = std::min(ans, stp), void(0);
                    pos[0]--; pos[1]--; pos[2]--;
                }
            }
            
            return;
        }
    }

    inline std::vector<int> to_vec(int x) {
        std::vector<int> vec;
        while (x) {
            vec.push_back(x % 10);
            x /= 10;
        }
        return vec;
    }

    inline void solve() {
        auto A = to_vec(a);
        auto B = to_vec(b);
        auto C = to_vec(c);

        rep (SA, 0, (1 << A.size()) - 1) {
        rep (SB, 0, (1 << B.size()) - 1) {
        rep (SC, 0, (1 << C.size()) - 1) {
            std::vector<int> A1, B1, C1;
            rep (i, 0, A.size() - 1) if ((SA >> i) & 1) A1.push_back(A[i]);
            rep (i, 0, B.size() - 1) if ((SB >> i) & 1) B1.push_back(B[i]);
            rep (i, 0, C.size() - 1) if ((SC >> i) & 1) C1.push_back(C[i]);

            dfs({A1, B1, C1}, i64(A.size() - A1.size()) * D + i64(B.size() - B1.size()) * D + i64(C.size() - C1.size()) * D, 0, 0);
        }}}

        std::cout << ans << "\n";
    }
}

namespace Task3 {
    i64 ans = 1e18;

    inline i64 to_num(std::vector<int> s) {
        i64 res = 0;
        rep (i, 0, (int) s.size() - 1) {
            if (s[i] == -1) continue;
            res += pw10[i] * s[i];
        }
        return res;
    }

    std::array<std::vector<int>, 3> s;
    void dfs(i64 stp, int id, int lst, bool flg) {
        if (stp > ans) return;
        if (s[0].size() > 15) return;
        if (s[1].size() > 15) return;
        if (s[2].size() > 15) return;

        if (not flg) {
            rep (i, lst, s[id].size()) {
                auto s1 = s;
                s[id].insert(s[id].begin() + i, -1);
                dfs(stp + I, id, lst + 1, false);
                if (id + 1 < 3) dfs(stp + I, id + 1, 0, false);
                else dfs(stp + I, 0, 0, true);
                s = s1;
            }
        } else {
            rep (i, lst, (int) s[id].size() - 1) {
                rep (t, 0, 9) {
                    auto s1 = s;
                    s[id][i] = t;
                    dfs(stp + R, id, lst + 1, true);
                    if (id + 1 < 3) dfs(stp + R, id + 1, 0, true);
                    s = s1;
                }
            }   
        }
    }

    inline std::vector<int> to_vec(int x) {
        std::vector<int> vec;
        while (x) {
            vec.push_back(x % 10);
            x /= 10;
        }
        return vec;
    }

    inline void solve() {
        auto A = to_vec(a);
        auto B = to_vec(b);
        auto C = to_vec(c);

        rep (SA, 0, (1 << A.size()) - 1) {
        rep (SB, 0, (1 << B.size()) - 1) {
        rep (SC, 0, (1 << C.size()) - 1) {
            std::vector<int> A1, B1, C1;
            rep (i, 0, A.size() - 1) if ((SA >> i) & 1) A1.push_back(A[i]);
            rep (i, 0, B.size() - 1) if ((SB >> i) & 1) B1.push_back(B[i]);
            rep (i, 0, C.size() - 1) if ((SC >> i) & 1) C1.push_back(C[i]);

            s[0] = A1;
            s[1] = B1;
            s[2] = C1;
            dfs(i64(A.size() - A1.size()) * D + i64(B.size() - B1.size()) * D + i64(C.size() - C1.size()) * D, 0, 0, false);
        }}}

        std::cout << ans << "\n";
    }
}

void solve() {
	std::cin >> a >> b >> c;
    std::cin >> I >> D >> R;

    // Task1::solve();
    Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("distortion2")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif

    init();
	
	while (_--) {
		solve();
	}

	return 0;
}
