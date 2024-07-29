#include <iostream>
#include <string>
#include <set>
#include <map>

using i64 = long long;

const int maxn = 200005;

i64 k;
std::string op;

struct Node {
    i64 x, y;

    friend bool operator < (Node x, Node y) { 
        if (x.x != y.x) { return x.x < y.x; }
        else { return x.y < y.y; }
    }
};
std::set <Node> p;
i64 ex, ey;

inline void getPoints (i64 sx, i64 sy) {
    i64 nowx = sx; 
    i64 nowy = sy;
    p.insert (Node { nowx, nowy });

    for (auto c : op) {
        if (c == 'U') { nowy ++; }
        if (c == 'D') { nowy --; }
        if (c == 'L') { nowx --; }
        if (c == 'R') { nowx ++; }
        p.insert (Node { nowx, nowy });
        ex = nowx; ey = nowy;
    }
}

namespace Task0 { // O (|s|k)
    
    inline void solve () {
        k--;

        while (k--) { getPoints (ex, ey); }

        std::cout << p.size () << "\n";
    }
}

namespace Task1 { // O (|S| ^ 2)
    Node ps[maxn];
    int cnt;

    inline void solve () {
        for (auto node : p) { ps[++cnt] = node; }

        if (ex == 0 and ey == 0) { std::cout << cnt << "\n"; return; }

        if (ex == 0) { 
            return;
        } // ToDo

        if (ey == 0) { 
            return;
        } // ToDo

        i64 ans = 0;
        for (int i = 1; i <= cnt; i++) {
            bool flag = false;
            i64 min_dis = 1e15;

            for (int j = 1; j <= cnt; j++) {
                i64 disx = ps[j].x - ps[i].x;
                i64 disy = ps[j].y - ps[i].y;

                if (disx % ex == 0 and disy % ey == 0 and disx / ex == disy / ey and disx / ex > 0) {
                    flag = true;        
                    min_dis = std::min (min_dis, disx / ex);
                }
            }    

            if (not flag) { ans += k; }
            else { ans += min_dis; }
        }
        std::cout << ans << "\n";
    }
}

namespace Solution {
    std::map <Node, i64> L;
    std::map <Node, i64> R;
    std::set <Node> ps;

    inline void solve () {
        if (ex == 0 and ey == 0) { std::cout << p.size () << "\n"; return; }
        
        std::cerr << ex << " " << ey << "\n";

        ex = abs (ex);
        ey = abs (ey);

        bool flag = (ex != 0);

        for (auto nd : p) {
            auto now = Node { (ex ? ((nd.x % ex + ex) % ex) : nd.x), (ey ? ((nd.y % ey + ey) % ey) : nd.y) };

            ps.insert (now);

            if (not L.count (now)) { L[now] = (flag ? nd.x : nd.y); }
            else { L[now] = std::min (L[now], (flag ? nd.x : nd.y)); }

            if (not R.count (now)) { R[now] = (flag ? nd.x : nd.y); }
            else { R[now] = std::max (R[now], (flag ? nd.x : nd.y)); }
        }

        i64 ans = 0;
        for (auto it : ps) {
            if (flag) {
                ans += abs (R[it] - L[it]) / abs (ex);
            } else {
                ans += abs (R[it] - L[it]) / abs (ey);
            }
            ans += k;
        }

        std::cout << ans << "\n";
    }
}

int main () {

    // freopen ("loop.in", "r", stdin);
    // freopen ("loop.out", "w", stdout);

    std::cin >> op;
    std::cin >> k;

    getPoints (0, 0);

    Solution::solve ();

    // if (ex == 0 or ey == 0) { Task0::solve (); }
    // else { Task1::solve (); }

    return 0;
}