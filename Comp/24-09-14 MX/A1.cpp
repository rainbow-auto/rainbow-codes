#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 100005;

int n;
i64 k;

int a[maxn];

std::set <int> pos[10];

inline i64 ksm (i64 a, i64 b) {
    i64 res = 1;
    i64 base = a;
    while (b) {
        if (b & 1) { res *= base; }
        base *= base; b >>= 1;
    }
    return res;
}

namespace Task0 {
    inline int getlen (i64 x) {
        int cnt = 0;
        while (x) { cnt ++; x /= 10; }
        return cnt;
    }

    int p[maxn];
    inline void solve () {
        rep (i, 0, n - 1) { p[i] = i; }

        std::pair <i64, i64> ans = { -1e18, -1e18 };

        do {
            i64 x = 0;
            rep (i, 0, n - 1) { 
                rep (j, i + 1, n - 1) {
                    x += p[j] < p[i];
                }
            }

            i64 curr = 0;
            per (i, n - 1, 0) { curr = curr * 10 + a[p[i]]; }

            ans = std::max (ans, { curr - k * x, curr });
        } while (std::next_permutation (p, p + n));

        rep (i, 1, n - getlen (ans.second)) { std::cout << '0'; }
        std::cout << ans.second << "\n";
    }
}

namespace Task1 {
    std::set <int> pos[10];

    inline i64 ksm (i64 a, i64 b) {
        i64 res = 1;
        i64 base = a;
        while (b) {
            if (b & 1) { res *= base; }
            base *= base; b >>= 1;
        }
        return res;
    }

    inline void solve () {
        per (i, n - 1, 0) {
            std::vector < std::pair <i64, i64> > js;
            rep (t, a[i] + 1, 9) {
                if (pos[t].empty ()) { continue; }

                auto it = pos[t].lower_bound (i);
                if (it == pos[t].begin ()) { continue; }
                int j = *std::prev (it);
                js.push_back ({ t - a[i], j });
            }

            if (js.empty ()) { continue; }

            i64 curr = 0;
            i64 j = 0;
            bool choose = false;

            // x.first * (10 ^ i - 10 ^ x.second) + (i - x.second) * k
            for (auto x : js) {
                if (curr <= x.first * (ksm (10, i) - ksm (10, j)) - (i - x.second) * k) {
                    curr =  x.first * (ksm (10, i) - ksm (10, j)) - (i - x.second) * k;
                    j = x.second;
                    choose = true;
                } // curr 相同时, first 越大越好
            }

            if (not choose) { continue; }

            pos[a[i]].erase (i);
            pos[a[i]].insert (j);

            pos[a[j]].erase (j);   
            pos[a[j]].insert (i);

            std::swap (a[i], a[j]);
        }

        per (i, n - 1, 0) { std::cout << a[i]; }
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    freopen ("swap.in", "r", stdin);
    freopen ("swap.out", "w", stdout);

    std::string num; std::cin >> num;
    std::reverse (num.begin (), num.end ());
    n = num.size ();
    rep (i, 0, n - 1) { a[i] = num[i] - '0'; pos[a[i]].insert (i); }

    std::cin >> k;

    if (n <= 9) {
        Task0::solve ();
    } else {
        Task1::solve ();
    }

	return 0;
}
