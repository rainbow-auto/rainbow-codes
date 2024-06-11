#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 5005;

int n, k;

int g[maxn][maxn];
bool vis[maxn];

bool flag;
void dfs (int now, int fa) {
    std::cerr << "now = " << now << "\n";
    
    vis[now] = true;
    for (int t = 1; t <= n; t++) {
        if (not g[now][t]) { continue; }
        if (t == fa) { continue; }

        if (vis[t]) { flag = false; return; }

        dfs (t, now);
    }
}

inline bool checkTree () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] > 1) { 
                // std::cout << "aaaa\n";
                return false; 
            }
        }
    }
    
    flag = true;
    memset (vis, 0, sizeof (vis));

    dfs (1, 0);

    for (int i = 1; i <= n; i++) {
        if (not vis[i]) { /* std::cout << "xxxx\n"; */ return false; }    
    }       
    return true;
}

inline bool get () {
    freopen ("C.out", "r", stdin);

    std::cin >> n;
    if (n == -1) { return true; }
    std::cin >> k;

    for (int t = 1; t <= k; t++) {
        // std::cout << "------------------\n";

        memset (g, 0, sizeof (g));

        for (int i = 1; i <= n - 1; i++) {
            int u, v; std::cin >> u >> v;
            g[u][v] ++;
            g[v][u] ++;
        }

        if (not checkTree ()) { return false; } 
    }

    return true;
}

int wa, ac;

inline bool pai () {
    system ("C_gen.exe > C.in");

    system ("C_1.exe < C.in > C.out");
    
    if (not get ()) { wa++; std::cout << "Wrong Answer !\n"; return false; }
    else { ac++; std::cout << "Accepted! \n"; return true; }
}

int main () {

    int tot = 0;

    for (int i = 1; i <= 200; i ++) {
        pai ();
    }

    std::cout << ac << " " << wa << " " << (double) (ac / 200.0) << "\n";

    return 0;
}