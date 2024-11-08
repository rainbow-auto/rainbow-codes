#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 300005;

int T;

int n, m;

struct Node {
    int u, v;
};

std::vector <Node> a;

namespace Subtask5 {
    bool vis[maxn];
    
    inline void solve () {
        memset (vis, 0, sizeof (vis));

        for (auto now : a) { vis[now.v] = true; }

        std::vector <Node> ans;

        int last = -1;
        for (int i = 2; i <= n; i++) {
            if (not vis[i]) { ans.push_back (Node { 1, i }); last = i; }
        }

        if (last == -1) { std::cout << "No\n"; return; }
            
        std::cout << "Yes\n";

        for (int i = 2; i <= n; i++) {
            if (vis[i]) { ans.push_back (Node { last, i }); }
        }

        for (auto now : ans) { std::cout << now.u << " " << now.v << "\n"; }
    }
}

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> m;

        bool Subtask5Flag = true;
        for (int i = 1; i <= m; i++) {
            int u, v; std::cin >> u >> v;
            a.push_back (Node { u, v });

            Subtask5Flag &= u == 1;
        }

        if (Subtask5Flag) { Subtask5::solve (); }
    }

    return 0;
}