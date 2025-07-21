#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;
using u64 = unsigned i64;

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

constexpr int maxn = 500005;

int n, k;
int pre[26][maxn];

std::string s[maxn];

// O(n^2 * k)
namespace Task1 {
    inline void solve() {
        i64 ans = 0;
        
        rep (i, 1, n) {
            rep (j, i + 1, n) {
                int pre = -1;
                rep (x, 0, k - 1) {
                    if (s[i][x] != s[j][x]) break;
                    pre = x;
                }
                
                int suf = k;
                per (x, k - 1, 0) {
                    if (s[i][x] != s[j][x]) break;
                    suf = x;
                }
                
                std::array<int, 26> c_i; c_i.fill(0);
                std::array<int, 26> c_j; c_j.fill(0);
                
                bool flg_i = true;
                bool flg_j = true;

                rep (k, pre + 1, suf - 1) {
                    if (k > pre + 1) flg_i &= (s[i][k] >= s[i][k - 1]);
                    if (k > pre + 1) flg_j &= (s[j][k] >= s[j][k - 1]);
                    c_i[s[i][k] - 'a']++;
                    c_j[s[j][k] - 'a']++;
                }
        
                bool same = true;
                rep (c, 0, 25) same &= (c_i[c] == c_j[c]);
        
                if (not same) {
                    ans += 6666;
                } else {
                    ans += 2 - flg_i - flg_j;
                }
            }
        }

        std::cout << ans << "\n";
    }
}

// O(n * k ^ 2)
namespace Task2 {
    constexpr u64 base = 233;
    inline u64 get(std::string &s) {
        u64 h = 0;
        for (auto c : s) h = h * base + (c - 'a');
        return h;
    }

    i64 ans[4];
    u64 v[maxn];

    inline void solve() {
        std::unordered_map<u64, int> cnt;
        rep (i, 1, n) {
            v[i] = get(s[i]);
            cnt[v[i]] ++;     
        }
        
        std::unordered_map<u64, int> cnt2;
        rep (i, 1, n) {
            std::string t = s[i];
            std::sort(t.begin(), t.end());
            cnt2[get(t)]++;
        }

        for (auto x : cnt2) ans[2] += (1ll * x.second * (x.second - 1) >> 1);
        for (auto x : cnt) ans[0] += (1ll * x.second * (x.second - 1) >> 1);

        rep (i, 1, n) {
            rep (l, 0, k - 1) {
                rep (r, l + 1, k - 1) {
                    std::string t = s[i];
                    std::sort(t.begin() + l, t.begin() + r + 1);
                    u64 h = get(t);
                    ans[1] += cnt[h];
                    if (h == v[i]) ans[1] --;
                }
            }
        }

        ans[1] >>= 1;
        ans[3] = (n * (n - 1) >> 1);
     
        ans[3] -= ans[2];
        ans[2] -= ans[1];
        ans[1] -= ans[0];
     
        i64 res = 0;
        res += ans[1] * 1;
        res += ans[2] * 2;
        res += ans[3] * 6666;

        std::cout << res << "\n";
    }
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> s[i];
    k = s[1].size();

    if (n * n * k < n * k * k) {
        Task1::solve();
    } else {
        Task2::solve();
    }
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("string3")

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
