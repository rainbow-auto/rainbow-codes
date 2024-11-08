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

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    std::string num; std::cin >> num;
    std::reverse (num.begin (), num.end ());
    n = num.size ();
    rep (i, 0, n - 1) { a[i] = num[i] - '0'; pos[a[i]].insert (i); }

    std::cin >> k;

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

        std::cerr << "i = " << i << "\n";

        // x.first * (10 ^ i - 10 ^ x.second) + (i - x.second) * k
        for (auto x : js) {
            std::cerr << x.second << " : ";
            std::cerr << (x.first * (ksm (10, i) - ksm (10, j)) - (i - x.second) * k) << "\n"; 
            
            if (curr <= x.first * (ksm (10, i) - ksm (10, j)) - (i - x.second) * k) {
                curr =  x.first * (ksm (10, i) - ksm (10, j)) - (i - x.second) * k;
                j = x.second;
                choose = true;
            } // curr 相同时, first 越大越好

        }

        std::cerr << "\n";
        if (not choose) { continue; }
        std::cerr << "choose " << j << "\n";
        std::cerr << "delta: " << curr << "\n";

        pos[a[i]].erase (i);
        pos[a[i]].insert (j);

        pos[a[j]].erase (j);   
        pos[a[j]].insert (i);

        std::swap (a[i], a[j]);

        per (id, n - 1, 0) { std::cerr << a[id]; } std::cerr << "\n";
    }

    per (i, n - 1, 0) { std::cout << a[i]; }

	return 0;
}
