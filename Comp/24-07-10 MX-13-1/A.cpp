#include <iostream>
#include <cmath>

using i64 = long long;
using f64 = double;

const int maxn = 100005;

int n;

struct Point {
    f64 x, y;
} ns[maxn];

const f64 eps = 1e-18;

inline f64 abs (f64 x) { return x > eps ? x : -x; }
inline f64 max (f64 x, f64 y) { return x - y > eps ? x : y; }

inline f64 dis1 (Point a, Point b) {
    return abs (a.x - b.x) + abs (a.y - b.y);
}

inline f64 dis2 (Point a, Point b) {
    return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main () {

    freopen ("Apair.in", "r", stdin);
    freopen ("Apair.out", "w", stdout);

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) { std::cin >> ns[i].x >> ns[i].y; }        
        
        f64 ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                ans = max (ans, dis1 (ns[i], ns[j]) / dis2 (ns[i], ns[j]));
            }
        }

        printf ("%.12lf\n", ans);
    }   

    return 0;
}