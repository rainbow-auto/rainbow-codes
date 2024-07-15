#include <iostream>
#include <algorithm>
#include <cmath>

using i64 = long long;
using f64 = double;

const int maxn = 100005;

int n;

struct Node {
    f64 x, y;
    int id;
} a[maxn];

inline f64 abs (f64 t) { return (t > 1e-18) ? t : -t; }

inline f64 dis1 (Node a, Node b) { return abs (a.x - b.x) + abs (a.y - b.y); }

inline f64 dis2 (Node a, Node b) { return sqrt ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

inline f64 val (Node a, Node b) { return dis1 (a, b) / dis2 (a, b); }

inline bool sort_x (Node a, Node b) {
    return (a.x + a.y) < (b.x + b.y);
}

inline bool sort_y (Node a, Node b) {
    return (a.x - a.y) < (b.x - b.y);
}

int main () {

    freopen ("Apair.in", "r", stdin);
    freopen ("Apair.out", "w", stdout);

    int T; scanf ("%d", &T);

    while (T--) {
        scanf ("%d", &n);

        for (int i = 1; i <= n; i++) {
            f64 x, y; scanf ("%lf %lf", &x, &y);
            a[i] = Node { x, y, i };
        }

        f64 ans = 0;

        std::sort (a + 1, a + n + 1, sort_x);
        for (int i = 2; i <= n; i++) {
            ans = std::max (ans, val (a[i - 1], a[i]));
        }   

        std::sort (a + 1, a + n + 1, sort_y);
        for (int i = 2; i <= n; i++) {
            ans = std::max (ans, val (a[i - 1], a[i]));
        }     

        printf ("%.12lf\n", ans);
    }


    return 0;
}