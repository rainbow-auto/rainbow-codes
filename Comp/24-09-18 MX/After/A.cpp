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

i64 n, p, k, r;

std::vector<i64> operator * (const std::vector<i64>& a, const std::vector<i64>& b) {
    std::vector <i64> res (k);
    rep (i, 0, k - 1) {
        rep (j, 0, k - 1) {
            (res[(i + j) % k] += a[i] * b[j] % p) %= p;
        }
    }
    return res;
}

inline std::vector <i64> ksm (std::vector <i64> a, i64 b) {
    std::vector <i64> res (k);
    res[0] = 1;

    while (b) {
        if (b & 1) { res = res * a; }
        a = a * a; b >>= 1;
    }
    return res;
}

inline void solve () {
    std::cin >> n >> p >> k >> r;
    
    std::vector <i64> a(k);
    if (k == 1) {
        a[0] = 2 % p;
    } else {
        a[0] = a[1] = 1;
    }

    a = ksm (a, n * k);
    
    std::cout << a[r] << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    int _ = 1;
    while (_--) {
        solve ();
    }

	return 0;
}
