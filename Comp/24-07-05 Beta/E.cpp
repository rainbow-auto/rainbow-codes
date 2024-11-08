#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include <cstdlib>

using i64 = long long;

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline i64 getNum (i64 l, i64 r) {
    return std::uniform_int_distribution <i64> (l, r) (rng);
}

const int maxn = 200005;

int n;

i64 a[maxn];
i64 limit[10], v[10];

inline void display_v () { for (int i = 1; i <= 5; i++) { std::cerr << v[i] << "\n"; } }

i64 get (i64 x) {
    if (x < limit[1]) { return v[1]; }
    if (limit[1] <= x and x < limit[2]) { return v[2]; }
    if (limit[2] <= x and x < limit[3]) { return v[3]; }
    if (limit[3] <= x and x <= limit[4]) { return v[4]; }
    if (limit[4] < x) { return v[5]; }
}

inline void clear () {
    for (int i = 1; i <= n; i++) { a[i] = 0; }
}

const double d = 0.97;
const double eps = 1e-19;

inline i64 calc (i64 h) {
    i64 res = 0;
    for (int i = 1; i <= n; i++) {
        res += get (a[i] + h);
    }
    return res;
}

i64 ans, last;
inline void SA () {
    double t = ;

    while (t > eps) {
        i64 h = getNum (-1e10, 1e10);
        i64 now = calc (h); 
        
        i64 delta = now - last;

        if (delta > 0) {
            ans = std::max (ans, now);
            last = now;     
        } else if (exp (delta / t) > (rand () / RAND_MAX)) {
            last = now;
        }

        t *= d;
    }
}

int main () {

    int T; std::cin >> T;

    double averageTime = 0.8 / T;

    while (T--) {
        std::cin >> n;
        clear ();

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        for (int i = 1; i <= 4; i++) { std::cin >> limit[i]; }
        for (int i = 1; i <= 5; i++) { std::cin >> v[i]; }

        ans = last = calc (0);

        int startTime = clock ();
        
        while (clock () - startTime < averageTime * CLOCKS_PER_SEC) { SA (); }

        std::cout << ans << "\n";
    }


    return 0;
}