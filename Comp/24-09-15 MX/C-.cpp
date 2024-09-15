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
std::string s[maxn];

namespace Task1 {
    inline void solve () {
        rep (i, 1, n) {
            rep (j, 1, n) {
                rep (k, 1, n) {
                    rep (l, 1, n) {
                        
                        rep (p, 1, s[i].size () - 1) {
                            rep (q, 1, s[j].size () - 1) {

                                std::string A = s[i].substr (0, p);
                                std::string B = s[i].substr (p);

                                std::string C = s[j].substr (0, q);
                                std::string D = s[j].substr (q);
                                
                                if (A == C) { continue; }
                                if (B == D) { continue; }

                                if (s[k] == C + B and s[l] == A + D) {
                                    std::cout << "Yes\n";
                                    std::cout << i << " " << j << " " << k << " " << l << " " << p + 1 << " " << q + 1 << "\n";
                                    return;
                                }                       
                            }
                        }
                    }
                }
            }
        }        

        std::cout << "NO\n";
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    freopen ("empty.in", "r", stdin);
    freopen ("empty.out", "w", stdout);

    int _; std::cin >> _;
    while (_--) {
        std::cin >> n;
        rep (i, 1, n) { std::cin >> s[i]; }

        Task1::solve ();   
    }

	return 0;
}
