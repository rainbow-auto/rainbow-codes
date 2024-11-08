#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 2005;

int n, k;

struct Node {
    i64 x, y;
} ns[maxn];

inline i64 abs (i64 t) { return (t > 0) ? t : -t; }

namespace Task1 {

    inline i64 get (i64 S, bool id) {
        std::vector <i64> ps;

        for (int i = 1; i <= n; i++) {
            if (S & (1 << (i - 1))) { ps.push_back (id ? ns[i].x : ns[i].y); }
        }

        std::sort (ps.begin (), ps.end ());
        
        i64 pos = 0;
        if (ps.size () & 1) {
            pos = ps[ps.size () >> 1];
        } else {
            i64 u = ps[ps.size () >> 1];
            i64 v = ps[(ps.size () >> 1) - 1];

            if (u == v) { pos = u; }
            else { pos = u + 1; }
        }

        i64 dis = 0;
        for (auto now : ps) { dis += abs (now - pos); }   
        return dis;
    }

    inline void solve () {
        i64 ans = 0x3f3f3f3f;
        
        for (i64 S = 0; S < (1 << n); S++) {
            i64 cnt = 0;
            for (i64 i = 1; i <= n; i++) {
                if (S & (1 << (i - 1))) { cnt ++; }
            }
            if (cnt < k) { continue; }

            ans = std::min (ans, get (S, 1) + get (S, 0));
        }

        std::cout << ans << "\n";
    }
}

namespace Task2 {
    
    inline i64 get (bool id) {
        std::vector <i64> ps;
        for (int i = 1; i <= n; i++) { ps.push_back (id ? ns[i].x : ns[i].y); }

        std::sort (ps.begin (), ps.end ());
        
        i64 pos = 0;
        if (ps.size () & 1) {
            pos = ps[ps.size () >> 1];
        } else {
            i64 u = ps[ps.size () >> 1];
            i64 v = ps[(ps.size () >> 1) - 1];

            if (u == v) { pos = u; }
            else { pos = u + 1; }
        }

        i64 dis = 0;
        for (auto now : ps) { dis += abs (now - pos); }   
        return dis;
    }
    
    inline void solve () {
        std::cout << get (0) + get (1) << "\n";
    }
}

int main () {

    freopen ("dating.in", "r", stdin);
    freopen ("dating.out", "w", stdout);

    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        std::cin >> ns[i].x >> ns[i].y;
    }

    if (n == k) { Task2::solve (); }
    else { Task1::solve (); }

    // Task1::solve ();

    return 0;
}