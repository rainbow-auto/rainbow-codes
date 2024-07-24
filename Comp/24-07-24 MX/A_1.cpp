#include <iostream>
#include <vector>

struct Edge {
    int u, v;
    int w;
};

std::vector <Edge> es;

namespace Solution {
    
    inline bool check (int lim) {
        for (auto e : es) {
            if (e.w >= lim) { continue; }

            int u = find (e.u);
            int v = find (e.v);

            if (u == v) { continue; }
        }   
    }

    inline void solve () {

    }
}

int main () {
    
    return 0;
}