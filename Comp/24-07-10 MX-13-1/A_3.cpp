#include <iostream>
#include <set>
#include <cmath>

using f64 = double;
using i64 = long long;

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

namespace Task1 {
    inline void solve () {
        f64 ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                ans = max (ans, dis1 (ns[i], ns[j]) / dis2 (ns[i], ns[j]));
            }
        }

        printf ("%.12lf\n", ans);
    }
}

std::set <i64> cnt1;
std::set <i64> cnt2;

namespace Task2 {
    inline void solve () {
        f64 ans = sqrt (2.0);
        printf ("%.12lf\n", ans);
    }
}

int main () {

    freopen ("Apair.in", "r", stdin);
    freopen ("Apair.out", "w", stdout);

    int T; scanf ("%d", &T);

    while (T--) {
        cnt1.clear (); cnt2.clear ();
        bool Task2Flag = false;

        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) { 
            scanf ("%lf %lf", &ns[i].x, &ns[i].y); 
            if (Task2Flag) { continue; }

            if (cnt1.count (i64 (ns[i].x) - i64 (ns[i].y))) { Task2Flag = true; } 
            else { cnt1.insert(i64 (ns[i].x) - i64 (ns[i].y)); }
            if (cnt2.count (i64 (ns[i].x) + i64 (ns[i].y))) { Task2Flag = true; }
            else { cnt2.insert(i64 (ns[i].x) + i64 (ns[i].y)); }
        }

        if (Task2Flag) { Task2::solve (); }
        else { Task1::solve (); }
    }

    return 0;
}