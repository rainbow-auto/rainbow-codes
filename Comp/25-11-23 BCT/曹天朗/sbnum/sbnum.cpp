// 这下知道 T1 为啥叫 sbnum 了。

#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++) 
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--) 
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";

using i64 = long long;

constexpr int maxn = 100005;

std::string s;
i64 k;

namespace Sol {
    inline void solve() {
        int n = s.size();
        s = " " + s;
        std::array<int, 10> pos;
        pos.fill(-1);
        pos[s[1] - '0'] = 1;
        rep (i, 2, n) {
            int c = s[i] - '0';
            int t = pos[c] + 1;

            if (not ~pos[c]) {
                t = 1;
                rep (tt, 0, c) if (~pos[tt]) {
                    t = std::max(t, pos[tt] + 1);
                }
            }

            // i -> pos[s[i] - '0'] + 1
            if (k <= i - t) {
                // i -> i - k
                std::sort(s.begin() + 1, s.begin() + (i - 1) + 1);
                s.insert(s.begin() + i - k, s[i]);
                s.erase(s.begin() + i + 1);
                rep (j, 1, n) std::cout << s[j];
                std::cout << "\n";
                return;
            }
            k -= i - t;

            if (not ~pos[c]) {
                pos[c] = t;
                rep (j, c + 1, 9) {
                    if (~pos[j]) pos[j]++;
                }
            } else {
                rep (j, c, 9) {
                    if (~pos[j]) pos[j]++;
                }
            }
         
        }

        std::sort(s.begin() + 1, s.begin() + n + 1);
        rep (j, 1, n) std::cout << s[j]; std::cout << "\n";
    }
}

inline void solve() {
    std::cin >> s >> k;
    
    Sol::solve();

    // db << "--------------\n";
}

int main() {
    fastread

    file("sbnum")

    int _; std::cin >> _;
    while (_--) solve();

    return 0;
}