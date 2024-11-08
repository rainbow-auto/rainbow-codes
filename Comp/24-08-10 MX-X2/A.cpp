#include <iostream>
#include <algorithm>
#include <vector>

using i64 = long long;

int T;
int n, m;

struct Node {
    i64 id;
    i64 val;
};

std::vector <Node> p;

bool chk () {
    if (m == 0 or m == 1) { return true; }
    std::sort (p.begin (), p.end (), [] (Node x, Node y) { return x.id < y.id; });

    Node last = Node { 0, 0 }; bool lastflag = false;
    i64 delta = 0; bool deltaflag = false;
    for (auto now : p) {
        if (not lastflag) { last = now; lastflag = true; continue; } 

        if ((now.val - last.val) % (now.id - last.id) != 0) { return false; }

        if (not deltaflag) { delta = (now.val - last.val) / (now.id - last.id); deltaflag = true; last = now; continue; }
        
        if (delta != (now.val - last.val) / (now.id - last.id)) { return false; }
        last = now;
    }

    return true;
}

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> m;

        for (int i = 1; i <= m; i++) {
            int pos; long double x; std::cin >> pos >> x;
            p.push_back (Node { pos, x });
        }
        if (chk ()) { std::cout << "Yes\n"; }
        else { std::cout << "No\n"; }

        p.clear ();
    }

    return 0;
}