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

std::vector <std::pair <int, int>> ops;
inline bool solve (i64 a, i64 b, i64 c, i64 d) {
    if (a * b % c != 0) { return false; }
    ops.push_back ({ 1, a });
    ops.push_back ({ 2, c });
    return true;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    int _; std::cin >> _;
    while (_--) {
        ops.clear ();

        i64 a, b, c, d; std::cin >> a >> b >> c >> d;
        // (a, b)
        // (1, ab)
        // (x, 1) x = ab / 2 + 1
        // (1, cd)
        // (c, ab / c) <=> (c, d)

        if (a * b < c * d) { std::cout << "-1\n"; continue; }

        i64 delta = a * b - c * d;
        if (delta) {
            std::cerr << "dt: " << delta << "\n";

            bool flag = false;
            if (not flag and delta % b == 0) { 
                i64 m = delta / b;
                std::cerr << "expect: " << a << " % k = " << m << "\n";
                if (m < a) {
                    i64 k = a - m;
                    if (a % k == m) {
                        flag = true;
                        std::cerr << "sol: " << k << "\n";
                        ops.push_back ({ 1, k });
                        a /= k; b *= k;
                    }
                }
            }
            if (not flag and delta % a == 0) { 
                i64 m = delta / a;
                std::cerr << "expect: " << b << " % k = " << m << "\n";
                if (m < b) {
                    i64 k = b - m;
                    if (b % k == m) {
                        flag = true;
                        ops.push_back ({ 2, k });
                        std::cerr << "sol: " << k << "\n";
                        a *= k; b /= k;
                    }
                }
            }

            if (not flag) { 
                std::cout << "-1\n"; continue; 
            }
        }

        if (not solve (a, b, c, d)) { std::cout << "-1\n"; continue; }
        
        std::cout << ops.size () << "\n";
        for (auto x : ops) { std::cout << x.first << " " << x.second << "\n"; }
    }

	return 0;
}
