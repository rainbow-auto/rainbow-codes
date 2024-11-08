#include <iostream>
#include <map>

using i64 = long long;

const int maxn = 2005;

int n;
i64 g[maxn][maxn];

i64 dis[maxn];
std::map <i64, int> cnt;

bool check () {
    for (int i = 1; i <= n; i++) { if (g[i][i] != 0) { return false; } }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j and g[i][j] == 0) { return false; }
            if (g[i][j] != g[j][i]) { return false; }
        }
    }

    for (int i = 1; i <= n; i++) { dis[i] = g[1][i]; }
    for (int i = 1; i <= n; i++) { cnt[dis[i]] ++; }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((dis[i] + dis[j] - g[i][j]) % 2 != 0) { return false; }
            if (not cnt.count ((dis[i] + dis[j] - g[i][j]) / 2ll)) { return false; }
        }
    }

    return true;
}

int main () {

    std::ios::sync_with_stdio (false);

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> g[i][j];
        }   
    }

    if (check ()) { std::cout << "YES\n"; }
    else { std::cout << "NO\n"; }

    return 0;
}