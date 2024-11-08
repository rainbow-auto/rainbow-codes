#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 205;

int n, m;

int dis[maxn][maxn];

inline void floyd () {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) { continue; }
                dis[i][j] = max (dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout << "after floyd" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j <= n; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}

inline int getLonggestPath () {
    floyd ();
    
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mx = max (mx, dis[i][j]);
        }
    }
    return mx;
}

int main () {

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = w;
        dis[v][u] = w;
    }

    cout << getLonggestPath () << endl;

    return 0;
}